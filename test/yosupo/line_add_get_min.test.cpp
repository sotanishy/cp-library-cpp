#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../../data-structure/cht/li_chao_tree.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Query {
    int t;
    ll a, b, p;
    Query(int t, ll a, ll b) : t(t), a(a), b(b) {}
    Query(int t, ll p) : t(t), p(p) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, ll>> ab(N);
    for (int i = 0; i < N; ++i) cin >> ab[i].first >> ab[i].second;
    vector<Query> query;
    vector<ll> xs;
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            ll a, b;
            cin >> a >> b;
            query.emplace_back(t, a, b);
        } else {
            ll p;
            cin >> p;
            query.emplace_back(t, p);
            xs.push_back(p);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    LiChaoTree<ll> lct(xs);
    for (auto& p : ab) {
        lct.add_line(p.first, p.second);
    }
    for (auto& q : query) {
        if (q.t == 0) {
            lct.add_line(q.a, q.b);
        } else {
            cout << lct.get(lower_bound(xs.begin(), xs.end(), q.p) - xs.begin()) << "\n";
        }
    }
}