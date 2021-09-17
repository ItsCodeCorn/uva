#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;

    while (cin >> n >> k) {
        cout << (int)(ceil(n / (double)(k - 1) * k - 1) + 0.5) << '\n';
    }
}