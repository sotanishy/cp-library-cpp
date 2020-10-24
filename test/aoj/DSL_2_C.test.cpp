#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include "../../data-structure/kd_tree.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    KDTree<int> kd_tree;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        kd_tree.add_point(i, x, y);
    }
    kd_tree.build();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int sx, tx, sy, ty;
        cin >> sx >> tx >> sy >> ty;
        auto res = kd_tree.search(sx, tx, sy, ty);
        sort(res.begin(), res.end());
        for (int j : res) cout << j << "\n";
        cout << "\n";
    }
}