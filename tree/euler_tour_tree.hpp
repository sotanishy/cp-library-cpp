#pragma once
#include <cassert>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename M, typename O,
          typename M::T (*act)(typename M::T, typename O::T)>
class EulerTourTree {
    using T = M::T;
    using E = O::T;

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
        auto [a, b, c] = split(get_node(u, v), get_node(v, u));
        join(a, c);
        ptr[u].erase(v);
        ptr[v].erase(u);
    }

    bool same(int u, int v) { return same(get_node(u, u), get_node(v, v)); }

    T get(int v) {
        auto t = get_node(v, v);
        splay(t);
        return t->val;
    }

    void update(int v, const T& x) {
        auto t = get_node(v, v);
        splay(t);
        t->val = x;
        recalc(t);
    }

    void update(int v, int p, const E& x) {
        cut(p, v);
        auto t = get_node(v, v);
        splay(t);
        t->lazy = O::op(t->lazy, x);
        link(p, v);
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
        T val = M::id(), sum = M::id();
        E lazy = O::id();
        Node(int from, int to) : from(from), to(to), sz(from == to) {}
    };

    std::vector<std::unordered_map<int, node_ptr>> ptr;

    node_ptr get_node(int u, int v) {
        if (ptr[u].find(v) == ptr[u].end())
            ptr[u][v] = std::make_shared<Node>(u, v);
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

    static int size(const node_ptr& t) { return t ? t->sz : 0; }

    static node_ptr recalc(const node_ptr& t) {
        if (!t) return t;
        t->sz = size(t->ch[0]) + (t->from == t->to) + size(t->ch[1]);
        t->sum = t->val;
        if (t->ch[0]) t->sum = M::op(t->ch[0]->sum, t->sum);
        if (t->ch[1]) t->sum = M::op(t->sum, t->ch[1]->sum);
        return t;
    }

    static void push(const node_ptr& t) {
        if (t->lazy != O::id()) {
            t->val = act(t->val, t->lazy);
            if (t->ch[0]) {
                t->ch[0]->lazy = O::op(t->ch[0]->lazy, t->lazy);
                t->ch[0]->sum = act(t->ch[0]->sum, t->lazy);
            }
            if (t->ch[1]) {
                t->ch[1]->lazy = O::op(t->ch[1]->lazy, t->lazy);
                t->ch[1]->sum = act(t->ch[1]->sum, t->lazy);
            }
            t->lazy = O::id();
        }
        recalc(t);
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

    static std::pair<node_ptr, node_ptr> split2(node_ptr t) {
        splay(t);
        auto l = t->ch[0];
        auto r = t->ch[1];
        t->ch[0] = nullptr;
        if (l) l->par = nullptr;
        t->ch[1] = nullptr;
        if (r) r->par = nullptr;
        return {l, r};
    }

    static std::tuple<node_ptr, node_ptr, node_ptr> split(node_ptr s,
                                                          node_ptr t) {
        auto [a, b] = split2(s);
        if (same(a, t)) {
            auto [c, d] = split2(t);
            return {c, d, b};
        } else {
            auto [c, d] = split2(t);
            return {a, c, d};
        }
    }

    static void rotate(node_ptr t, bool b) {
        node_ptr p = t->par, g = p->par;
        p->ch[1 - b] = t->ch[b];
        if (p->ch[1 - b]) t->ch[b]->par = p;
        t->ch[b] = p;
        p->par = t;
        recalc(p);
        recalc(t);
        t->par = g;
        if (t->par) {
            if (g->ch[0] == p)
                g->ch[0] = t;
            else
                g->ch[1] = t;
            recalc(g);
        }
    }

    static void splay(node_ptr t) {
        push(t);
        while (t->par) {
            auto p = t->par, g = p->par;
            if (!g) {
                push(p);
                push(t);
                rotate(t, p->ch[0] == t);
            } else {
                push(g);
                push(p);
                push(t);
                bool b = g->ch[0] == p;
                if (p->ch[1 - b] == t) {
                    rotate(p, b);
                    rotate(t, b);
                } else {
                    rotate(t, 1 - b);
                    rotate(t, b);
                }
            }
        }
    }
};