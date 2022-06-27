#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1040"

#include "../../graph/edge.cpp"
#include "../../graph/minimum_steiner_tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    while (true) {
        int H, W;
        cin >> H >> W;
        if (H == 0) break;
        vector<vector<Edge<int>>> G(H*W);
        vector<int> terminals;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                int s;
                cin >> s;
                if (s) terminals.push_back(i*W+j);
                if (i < H-1) {
                    G[i*W+j].push_back({(i+1)*W+j, 1});
                    G[(i+1)*W+j].push_back({i*W+j, 1});
                }
                if (j < W-1) {
                    G[i*W+j].push_back({i*W+j+1, 1});
                    G[i*W+j+1].push_back({i*W+j, 1});
                }
            }
        }
        cout << H*W - minimum_steiner_tree(G, terminals) - 1 << endl;
    }
}
