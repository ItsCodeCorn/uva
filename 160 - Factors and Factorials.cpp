#include <bits/stdc++.h>
using namespace std;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (!(n % i)) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, s;
    vector<int> factor;

    while (cin >> N) {
        if (!N) {
            break;
        }

        for (s = 0; s < 25; ++s) {
            if (prime[s] > N) {
                break;
            }
        }

        factor.assign(s, 0);

        for (int i = 2; i <= N; ++i) {
            int tmp = i;

            for (int j = 0; tmp != 1 && j < s; ++j) {
                while (!(tmp % prime[j])) {
                    tmp /= prime[j];
                    ++factor[j];
                }
            }
        }

        cout << setw(3) << N << "! =";

        for (int i = 0; i < s; ++i) {
            if (!((i + 1) % 16)) {
                cout << "\n      ";
            }

            cout << setw(3) << factor[i];
        }

        cout << '\n';
    }
}