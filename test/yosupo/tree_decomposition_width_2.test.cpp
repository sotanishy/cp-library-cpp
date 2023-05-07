#define PROBLEM "https://judge.yosupo.jp/problem/tree_decomposition_width_2"

#include <bits/stdc++.h>

#include "../../graph/junction_tree.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string _s;
    cin >> _s >> _s;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    JunctionTreeWidth2 jt(G);
    if (!jt.is_treewidth_2()) {
        cout << -1 << "\n";
        return 0;
    }
    auto nodes = jt.get_nodes();
    int K = jt.size();
    cout << "s td " << K << " 2 " << N << "\n";
    for (int i = 0; i < K; ++i) {
        cout << "b " << i + 1;
        for (int v : nodes[i].bag) {
            cout << " " << v + 1;
        }
        cout << "\n";
    }
    for (int i = 0; i < K; ++i) {
        for (int c : nodes[i].ch) {
            cout << i + 1 << " " << c + 1 << "\n";
        }
    }
}
