#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../data-structure/lazy_segment_tree.cpp"

using ll = long long;

const ll mod = 998244353;

struct S {
    struct V {
        using T = ll;
        inline static const T id = 0;
        static T op(T a, T b) {
            return (a + b) % mod;
        }
    };

    struct O {
        using E = pair<ll, ll>;
        inline static const E id = {1, 0};
        static E op(E a, E b) {
            return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
        }
    };

    static V::T op(V::T a, O::E b) {
        return (a * b.first + b.second) % mod;
    }

    static O::E mul(O::E a, size_t b) {
        return {a.first, a.second * b % mod};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    LazySegmentTree<S> st(a);
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
            cout << st.fold(l, r) << "\n";
        }
    }
}