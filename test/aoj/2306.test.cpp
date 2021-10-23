#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306"

#include "../../graph/enumerate_cliques.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n));
    vector<vector<bool>> edges(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int u, v, f;
        cin >> u >> v >> f;
        --u, --v;
        G[u][v] = G[v][u] = f;
        edges[u][v] = edges[v][u] = true;
    }
    int ans = 0;
    for (auto& clique : enumerate_cliques(edges)) {
        if (clique.size() == 1) continue;
        int s = 0;
        for (int i : clique) {
            int m = 1e9;
            for (int j : clique) {
                if (i != j) m = min(m, G[i][j]);
            }
            s += m;
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
}