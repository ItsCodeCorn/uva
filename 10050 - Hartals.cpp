#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, N, P, h, count;
    vector<int> day;
    cin >> T;

    while (T--) {
        cin >> N >> P;
        count = 0;
        day.assign(N + 1, 0);

        for (int i = 0; i < P; ++i) {
            cin >> h;

            for (int j = h; j <= N; j += h) {
                if (j % 7 != 6 && j % 7 != 0) {
                    day[j] = 1;
                }
            }
        }

        for (int i = 0; i <= N; ++i) {
            if (day[i]) {
                ++count;
            }
        }

        cout << count << '\n';
    }
}