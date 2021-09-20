#include <bits/stdc++.h>
using namespace std;
int H, D, F, day;
double U, decrease, pos;

int main() {
    while (cin >> H >> U >> D >> F) {
        if (!H) {
            break;
        }

        day = 0;
        pos = 0;
        decrease = U * F / 100.0;

        do {
            ++day;

            if (U > 0) {
                pos += U;
            }

            if (pos > H) {
                break;
            }

            pos -= D;
            U -= decrease;
        } while (pos >= 0);
        
        if (pos > H) {
            cout << "success on day " << day << '\n';
        } else {
            cout << "failure on day " << day << '\n';
        }
    }
}