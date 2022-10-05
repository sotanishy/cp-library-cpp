#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../graph/lowlink.cpp"
#include "../../graph/two_edge_connected_components.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Lowlink low(G);
    auto comp = two_edge_connected_components(G, low);
    vector<vector<int>> ans(*max_element(comp.begin(), comp.end()) + 1);
    for (int i = 0; i < N; ++i) ans[comp[i]].push_back(i);
    cout << ans.size() << "\n";
    for (auto& v : ans) {
        cout << v.size();
        for (int u : v) cout << " " << u;
        cout << "\n";
    }
}