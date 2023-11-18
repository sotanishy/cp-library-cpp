#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../graph/shortest_path.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<vector<Edge<long long>>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    auto [dist, par] = shortest_path_tree(G, s);
    if (dist[t] >= 1e18) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        for (int v = t; v != s; v = par[v]) {
            path.push_back(v);
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        cout << dist[t] << " " << path.size() - 1 << endl;
        for (int i = 0; i < (int)path.size() - 1; ++i) {
            cout << path[i] << " " << path[i + 1] << "\n";
        }
    }
}
