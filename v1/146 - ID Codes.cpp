#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;

    while (cin >> str) {
        if (str == "#") {
            break;
        }

        bool flag = true;
        for (int i = 1; i < str.length(); ++i) {
            if (str[i] > str[i - 1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "No Successor" << '\n';
            continue;
        }

        next_permutation(begin(str), end(str));
        cout << str << '\n';
    }
}