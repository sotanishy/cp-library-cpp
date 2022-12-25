import os

paths = {
    "convolution": [
        "../convolution/xor_convolution.hpp",
        "../convolution/and_or_convolution.hpp",
        "../convolution/gcd_lcm_convolution.hpp",
        "../convolution/fft.hpp",
    ],
    "data-structure": [
        "../data-structure/segtree/segment_tree.cpp",
        "../data-structure/segtree/lazy_segment_tree.cpp",
        "../data-structure/fenwick_tree.cpp",
        "../data-structure/range_tree.cpp",
        "../data-structure/unionfind/union_find.cpp",
        "../data-structure/unionfind/weighted_union_find.cpp",
        "../data-structure/cht/convex_hull_trick.cpp",
        # "../data-structure/bst/treap.cpp",
        # "../data-structure/kd_tree.cpp",
        # "../data-structure/bit_vector.cpp",
        # "../data-structure/wavelet_matrix.cpp",
        # "../data-structure/binary_trie.cpp",
        # "../data-structure/disjoint_sparse_table.cpp",
        # "../data-structure/kd_tree.cpp",

        # "../data-structure/persistent_array.cpp",
        # "../data-structure/sparse_table.cpp",
        # "../data-structure/slope_trick.cpp",
        # "../data-structure/persistent_stack.cpp",
        # "../data-structure/persistent_queue.cpp",
        # "../data-structure/segtree/segment_tree_2d.hpp",
        # "../data-structure/segtree/segment_tree_beats.cpp",
        # "../data-structure/segtree/persistent_segment_tree.cpp",
        # "../data-structure/segtree/dual_segment_tree.cpp",
        # "../data-structure/unionfind/undoable_union_find.cpp",
        # "../data-structure/unionfind/partially_persistent_union_find.cpp",
        # "../data-structure/bst/rbst.cpp",
        # "../data-structure/bst/lazy_treap.cpp",
        # "../data-structure/bst/red_black_tree.cpp",
        # "../data-structure/bst/splay_tree.cpp",
        # "../data-structure/cht/convex_hull_trick_binsearchtree.hpp",
        # "../data-structure/cht/li_chao_tree.cpp",
    ],
    "flow": [
        "../flow/ford_fulkerson.cpp",
        "../flow/dinic.cpp",
        "../flow/min_cost_flow.cpp",
    ],
    "geometry": [
        "../geometry/geometry.hpp",
        "../geometry/intersection.hpp",
        "../geometry/dist.hpp",
        "../geometry/intersect.hpp",
        "../geometry/tangent.hpp",
        "../geometry/polygon.hpp",
        "../geometry/triangle.hpp",
        "../geometry/convex_hull.hpp",
        "../geometry/bisector.hpp",
        "../geometry/geometry3d.hpp",
    ],
    "graph": [
        "../graph/scc.cpp",
        "../graph/lowlink.cpp",

        # "../graph/topological_sort.cpp",
        # "../graph/mst.cpp",
        # "../graph/range_edge_graph.cpp",
        # "../graph/enumerate_cliques.cpp",
        # "../graph/chromatic_number.cpp",
        # "../graph/enumerate_triangles.cpp",
        # "../graph/general_matching.hpp",
        # "../graph/two_edge_connected_components.cpp",

        # "../graph/bipartite_matching.hpp",
        # "../graph/bipartite_edge_coloring.hpp",
        # "../graph/shortest_path.cpp",
        # "../graph/edge.cpp",
        # "../graph/eulerian_path.hpp",
        # "../graph/maximum_weight_independent_set.hpp",
        # "../graph/dominator_tree.cpp",
        # "../graph/biconnected_components.cpp",
        # "../graph/maximum_independent_set.cpp",
        # "../graph/dm_decomposition.cpp",
        # "../graph/pseudotree_cycle.hpp",
        # "../graph/offline_dynamic_connectivity.cpp",
        # "../graph/minimum_steiner_tree.hpp",
        # "../graph/assignment.hpp",
    ],
    "math": [
        "../math/garner.cpp",
        "../math/euler_totient.cpp",
        "../math/mod_arithmetic.cpp",
        "../math/floor_sum.cpp",
        "../math/polynomial.cpp",

        # "../math/bostan_mori.hpp",
        # "../math/berlekamp_massey.cpp",
    ],
    "misc": [
        "../misc/mo.cpp",
        "../misc/interval_set.hpp",
        "../sat/twosat.hpp",
        # "../misc/memo.hpp",
    ],
    "string": [
        "../string/rolling_hash.cpp",
        "../string/suffix_array.cpp",
        "../string/lcp_array.cpp",
        "../string/z_array.cpp",
        "../string/trie.cpp",
        "../string/kmp.cpp",
        "../string/aho_corasick.cpp",
    ],
    "tree": [
        "../tree/lca.cpp",
        "../tree/tree_isomorphism.hpp",
        "../tree/centroid_decomposition.hpp",
        "../tree/hld.cpp",
        "../tree/tree_diameter.cpp",
        "../tree/rerooting.cpp",

        "../tree/link_cut_tree.cpp",

        # "../tree/auxiliary_tree.cpp",
    ],
}

def list_all_files():
    sections = ["convolution", "data-structure", "dp", "flow", "geometry", "graph", "math", "misc", "sat", "string", "tree"]
    # sections = ["data-structure"]
    # sections = ["convolution"]

    res = ["paths = {"]
    for sec in sections:
        res.append(f"    \"{sec}\": [")
        for root, dirs, files in os.walk(os.path.join("..", sec)):
            for f in files:
                if ".cpp" in f or ".hpp" in f:
                    res.append(f"        \"{os.path.join(root, f)}\",")
        res.append("    ],")
    res.append("}")
    print("\n".join(res))


if __name__ == "__main__":
    list_all_files()