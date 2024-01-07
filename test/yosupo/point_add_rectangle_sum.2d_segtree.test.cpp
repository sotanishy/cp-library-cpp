#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <bits/stdc++.h>

#include "../../data-structure/segtree/segment_tree_2d.hpp"
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = ll;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

struct Query {
    int t, x, y, w, l, d, r, u;
    Query(int t, int x, int y, int w) : t(t), x(x), y(y), w(w) {}
    Query(int t, int l, int d, int r, int u) : t(t), l(l), d(d), r(r), u(u) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> x(N), y(N), w(N);
    vector<pair<int, int>> pts;
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> w[i];
        pts.push_back({x[i], y[i]});
    }
    vector<Query> queries;
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y, w;
            cin >> x >> y >> w;
            queries.emplace_back(t, x, y, w);
            pts.push_back({x, y});
        } else {
            int l, d, r, u;
            cin >> l >> d >> r >> u;
            queries.emplace_back(t, l, d, r, u);
        }
    }
    SegmentTree2D<int, int, AddMonoid> st(pts);
    for (int i = 0; i < N; ++i) {
        st.update(x[i], y[i], st.get(x[i], y[i]) + w[i]);
    }

    for (auto& q : queries) {
        if (q.t == 0) {
            st.update(q.x, q.y, st.get(q.x, q.y) + q.w);
        } else {
            cout << st.fold(q.l, q.r, q.d, q.u) << "\n";
        }
    }
}