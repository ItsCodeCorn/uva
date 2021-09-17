#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    while (cin >> n) {
        if (n < 0) {
            break;
        }

        cout << 1 + n * (n + 1) / 2 << '\n';
    }
}