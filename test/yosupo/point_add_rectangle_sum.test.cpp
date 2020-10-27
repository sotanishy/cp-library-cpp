#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../data-structure/quadtree.cpp"
#include "../../misc/compress.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = ll;
    static constexpr T id = 0;
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
    vector<int> xs, ys;
    vector<int> x(N), y(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> w[i];
    }
    xs.insert(xs.end(), x.begin(), x.end());
    ys.insert(ys.end(), y.begin(), y.end());
    vector<Query> queries;
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y, w;
            cin >> x >> y >> w;
            queries.emplace_back(t, x, y, w);
            xs.push_back(x);
            ys.push_back(y);
        } else {
            int l, d, r, u;
            cin >> l >> d >> r >> u;
            queries.emplace_back(t, l, d, r, u);
            xs.push_back(l);
            ys.push_back(d);
            xs.push_back(r);
            ys.push_back(u);
        }
    }
    Compress<int> cx(xs), cy(ys);
    x = cx.compress(x);
    y = cy.compress(y);
    Quadtree<AddMonoid> qt(xs.size());
    for (int i = 0; i < N; ++i) {
        qt.update(x[i], y[i], qt.get(x[i], y[i]) + w[i]);
    }

    for (auto& q : queries) {
        if (q.t == 0) {
            int a = cx.compress(q.x), b = cy.compress(q.y);
            qt.update(a, b, qt.get(a, b) + q.w);
        } else {
            int l = cx.compress(q.l), r = cx.compress(q.r);
            int d = cy.compress(q.d), u = cy.compress(q.u);
            cout << qt.fold(l, r, d, u) << "\n";
        }
    }
}