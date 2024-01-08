#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../../tree/lca.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    LCA lca(G, 0);
    for (int q = 0; q < Q; ++q) {
        int s, t, i;
        cin >> s >> t >> i;
        cout << lca.jump(s, t, i) << "\n";
    }
}
