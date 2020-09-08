#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../data-structure/segment_tree.cpp"

int op(int a, int b) {
    return min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    SegmentTree<int, op, (1u << 31) - 1> st(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) st.update(x, y);
        else cout << st.query(x, y + 1) << "\n";
    }
}