#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include "../../tree/link_cut_tree.cpp"

using namespace std;

struct AddMonoid {
    using T = long long;
    static constexpr T id = 0;
    static T op(T a, T b) {
        return a + b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    LinkCutTree<AddMonoid> lct;
    vector<decltype(lct)::node_ptr> nodes;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        nodes.emplace_back(lct.make_node(a));
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        lct.link(nodes[u], nodes[v]);
    }
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            lct.make_root(nodes[u]);
            lct.cut(nodes[v]);
            lct.link(nodes[w], nodes[x]);
        } else if (t == 1) {
            int p, x;
            cin >> p >> x;
            lct.update(nodes[p], lct.fold(nodes[p], nodes[p]) + x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << lct.fold(nodes[u], nodes[v]) << "\n";
        }
    }
}