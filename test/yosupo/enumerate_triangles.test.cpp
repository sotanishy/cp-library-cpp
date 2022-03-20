#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include "../../math/modint.cpp"
#include "../../graph/enumerate_triangles.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1) : 0; }
template <typename T> bool chmin(T& a, const T& b) { return a > b ? (a = b, 1) : 0; }

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<mint> x(N);
    for (auto& v : x) cin >> v;
    vector<vector<int>> G(N);
    rep(i,0,M) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    mint ans = 0;
    for (auto [a, b, c] : enumerate_triangles(G)) {
        ans += x[a]*x[b]*x[c];
    }
    cout << ans << endl;
}
