#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include <bits/stdc++.h>

#include "../../math/modint.cpp"
#include "../../tree/rerooting.cpp"
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

struct AddCountMonoid {
    using T = pair<mint, int>;
    static T id() { return {0, 0}; }
    static T op(T a, T b) { return {a.first + b.first, a.second + b.second}; }
};

vector<mint> a;

pair<mint, int> apply_edge(pair<mint, int> x, int, int, pair<mint, mint> e) {
    return {e.first * x.first + e.second * x.second, x.second};
}
pair<mint, int> apply_vertex(pair<mint, int> x, int v) {
    return {x.first + a[v], x.second + 1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    a.resize(N);
    for (auto& x : a) cin >> x;
    Rerooting<AddCountMonoid, pair<mint, mint>, apply_edge, apply_vertex>
        rerooting(N);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        mint b, c;
        cin >> u >> v >> b >> c;
        rerooting.add_edge(u, v, {b, c});
    }
    auto ans = rerooting.run();
    for (int i = 0; i < N; ++i) {
        cout << ans[i].first << (i < N - 1 ? " " : "\n");
    }
}
