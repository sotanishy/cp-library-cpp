#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../data-structure/fenwick_tree.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    FenwickTree<int> ft(n+1);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) ft.add(x - 1, y);
        else cout << (ft.sum(y - 1) - ft.sum(x - 2)) << "\n";
    }
}