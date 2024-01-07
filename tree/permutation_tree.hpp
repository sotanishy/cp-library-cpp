#pragma once
#include <algorithm>
#include <vector>

#include "../data-structure/segtree/lazy_segment_tree.hpp"

struct MinMonoid {
    using T = int;
    static T id() { return (1u << 31) - 1; }
    static T op(T a, T b) { return std::min(a, b); }
};

struct AddMonoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

int act(int a, int b) { return a + b; }

class PermutationTree {
   public:
    enum NodeType { JoinAsc, JoinDesc, Cut, Leaf, None };
    struct Node {
        NodeType tp;
        int l, r;    // i in [l, r)
        int lb, ub;  // p[i] in [lb, ub)
        std::vector<int> ch;
    };

    std::vector<Node> nodes;

    PermutationTree() = default;
    explicit PermutationTree(const std::vector<int>& p) {
        LazySegmentTree<MinMonoid, AddMonoid, act> seg(
            std::vector<int>(p.size()));
        // seg.fold(l, r) ==
        // min_{l <= j < r} { max(p[j:i]) - min(p[j:i]) - (i - j) }
        std::vector<int> st_max = {-1}, st_min = {-1}, st;

        for (int i = 0; i < (int)p.size(); ++i) {
            while (st_max.back() >= 0 && p[st_max.back()] < p[i]) {
                seg.update(st_max[st_max.size() - 2] + 1, st_max.back() + 1,
                           p[i] - p[st_max.back()]);
                st_max.pop_back();
            }
            st_max.push_back(i);

            while (st_min.back() >= 0 && p[st_min.back()] > p[i]) {
                seg.update(st_min[st_min.size() - 2] + 1, st_min.back() + 1,
                           -(p[i] - p[st_min.back()]));
                st_min.pop_back();
            }
            st_min.push_back(i);

            nodes.push_back(
                {Leaf, i, i + 1, p[i], p[i] + 1, std::vector<int>{}});
            int v = nodes.size() - 1;  // index of the current node

            while (true) {
                NodeType join_tp = None;
                if (!st.empty() && nodes[st.back()].ub == nodes[v].lb)
                    join_tp = JoinAsc;
                if (!st.empty() && nodes[st.back()].lb == nodes[v].ub)
                    join_tp = JoinDesc;

                if (!st.empty() && join_tp != None) {
                    // join
                    if (join_tp == nodes[st.back()].tp) {
                        // same type, append to the existing join node
                        add_child(st.back(), v);
                        v = st.back();
                        st.pop_back();
                    } else {
                        // different type, create a new join node
                        int u = st.back();
                        nodes.push_back({join_tp,
                                         nodes[u].l,
                                         nodes[u].r,
                                         nodes[u].lb,
                                         nodes[u].ub,
                                         {u}});
                        st.pop_back();
                        add_child(nodes.size() - 1, v);
                        v = nodes.size() - 1;
                    }
                } else if (seg.fold(0, i + 1 - (nodes[v].r - nodes[v].l)) ==
                           0) {
                    // cut
                    int l = nodes[v].l, r = nodes[v].r, lb = nodes[v].lb,
                        ub = nodes[v].ub;
                    nodes.push_back({Cut, l, r, lb, ub, {v}});
                    v = nodes.size() - 1;
                    do {
                        add_child(v, st.back());
                        st.pop_back();
                    } while (nodes[v].ub - nodes[v].lb !=
                             nodes[v].r - nodes[v].l);
                    std::ranges::reverse(nodes[v].ch);
                } else {
                    break;
                }
            }
            st.push_back(v);
            seg.update(0, i + 1, -1);
        }
    }

   private:
    void add_child(int par, int ch) {
        nodes[par].ch.push_back(ch);
        nodes[par].l = std::min(nodes[par].l, nodes[ch].l);
        nodes[par].r = std::max(nodes[par].r, nodes[ch].r);
        nodes[par].lb = std::min(nodes[par].lb, nodes[ch].lb);
        nodes[par].ub = std::max(nodes[par].ub, nodes[ch].ub);
    }
};