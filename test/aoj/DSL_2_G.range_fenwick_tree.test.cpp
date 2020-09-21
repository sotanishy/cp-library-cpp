#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../data-structure/range_fenwick_tree.cpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    RangeFenwickTree<long long> ft(n+1);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            ft.add(s - 1, t - 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << ft.sum(t) - ft.sum(s - 1) << "\n";
        }
    }
}