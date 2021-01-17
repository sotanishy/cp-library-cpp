#pragma once
#include <cassert>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename M>
class EulerTourTree {
    using T = typename M::T;

public:
    EulerTourTree() = default;
    explicit EulerTourTree(int n) {
        ptr.resize(n);
        for (int i = 0; i < n; ++i) {
            ptr[i][i] = std::make_shared<Node>(i, i);
        }
    }

    void link(int u, int v) {
        assert(!same(u, v));
        auto tu = reroot(get_node(u, u));
        auto tv = reroot(get_node(v, v));
        join(join(tu, get_node(u, v)), join(tv, get_node(v, u)));
    }

    void cut(int u, int v) {
        assert(ptr[u].find(v) != ptr[u].end());
        node_ptr a, b, c;
        std::tie(a, b, c) = split(get_node(u, v), get_node(v, u));
        join(a, c);
        ptr[u].erase(v);
        ptr[v].erase(u);
    }

    bool same(int u, int v) {
        return same(get_node(u, u), get_node(v, v));
    }

    T get(int v) {
        return get_node(v, v)->val;
    }

    void update(int v, const T& x) {
        auto t = get_node(v, v);
        splay(t);
        t->val = x;
        recalc(t);
    }

    T fold(int v, int p = -1) {
        if (p != -1) cut(p, v);
        auto t = get_node(v, v);
        splay(t);
        T ret = t->sum;
        if (p != -1) link(p, v);
        return ret;
    }

private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        node_ptr ch[2] = {nullptr, nullptr};
        node_ptr par = nullptr;
        int from, to, sz;
        T val = M::id, sum = M::id;
        Node(int from, int to) : from(from), to(to), sz(from == to) {}
    };

    std::vector<std::unordered_map<int, node_ptr>> ptr;

    node_ptr get_node(int u, int v) {
        if (ptr[u].find(v) == ptr[u].end()) ptr[u][v] = std::make_shared<Node>(u, v);
        return ptr[u][v];
    }

    static node_ptr root(node_ptr t) {
        if (!t) return nullptr;
        while (t->par) t = t->par;
        return t;
    }

    static bool same(node_ptr s, node_ptr t) {
        if (s) splay(s);
        if (t) splay(t);
        return root(s) == root(t);
    }

    static node_ptr reroot(node_ptr t) {
        auto s = split(t);
        return join(s.second, s.first);
    }

    // splay tree

    static int size(const node_ptr& t) {
        return t ? t->sz : 0;
    }

    static node_ptr recalc(const node_ptr& t) {
        if (!t) return t;
        t->sz = size(t->ch[0]) + (t->from == t->to) + size(t->ch[1]);
        t->sum = t->val;
        if (t->ch[0]) t->sum = M::op(t->ch[0]->sum, t->sum);
        if (t->ch[1]) t->sum = M::op(t->sum, t->ch[1]->sum);
        return t;
    }

    static node_ptr join(node_ptr l, node_ptr r) {
        if (!l) return r;
        if (!r) return l;
        while (l->ch[1]) l = l->ch[1];
        splay(l);
        l->ch[1] = r;
        r->par = l;
        return recalc(l);
    }

    static std::pair<node_ptr, node_ptr> split(node_ptr t) {
        splay(t);
        auto s = t->ch[0];
        t->ch[0] = nullptr;
        if (s) s->par = nullptr;
        return {s, recalc(t)};
    }

    static std::pair<node_ptr,node_ptr> split2(node_ptr t) {
        splay(t);
        auto l = t->ch[0];
        auto r = t->ch[1];
        t->ch[0] = nullptr;
        if (l) l->par = nullptr;
        t->ch[1] = nullptr;
        if (r) r->par = nullptr;
        return {l, r};
    }

    static std::tuple<node_ptr, node_ptr, node_ptr> split(node_ptr s, node_ptr t) {
        node_ptr a, b, c, d;
        std::tie(a, b) = split2(s);
        if (same(a, t)) {
            std::tie(c, d) = split2(t);
            return {c, d, b};
        } else {
            std::tie(c, d) = split2(t);
            return {a, c, d};
        }
    }

    static void rotate(node_ptr t, bool b) {
        node_ptr s = t->ch[1 - b], p = t->par;
        t->ch[1 - b] = s->ch[b];
        if (t->ch[1 - b]) t->ch[1 - b]->par = t;
        s->ch[b] = t;
        t->par = s;
        recalc(t);
        recalc(s);
        s->par = p;
        if (p) {
            if (p->ch[0] == t) p->ch[0] = s;
            else p->ch[1] = s;
        }
    }

    static void splay(node_ptr t) {
        if (!t) return;
        while (t->par) {
            auto p = t->par, g = p->par;
            if (!g) {
                rotate(p, t == p->ch[0]);
            } else {
                if (t == p->ch[0]) {
                    if (p == g->ch[0]) {
                        rotate(g, 1);
                        rotate(p, 1);
                    } else {
                        rotate(p, 1);
                        rotate(g, 0);
                    }
                } else {
                    if (p == g->ch[0]) {
                        rotate(p, 0);
                        rotate(g, 1);
                    } else {
                        rotate(g, 0);
                        rotate(p, 0);
                    }
                }
            }
        }
    }
};

/*
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

    T fold(int v, int p) {
        if (p == -1) {
            splay(vertex[v]);
            return vertex[v]->sum;
        }
        auto e = edge[std::minmax(v, p)];
        node_ptr a, b, c, d;
        std::tie(a, b) = split(e.first);
        auto r = e.second;
        while (r->par) r = r->par;
        T ret;
        if (r == a) {
            std::tie(c, d) = split(e.second);
            ret = d->sum;
            join(join(c, d), b);
        } else {
            std::tie(c, d) = split(e.second);
            ret = c->sum;
            join(a, join(c, d));
        }
        return ret;
    }

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
*/