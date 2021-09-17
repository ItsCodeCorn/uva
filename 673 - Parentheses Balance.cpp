#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dp;
    string str;
    int len;
    bool isBalance;

    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, str, '\n');

        len = str.length();
        isBalance = true;

        dp.assign(len, 0);

        for (int i = 0; i < len; ++i) {
            if (str[i] == '[' || str[i] == '(') {
                dp[i] = i;
            } else {
                if (i != 0 && dp[i - 1] != -1 && (str[i] == ']' && str[dp[i - 1]] == '[' || str[i] == ')' && str[dp[i - 1]] == '(')) {
                    if (dp[i - 1] - 1 == -1) {
                        dp[i] = -1;
                    } else {
                        dp[i] = dp[dp[i - 1] - 1];
                    }
                } else {
                    isBalance = false;
                    break;
                }
            }
        }

        if (len - 1 >= 0 && dp[len - 1] != -1) {
            isBalance = false;
        }

        if (isBalance) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}