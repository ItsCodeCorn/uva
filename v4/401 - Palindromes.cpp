#include <bits/stdc++.h>
using namespace std;
vector<char> mirror(128, 0);
string str;
bool isPal, isMir;

void init() {
    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';
}

int main() {
    init();

    while (cin >> str) {
        isPal = true;
        isMir = true;

        for (int i = 0; i <= str.length() / 2; ++i) {
            if (str[i] != str[str.length() - 1 - i]) {
                isPal = false;
            }

            if (!mirror[str[i]] || mirror[str[i]] != str[str.length() - 1 - i]) {
                isMir = false;
            }

            if (!isPal && !isMir) {
                break;
            }
        }

        cout << str << " -- ";

        if (!isPal && !isMir) {
            cout << "is not a palindrome." << '\n';
        } else if (isPal && !isMir) {
            cout << "is a regular palindrome." << '\n';
        } else if (!isPal && isMir) {
            cout << "is a mirrored string." << '\n';
        } else {
            cout << "is a mirrored palindrome." << '\n';
        }

        cout << '\n';
    }
}