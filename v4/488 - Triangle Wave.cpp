#include <bits/stdc++.h>
using namespace std;
int T, ampl, freq;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> ampl >> freq;

        while (freq--) {
            for (int i = 1; i <= ampl; ++i) {
                for (int j = 0; j < i; ++j) {
                    cout << i;
                }

                cout << '\n';
            }

            for (int i = ampl - 1; i > 0; --i) {
                for (int j = 0; j < i; ++j) {
                    cout << i;
                }

                cout << '\n';
            }

            if (!T && !freq) {
                break;
            }

            cout << '\n';
        }

    }
}