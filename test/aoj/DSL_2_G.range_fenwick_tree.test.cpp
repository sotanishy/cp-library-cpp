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
        int type, s, t;
        cin >> type >> s >> t;
        --s;
        --t;
        if (type == 0) {
            int x;
            cin >> x;
            ft.add(s, t + 1, x);
        } else {
            cout << ft.prefix_sum(t + 1) - ft.prefix_sum(s) << "\n";
        }
    }
}