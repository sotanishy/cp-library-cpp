#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../data-structure/union_find.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        else cout << uf.same(u, v) << "\n";
    }
}