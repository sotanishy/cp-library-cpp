#pragma once
#include "../data-structure/bst/reversible_splay_tree.cpp"

/*
 * @brief Link/Cut Tree
 * @docs docs/tree/link_cut_tree.md
 */
template <typename M, typename M::T (*flip)(typename M::T)>
class LinkCutTree : ReversibleSplayTree<M, flip> {
    using T = typename M::T;
    using RST = ReversibleSplayTree<M, flip>;

public:
    using node_ptr = typename RST::node_ptr;

    using RST::make_node;

    void link(node_ptr v, node_ptr p) const {
        evert(v);
        access(p);
        v->par = p;
        p->right = v;
        recalc(p);
    }

    void cut(node_ptr v) const {
        access(v);
        auto p = v->left;
        v->left = p->par = nullptr;
        recalc(v);
    }

    void evert(node_ptr v) const {
        access(v);
        reverse(v);
    }

    void update(node_ptr v, const T& x) const {
        access(v);
        v->val = x;
        recalc(v);
    }

    T fold(node_ptr u, node_ptr v) const {
        evert(u);
        access(v);
        return v->sum;
    }

private:
    using RST::reverse;
    using RST::recalc;
    using RST::splay;

    void access(node_ptr v) const {
        node_ptr prev = nullptr;
        for (auto cur = v; cur; cur = cur->par) {
            splay(cur);
            cur->right = prev;
            recalc(cur);
            prev = cur;
        }
        splay(v);
    }
};
