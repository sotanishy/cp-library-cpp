#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include "../../tree/rerooting.cpp"

#include <bits/stdc++.h>
using namespace std;

struct MaxMonoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) {
        return max(a, b);
    }
};

int apply_edge(int x, int, int, int c) { return x + c; }
int apply_vertex(int x, int) { return x; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Rerooting<MaxMonoid, int, apply_edge, apply_vertex> G(n);
    for (int i = 0; i < n-1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G.add_edge(s, t, w);
    }
    auto ans = G.run();
    for (int i = 0; i < n; ++i) cout << ans[i] << "\n";
}
