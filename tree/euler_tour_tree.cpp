#pragma once
#include <cassert>
#include <map>
#include <memory>
#include <utility>
#include <vector>

// TODO: implement subtree fold in O(log n) (is it even possible?)
// there are two approaches that may work
// 1: find the parent of the node, cut, fold, and link again
// 2: retain the first and the last occurrence of the vertex, split and fold

/*
 * @brief Euler Tour Tree
 */
template <typename M>
class EulerTourTree {
    using T = typename M::T;

public:
    EulerTourTree() = default;
    explicit EulerTourTree(int n) {
        for (int i = 0; i < n; ++i) {
            vertex.push_back(std::make_shared<Node>(i, i, M::id));
        }
    }

    void link(int u, int v) {
        reroot(u);
        reroot(v);
        auto uv = std::make_shared<Node>(u, v, M::id);
        auto vu = std::make_shared<Node>(v, u, M::id);
        splay(vertex[u]);
        splay(vertex[v]);
        join(join(vertex[u], uv), join(vertex[v], vu));
        edge[std::minmax(u, v)] = {uv, vu};
    }

    void cut(int u, int v) {
        auto p = edge[std::minmax(u, v)];
        node_ptr a, b, c, d;
        std::tie(a, b) = split(p.first);
        auto r = p.second;
        while (r->par) r = r->par;
        if (r == a) {
            std::tie(c, d) = split(p.second);
            join(c, b->right);
            while (d->left) d = d->left;
            if (d->par) d->par->left = nullptr;
            d->par = nullptr;
        } else {
            std::tie(c, d) = split(p.second);
            join(a, d->right);
            while (c->left) c = c->left;
            if (c->par) c->par->left = nullptr;
            c->par = nullptr;
        }
        edge.erase(std::minmax(u, v));
    }

    void reroot(int v) {
        node_ptr a, b;
        std::tie(a, b) = split(vertex[v]);
        join(b, a);
    }

    T get(int v) const {
        return vertex[v]->val;
    }

    void set(int v, const T& x) {
        splay(vertex[v]);
        vertex[v]->val = x;
        recalc(vertex[v]);
    }

    // T fold(int v) {
    //     int p = parent(v);
    //     if (p != -1) cut(p, v);
    //     splay(vertex[v]);
    //     auto ret = vertex[v]->sum;
    //     if (p != -1) link(p, v);
    //     return ret;
    // }

    // int parent(int v) {
    //     auto t = vertex[v];
    //     splay(t);
    //     if (!t->left) return -1;
    //     t = t->left;
    //     while (t->right) t = t->right;
    //     return t->from == v ? t->to : t->from;
    // }

    // void print(int v) {
    //     auto r = vertex[v];
    //     while (r->par) r = r->par;
    //     print(r);
    //     cout << endl;
    // }

    // void print2(int v) {
    //     auto r = vertex[v];
    //     while (r->par) r = r->par;
    //     print2(r, 0);
    //     cout << endl;
    // }

private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    // void print(node_ptr t) {
    //     if (!t) return;
    //     print(t->left);
    //     cout << "(" << t->from << " " << t->to << ") ";
    //     print(t->right);
    // }

    // void print2(node_ptr t, int depth) {
    //     if (!t) return;
    //     for (int i = 0; i < depth; ++i) cout << " ";
    //     cout << "(" << t->from << " " << t->to << ")" << t->sum << endl;
    //     print2(t->left, depth + 1);
    //     for (int i = 0; i < depth; ++i) cout << " ";
    //     cout << "(" << t->from << " " << t->to << ")" << endl;
    //     print2(t->right, depth + 1);
    //     for (int i = 0; i < depth; ++i) cout << " ";
    //     cout << "(" << t->from << " " << t->to << ")" << endl;
    // }

    struct Node {
        node_ptr left, right, par;
        T val, sum;
        int from, to, sz;
        Node(int from, int to, const T& x)
            : left(nullptr), right(nullptr), par(nullptr),
              val(x), sum(x), from(from), to(to), sz(from == to) {}
    };

    std::vector<node_ptr> vertex;
    std::map<std::pair<int, int>, std::pair<node_ptr, node_ptr>> edge;

    // splay tree

    static int size(const node_ptr& t) {
        return t ? t->sz : 0;
    }

    static void recalc(const node_ptr& t) {
        if (!t) return;
        t->sz = size(t->left) + 1 + size(t->right);
        t->sum = t->val;
        if (t->left) t->sum = M::op(t->left->sum, t->sum);
        if (t->right) t->sum = M::op(t->sum, t->right->sum);
    }

    static node_ptr join(node_ptr l, node_ptr r) {
        if (!l) return r;
        if (!r) return l;
        while (l->right) l = l->right;
        splay(l);
        l->right = r;
        r->par = l;
        recalc(l);
        return l;
    }

    static std::pair<node_ptr, node_ptr> split(node_ptr t) {
        splay(t);
        auto s = t->left;
        t->left = nullptr;
        if (s) s->par = nullptr;
        recalc(t);
        return {s, t};
    }

    static void rotate_left(node_ptr t) {
        node_ptr s = t->right;
        t->right = s->left;
        if (s->left) s->left->par = t;
        s->par = t->par;
        if (t->par) {
            if (t->par->left == t) {
                t->par->left = s;
            } else {
                t->par->right = s;
            }
        }
        s->left = t;
        t->par = s;
        recalc(t);
        recalc(s);
    }

    static void rotate_right(node_ptr t) {
        node_ptr s = t->left;
        t->left = s->right;
        if (s->right) s->right->par = t;
        s->par = t->par;
        if (t->par) {
            if (t->par->right == t) {
                t->par->right = s;
            } else {
                t->par->left = s;
            }
        }
        s->right = t;
        t->par = s;
        recalc(t);
        recalc(s);
    }

    static void splay(node_ptr t) {
        if (!t) return;
        while (t->par) {
            auto p = t->par, g = p->par;
            if (!g) {
                if (t == p->left) rotate_right(p);
                else rotate_left(p);
            } else {
                if (t == p->left) {
                    if (p == g->left) {
                        rotate_right(g);
                        rotate_right(p);
                    } else {
                        rotate_right(p);
                        rotate_left(g);
                    }
                } else {
                    if (p == g->left) {
                        rotate_left(p);
                        rotate_right(g);
                    } else {
                        rotate_left(g);
                        rotate_left(p);
                    }
                }
            }
        }
    }
};

// using ll = long long;

// struct AddMonoid {
//     using T = ll;
//     static constexpr T id = 0;
//     static T op(T a, T b) {
//         return a + b;
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, Q;
//     cin >> N >> Q;
//     EulerTourTree<AddMonoid> ett(N);
//     for (int i = 0; i < N; ++i) {
//         int a;
//         cin >> a;
//         ett.set(i, a);
//     }
//     for (int i = 0; i < N - 1; ++i) {
//         int u, v;
//         cin >> u >> v;
//         ett.link(u, v);
//     }
//     while (Q--) {
//         int t;
//         cin >> t;
//         if (t == 0) {
//             int u, v, w, x;
//             cin >> u >> v >> w >> x;
//             ett.cut(u, v);
//             ett.link(w, x);
//         } else if (t == 1) {
//             int p, x;
//             cin >> p >> x;
//             ett.set(p, ett.get(p) + x);
//         } else {
//             int v, p;
//             cin >> v >> p;
//             cout << ett.fold(v) << endl;
//         }
//     }
}