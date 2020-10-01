#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../data-structure/segment_tree.cpp"

using namespace std;
using ll = long long;

const ll mod = 998244353;

struct Monoid {
    using T = pair<ll, ll>;
    static inline T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, ll>> ab(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    SegmentTree<Monoid> st(ab);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            st.update(p, {c, d});
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            auto f = st.fold(l, r);
            cout << (f.first * x + f.second) % mod << "\n";
        }
    }
}