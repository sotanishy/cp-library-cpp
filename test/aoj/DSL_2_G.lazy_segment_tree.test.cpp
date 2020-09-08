#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../data-structure/lazy_segment_tree.cpp"

using ll = long long;

struct S {
    struct V {
        using T = ll;
        inline static const T id = 0;
        static T op(T a, T b) {
            return a + b;
        }
    };

    struct O {
        using E = ll;
        inline static const E id = 0;
        static E op(E a, E b) {
            return a + b;
        }
    };

    static V::T op(V::T a, O::E b) {
        return a + b;
    }

    static O::E prod(O::E a, int b) {
        return a * b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<S> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s - 1, t, x);
        } else {
            cout << st.query(s - 1, t) << "\n";
        }
    }
}