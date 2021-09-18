#include <bits/stdc++.h>
using namespace std;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> str) {
        reverse(begin(str), end(str));
        cout << str << (char)cin.get();
    }
}