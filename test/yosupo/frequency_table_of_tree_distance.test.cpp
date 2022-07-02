#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../tree/centroid_decomposition.hpp"
#include "../../convolution/fft.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1) : 0; }
template <typename T> bool chmin(T& a, const T& b) { return a > b ? (a = b, 1) : 0; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vector<vector<int>> G(N);
    rep(i,0,N-1) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> level, sz, par;
    tie(level, sz, par) = centroid_decomposition(G);

    vector<ll> ans(N);
    vector<double> cnt;

    auto dfs = [&](auto& dfs, int v, int p, int d, int l) -> void {
        if (cnt.size() <= d) cnt.push_back(0);
        ++cnt[d];
        for (int c : G[v]) {
            if (c != p && level[c] > l) {
                dfs(dfs, c, v, d+1, l);
            }
        }
    };

    auto calc = [&](int s) {
        vector<double> res(sz[s]);
        cnt.assign(1, 0);
        for (int c : G[s]) {
            if (level[c] > level[s]) {
                dfs(dfs, c, s, 1, level[s]);
            }
        }
        auto conv = convolution(cnt, cnt);
        rep(d,0,cnt.size()) {
            res[d] += cnt[d];
        }
        rep(d,0,min(conv.size(), res.size())) {
            res[d] += conv[d]/2;
        }
        for (int c : G[s]) {
            if (level[c] > level[s]) {
                cnt.assign(1, 0);
                dfs(dfs, c, s, 1, level[s]);
                auto conv = convolution(cnt, cnt);
                rep(d,0,min(conv.size(), res.size())) {
                    res[d] -= conv[d]/2;
                }
            }
        }
        rep(d,0,sz[s]) {
            ans[d] += (ll) round(res[d]);
        }
    };

    rep(i,0,N) calc(i);
    rep(d,1,N) cout << ans[d] << (d < N-1 ? " " : "\n");
}