#include <bits/stdc++.h>
using namespace std;
string str1, str2;

void sum(string &str1, string &str2) {
    int carry = 0, i = 0;

    for (; i < str1.length() && i < str2.length(); ++i) {
        if (str1[i] - '0' + str2[i] - '0' + carry >= 10) {
            str1[i] = str1[i] - '0' + str2[i] - '0' + carry - 10 + '0';
            carry = 1;
        } else {
            str1[i] = str1[i] - '0' + str2[i] - '0' + carry + '0';
            carry = 0;
        }
    }

    for (; i < str1.length(); ++i) {
        if (str1[i] - '0' + carry >= 10) {
            str1[i] = str1[i] + carry - 10;
            carry = 1;
        } else {
            str1[i] = str1[i] + carry;
            carry = 0;
        }
    }

    for (; i < str2.length(); ++i) {
        if (str2[i] - '0' + carry >= 10) {
            str1 += str2[i] + carry - 10;
            carry = 1;
        } else {
            str1 += str2[i] + carry;
            carry = 0;
        }
    }

    if (carry) {
        str1 += '1';
    }
}

int main() {
    cin >> str1;
    reverse(begin(str1), end(str1));

    while (cin >> str2) {
        if (str2 == "0") {
            break;
        }

        reverse(begin(str2), end(str2));

        sum(str1, str2);
    }

    reverse(begin(str1), end(str1));
    cout << str1 << '\n';
}