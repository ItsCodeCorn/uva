#include <bits/stdc++.h>
using namespace std;

int f(int N) {
    if (N > 100) {
        return N - 10;
    }

    return 91;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    while (cin >> n) {
        if (!n) {
            break;
        }

        cout << "f91(" << n << ") = " << f(n) << '\n';
    }
}