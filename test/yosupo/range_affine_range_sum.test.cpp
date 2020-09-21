#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../data-structure/lazy_segment_tree.cpp"

using namespace std;

using ll = long long;

const ll mod = 998244353;

struct M {
    using T = pair<ll, int>;
    inline static const T id = {0, 0};
    static T op(T a, T b) {
        return {(a.first + b.first) % mod, a.second + b.second};
    }
};

struct O {
    using T = pair<ll, ll>;
    inline static const T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
    }
};

M::T act(M::T a, O::T b) {
    return {(a.first * b.first + a.second * b.second) % mod, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, int>> a(N, {0, 1});
    for (int i = 0; i < N; i++) cin >> a[i].first;
    LazySegmentTree<M, O, act> st(a);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.update(l, r, {b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.fold(l, r).first << "\n";
        }
    }
}