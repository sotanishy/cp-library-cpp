#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../data-structure/lazy_segment_tree.cpp"

const int id = (1u << 31) - 1;

int op(int a, int b) { return min(a, b); }
int apply(int a, int b) { return b; }
int comp(int a, int b) { return b; }
int prod(int a, int b) { return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<int, op, id, int, apply, comp, prod, id> st(n);
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