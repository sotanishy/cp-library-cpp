#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../tree/lca.cpp"

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
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    LCA lca(G, 0);
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << "\n";
    }
}
