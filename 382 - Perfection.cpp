#include <bits/stdc++.h>
using namespace std;



int main() {
    cout << "PERFECTION OUTPUT" << '\n';

    int N, sq, sum;

    while (cin >> N) {
        if (!N) {
            break;
        }
        
        sum = -N;
        sq = sqrt(N);
        for (int i = 1; i <= sq; ++i) {
            if (!(N % i)) {
                sum += i + N / i;
            }
        }

        if (sq * sq == N) {
            sum -= sq;
        }

        cout << setw(5) << N << "  ";
        if (sum == N) {
            cout << "PERFECT" << '\n';
        } else if (sum < N) {
            cout << "DEFICIENT" << '\n';
        } else {
            cout << "ABUNDANT" << '\n';
        }
    }

    cout << "END OF OUTPUT" << '\n';
}