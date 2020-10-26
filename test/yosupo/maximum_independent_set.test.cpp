#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../../graph/maximum_independent_set.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto ans = maximum_independent_set(G);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
}
