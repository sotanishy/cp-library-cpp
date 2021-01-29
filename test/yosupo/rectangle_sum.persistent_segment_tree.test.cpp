#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../data-structure/segtree/persistent_segment_tree.cpp"
#include "../../misc/compress.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = ll;
    static constexpr T id = 0;
    static T op(T a, T b) { return a + b; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> xs, ys;
    vector<int> x(N), y(N), w(N);
    vector<int> l(Q), d(Q), r(Q), u(Q);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> w[i];
        xs.push_back(x[i]);
        ys.push_back(y[i]);
    }
    for (int i = 0; i < Q; ++i) {
        cin >> l[i] >> d[i] >> r[i] >> u[i];
        xs.push_back(l[i]);
        ys.push_back(d[i]);
        xs.push_back(r[i]);
        ys.push_back(u[i]);
    }
    xs.push_back(-1);
    ys.push_back(-1);
    Compress<int> cx(xs), cy(ys);
    x = cx.compress(x);
    y = cy.compress(y);
    l = cx.compress(l);
    d = cy.compress(d);
    r = cx.compress(r);
    u = cy.compress(u);
    int M = xs.size();
    vector<vector<pair<int, int>>> points(M);
    for (int i = 0; i < N; ++i) {
        points[x[i]].emplace_back(y[i], w[i]);
    }
    vector<PersistentSegmentTree<AddMonoid>> st(M);
    st[0] = PersistentSegmentTree<AddMonoid>(M);
    for (int x = 0; x < M; ++x) {
        if (x > 0) st[x] = st[x-1];
        auto tmp = st.back();
        for (auto& p : points[x]) {
            int y, w;
            tie(y, w) = p;
            st[x] = st[x].update(y, st[x][y] + w);
        }
    }
    for (int i = 0; i < Q; ++i) {
        ll ans = st[r[i] - 1].fold(d[i], u[i]) - st[l[i] - 1].fold(d[i], u[i]);
        cout << ans << "\n";
    }
}