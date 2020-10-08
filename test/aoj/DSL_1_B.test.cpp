#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include "../../data-structure/unionfind/weighted_union_find.cpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    WeightedUnionFind<int> wuf(n);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            wuf.unite(x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            if (wuf.same(x, y)) cout << wuf.diff(x, y) << "\n";
            else cout << "?\n";
        }
    }
}
