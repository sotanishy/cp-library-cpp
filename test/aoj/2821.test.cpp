#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821"

#include "../../tree/tree_isomorphism.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T>
bool chmax(T& a, const T& b) {
    return a < b ? (a = b, 1) : 0;
}
template <typename T>
bool chmin(T& a, const T& b) {
    return a > b ? (a = b, 1) : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int N1, M1;
    cin >> N1 >> M1;
    vector<vector<int>> G1(N1);
    rep(i, 0, M1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    int N2;
    cin >> N2;
    vector<vector<int>> G2(N2);
    rep(i, 0, N2 - 1) {
        int w, x;
        cin >> w >> x;
        --w, --x;
        G2[w].push_back(x);
        G2[x].push_back(w);
    }

    TreeHasher hasher;
    ll h2 = hasher.hash_all(G2);

    vector<int> num(N1, -1);
    int ans = 0;
    rep(i, 0, N1) {
        if (num[i] != -1) continue;
        int k = 0;
        vector<vector<int>> G;
        auto dfs = [&](auto& dfs, int v, int p) -> void {
            num[v] = k++;
            G.emplace_back();
            if (p != -1) {
                G[num[p]].push_back(num[v]);
                G[num[v]].push_back(num[p]);
            }
            for (int c : G1[v]) {
                if (c != p) dfs(dfs, c, v);
            }
        };
        dfs(dfs, i, -1);

        if (G.size() == G2.size() && hasher.hash_all(G) == h2) {
            ++ans;
        }
    }
    cout << ans << endl;
}
