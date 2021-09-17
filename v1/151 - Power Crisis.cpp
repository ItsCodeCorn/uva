#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, count;
    bool flag, run;
    vector<bool> visited;
    
    while (cin >> N) {
        if (!N) {
            break;
        }

        flag = false;
        
        for (int i = 1, j;; ++i) {
            visited.assign(N + 1, false);
            j = 1;
            count = 0;
            run = true;

            while (run) {
                if (j == 13) {
                    if (count == N - 1) {
                        flag = true;
                    }

                    break;
                }
                visited[j] = true;
                ++count;

                for (int k = 0; k < i; ++k) {
                    ++j;
                    j = (j - 1) % N + 1;
                    int tmp = j;

                    while (visited[j]) {
                        ++j;
                        j = (j - 1) % N + 1;
                    }

                    if (!run) {
                        break;
                    }
                }
            }

            if (flag) {
                cout << i << '\n';
                break;
            }
        }
    }
}