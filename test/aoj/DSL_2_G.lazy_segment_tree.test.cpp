#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../data-structure/lazy_segment_tree.cpp"

using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll apply(ll a, ll b) { return a + b; }
ll comp(ll a, ll b) { return a + b; }
ll prod(ll a, int b) { return a * b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<ll, op, 0, ll, apply, comp, prod, 0> st(n);
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