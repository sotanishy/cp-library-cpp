#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../data-structure/unionfind/persistent_union_find.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    PersistentUnionFind init(N);
    vector<PersistentUnionFind> ver(Q);
    for (int i = 0; i < Q; ++i) {
        int t, k, u, v;
        cin >> t >> k >> u >> v;
        if (t == 0) {
            if (k == -1) ver[i] = init.unite(u, v);
            else ver[i] = ver[k].unite(u, v);
        } else {
            int b;
            if (k == -1) b = init.same(u, v);
            else b = ver[k].same(u, v);
            cout << b << "\n";
        }
    }
}