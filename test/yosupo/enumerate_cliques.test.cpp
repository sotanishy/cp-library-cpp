#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include "../../math/modint.hpp"
#include "../../graph/enumerate_cliques.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<mint> x(N);
    for (auto& y : x) cin >> y;
    vector<vector<bool>> G(N, vector<bool>(N));
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = true;
    }
    mint ans = 0;
    for (auto& clique : enumerate_cliques(G)) {
        mint res = 1;
        for (int i : clique) {
            res *= x[i];
        }
        ans += res;
    }
    cout << ans << endl;
}

