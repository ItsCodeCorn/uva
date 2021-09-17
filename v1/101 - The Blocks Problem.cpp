#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> blocks;

vector<int> find(int block) {
    for (int i = 0; i < blocks.size(); ++i) {
        for (int j = 0; j < blocks[i].size(); ++j) {
            if (blocks[i][j] == block) {
                return {i, j};
            }
        }
    }
}

int main() {
    int n;
    string cmd1, cmd2, cmd3, cmd4;

    cin >> n;
    blocks.resize(n);

    for (int i = 0; i < n; ++i) {
        blocks[i] = {i};
    }
    
    while (true) {
        vector<int> moving;
        cin >> cmd1;
        if (cmd1 == "quit") {
            break;
        }

        cin >> cmd2 >> cmd3 >> cmd4;
        vector<int> pos1 = find(stoi(cmd2));
        vector<int> pos2 = find(stoi(cmd4));

        if (pos1[0] == pos2[0]) {
            continue;
        }

        if (cmd1 == "move") {
            while (pos1[1] != blocks[pos1[0]].size() - 1) {
                blocks[blocks[pos1[0]].back()].push_back(blocks[pos1[0]].back());
                blocks[pos1[0]].pop_back();
            }

            moving.push_back(blocks[pos1[0]][pos1[1]]);
            blocks[pos1[0]].pop_back();
        } else {
            moving = vector<int>(begin(blocks[pos1[0]]) + pos1[1], end(blocks[pos1[0]]));
            
            while (blocks[pos1[0]].size() != pos1[1]) {
                blocks[pos1[0]].pop_back();
            }
        }
        
        if (cmd3 == "onto") {
            while (pos2[1] != blocks[pos2[0]].size() - 1) {
                blocks[blocks[pos2[0]].back()].push_back(blocks[pos2[0]].back());
                blocks[pos2[0]].pop_back();
            }

            for (auto &i : moving) {
                ++pos2[1];
                if (pos2[1] == blocks[pos2[0]].size()) {
                    blocks[pos2[0]].push_back(i);
                } else {
                    blocks[pos2[0]].insert(begin(blocks[pos2[0]]) + pos2[1], i);
                }
            }
        } else {
            for (auto &i : moving) {
                blocks[pos2[0]].push_back(i);
            }
        }
    }
    
    for (int i = 0; i < blocks.size(); ++i) {
        cout << i << ':';

        for (int j = 0; j < blocks[i].size(); ++j) {
            cout << ' ' << blocks[i][j];
        }

        cout << '\n';
    }

}