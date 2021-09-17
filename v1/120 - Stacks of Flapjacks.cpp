#include <bits/stdc++.h>
using namespace std;
vector<int> st, res;
int tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin) {
        st.clear();

        while (cin >> tmp) {
            st.push_back(tmp);

            if (cin && cin.get() == '\n') {
                break;
            }
        }

        cout << st[0];
        for (int i = 1; i < st.size(); ++i) {
            cout << ' ' << st[i];
        }
        cout << '\n';

        res = st;
        sort(begin(res), end(res));

        for (int i = st.size() - 1; i >= 0; --i) {
            if (st[i] == res[i]) {
                continue;
            }

            if (st[0] != res[i]) {
                for (int j = 0; j < i; ++j) {
                    if (st[j] == res[i]) {
                        cout << st.size() - j << ' ';
                        reverse(begin(st), begin(st) + j + 1);
                        break;
                    }
                }
            }

            cout << st.size() - i << ' ';
            reverse(begin(st), begin(st) + i + 1);
        }

        cout << 0 << '\n';
    }
}