#define PROBLEM "https://judge.yosupo.jp/problem/bipartite_edge_coloring"

#include "../../graph/bipartite_edge_coloring.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int L, R, M;
    cin >> L >> R >> M;
    vector<pair<int, int>> edges(M);
    map<pair<int, int>, int> idx;
    for (int i = 0; i < M; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        idx[p] = i;
        edges[i] = p;
    }
    auto ans = bipartite_edge_coloring(edges, L, R);
    cout << *max_element(ans.begin(), ans.end())+1 << "\n";
    for (int i = 0; i < M; ++i) cout << ans[i] << "\n";
}