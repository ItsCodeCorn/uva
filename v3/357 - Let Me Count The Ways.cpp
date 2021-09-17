#include <bits/stdc++.h>
using namespace std;
int moneys[] = {1, 5, 10, 25, 50};
int n;
vector<long long> dp;

int main() {
    while (cin >> n) {
        dp.assign(n + 1, 0);
        dp[0] = 1;

        for (int money = 0; money < 5; ++money) {
            for (int i = moneys[money]; i <= n; ++i) {
                dp[i] += dp[i - moneys[money]];
            }
        }

        if (dp[n] == 1) {
            cout << "There is only " << dp[n] << " way to produce " << n << " cents change." << '\n';
        } else {
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << '\n';
        }
    }
}