#include <bits/stdc++.h>
using namespace std;
int N, K, M, cents;
vector<int> value;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    while (N--) {
        cin >> K;

        value.assign(128, 0);

        for (int i = 0; i < K; ++i) {
            char c;
            int v;

            cin >> c >> v;
            value[c] = v;
        }

        cin >> M;
        cin.ignore();

        cents = 0;
        char tmp;

        while (M) {
            tmp = cin.get();

            if (tmp == '\n') {
                --M;
                continue;
            }

            cents += value[tmp];
        }

        cout << cents / 100 << '.';

        if (cents % 100 > 9) {
            cout << cents % 100;
        } else {
            cout << '0' << cents % 10;
        }

        cout << '$' << '\n';
    }
}