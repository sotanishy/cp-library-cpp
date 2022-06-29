#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../flow/hopcroft_karp.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int L, R, M;
    cin >> L >> R >> M;
    HopcroftKarp hk(L, R);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        hk.add_edge(a, b);
    }
    auto ans = hk.bipartite_matching();
    cout << ans.size() << "\n";
    for (auto [c, d] : ans) cout << c << " " << d << "\n";
}