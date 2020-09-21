#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../../data-structure/dual_segment_tree.cpp"

using namespace std;

struct Monoid {
    using T = int;
    inline static const T id = 0;
    static T op(T a, T b) {
        return a + b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DualSegmentTree<Monoid> st(n);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            st.update(s - 1, t, x);
        } else {
            int i;
            cin >> i;
            cout << st[i - 1] << "\n";
        }
    }
}