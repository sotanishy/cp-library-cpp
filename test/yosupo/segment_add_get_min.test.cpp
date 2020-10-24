#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../../data-structure/li_chao_tree.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment {
    ll l, r, a, b;
    Segment() = default;
    Segment(ll l, ll r, ll a, ll b) : l(l), r(r), a(a), b(b) {}
};

struct Query {
    int t;
    Segment seg;
    ll p;
    Query(int t, ll l, ll r, ll a, ll b) : t(t), seg(l, r, a, b) {}
    Query(int t, ll p) : t(t), p(p) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> xs;
    vector<Segment> seg(N);
    for (int i = 0; i < N; ++i) {
        cin >> seg[i].l >> seg[i].r >> seg[i].a >> seg[i].b;
        xs.push_back(seg[i].l);
        xs.push_back(seg[i].r);
    }
    vector<Query> query;
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            query.emplace_back(t, l, r, a, b);
        } else {
            ll p;
            cin >> p;
            query.emplace_back(t, p);
            xs.push_back(p);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    auto compress = [&](int x) {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    };
    LiChaoTree<ll> lct(xs);
    for (auto& s : seg) {
        lct.add_segment(s.a, s.b, compress(s.l), compress(s.r));
    }
    for (auto& q : query) {
        if (q.t == 0) {
            lct.add_segment(q.seg.a, q.seg.b, compress(q.seg.l), compress(q.seg.r));
        } else {
            ll ans = lct.get_min(compress(q.p));
            if (ans > 5e18) cout << "INFINITY\n";
            else cout << ans << "\n";
        }
    }
}