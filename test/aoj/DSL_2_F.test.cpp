#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../data-structure/lazy_segment_tree.cpp"

 struct S {
    struct V {
        using T = int;
        inline static const T id = (1u << 31) - 1;
        static T op(T a, T b) {
            return min(a, b);
        }
    };

    struct O {
        using E = int;
        inline static const E id = (1u << 31) - 1;
        static E op(E a, E b) {
            return b;
        }
    };

    static V::T op(V::T a, O::E b) {
        return b;
    }

    static O::E prod(O::E a, int b) {
        return a;
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
            st.update(s, t + 1, x);
        } else {
            cout << st.query(s, t + 1) << "\n";
        }
    }
}