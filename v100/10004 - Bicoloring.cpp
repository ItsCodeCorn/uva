#include <bits/stdc++.h>
using namespace std;
bool isBicoloring;
vector<vector<bool>> graph;
vector<vector<bool>> visited;
vector<int> color;
int n, e;

void coloring(int i, int lastColor) {
    if (!isBicoloring) {
        return;
    }

    if (color[i] == 0) {
        color[i] = lastColor + 1 > 2 ? 1 : 2;
    } else {
        if (lastColor == color[i]) {
            isBicoloring = false;
            return;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (graph[i][j] && !visited[i][j]) {
            visited[i][j] = true;
            coloring(j, color[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        if (!n) {
            break;
        }
        
        isBicoloring = true;
        graph.assign(n, vector<bool>(n, false));
        visited.assign(n, vector<bool>(n, false));
        color.assign(n, 0);
        cin >> e;
        
        for (int i = 0, from, to; i < e; ++i) {
            cin >> from >> to;

            graph[from][to] = true;
            graph[to][from] = true;
        }

        coloring(0, 1);

        if (isBicoloring) {
            cout << "BICOLORABLE." << '\n';
        } else {
            cout << "NOT BICOLORABLE." << '\n';
        }
    }
}