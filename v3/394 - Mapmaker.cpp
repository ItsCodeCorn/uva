#include <bits/stdc++.h>
using namespace std;
struct Address {
    int base;
    int bytes;
    vector<vector<int>> dim;
    vector<int> C;
    vector<int> index;
    void calculate() {
        int D = dim.size();

        C[D] = bytes;

        for (int i = D - 1; i > 0; --i) {
            C[i] = C[i + 1] * (dim[i][1] - dim[i][0] + 1);
        }

        C[0] = base;
        for (int i = 1; i <= D; ++i) {
            C[0] -= C[i] * dim[i - 1][0];
        }
    }
};
int N, R, D;
string str;
unordered_map<string, Address> address;

int main() {
    cin >> N >> R;

    while (N--) {
        cin >> str;
        Address addr = Address();
        cin >> addr.base >> addr.bytes;
        cin >> D;

        addr.dim.assign(D, vector<int>(2));
        addr.C.resize(D + 1, 0);
        addr.index.resize(D, 0);

        for (int i = 0; i < D; ++i) {
            cin >> addr.dim[i][0] >> addr.dim[i][1];
        }

        addr.calculate();

        address[str] = addr;
    }

    while (R--) {
        int res = 0;

        cin >> str;

        for (int i = 0; i < address[str].index.size(); ++i) {
            cin >> address[str].index[i];
        }

        res = address[str].C[0];

        for (int i = 1; i < address[str].C.size(); ++i) {
            res += address[str].C[i] * address[str].index[i - 1];
        }

        cout << str << '[' << address[str].index[0];
        for (int i = 1; i < address[str].index.size(); ++i) {
            cout << ", " << address[str].index[i];
        }
        cout << "] = " << res << '\n';
    }
    
}