#include <bits/stdc++.h>
using namespace std;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int N, M, res;
vector<int> factor;

void calculate(int n, int adder) {
    for (int i = 2; i <= n; ++i) {
        int tmp = i;

        for (int j = 0; tmp != 1 && j < 25; ++j) {
            while (!(tmp % prime[j])) {
                tmp /= prime[j];
                factor[j] += adder;
            }
        }
    }
}

int main() {
    while (cin >> N >> M) {
        if (!N && !M) {
            break;
        }
        
        res = 1;
        factor.assign(25, 0);

        calculate(N, 1);
        calculate(M, -1);
        calculate(N - M, -1);

        for (int i = 0; i < 25; ++i) {
            for (int j = 0; j < factor[i]; ++j) {
                res *= prime[i];
            }
        }

        cout << N << " things taken " << M << " at a time is " << res << " exactly." << '\n';
    }
}