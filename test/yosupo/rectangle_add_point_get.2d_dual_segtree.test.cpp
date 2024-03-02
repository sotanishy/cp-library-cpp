#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"

#include <bits/stdc++.h>

#include "../../data-structure/segtree/dual_segment_tree_2d.hpp"
using namespace std;
using ll = long long;


struct AddMonoid {
    using T = ll;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

struct Query {
    int t, x, y, l, d, r, u, w;
    Query(int t, int l, int d, int r, int u, int w)
        : t(t), l(l), d(d), r(r), u(u), w(w) {}
    Query(int t, int x, int y) : t(t), x(x), y(y) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> l(N), d(N), r(N), u(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> l[i] >> d[i] >> r[i] >> u[i] >> w[i];
    }
    vector<pair<int, int>> pts;
    vector<Query> queries;
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, d, r, u, w;
            cin >> l >> d >> r >> u >> w;
            queries.emplace_back(t, l, d, r, u, w);
        } else {
            int x, y;
            cin >> x >> y;
            pts.push_back({x, y});
            queries.emplace_back(t, x, y);
        }
    }
    DualSegmentTree2D<int, int, AddMonoid> st(pts);
    for (int i = 0; i < N; ++i) {
        st.update(l[i], r[i], d[i], u[i], w[i]);
    }

    for (auto& q : queries) {
        if (q.t == 0) {
            st.update(q.l, q.r, q.d, q.u, q.w);
        } else {
            cout << st.get(q.x, q.y) << "\n";
        }
    }
}