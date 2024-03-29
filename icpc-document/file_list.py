import os

paths = {
    "convolution": [
        "../convolution/xor_convolution.hpp",
        "../convolution/and_or_convolution.hpp",
        "../convolution/ntt.hpp",
        "../convolution/fft.hpp",
        # "../convolution/subset_convolution.hpp",
        # "../convolution/arbitrary_mod_convolution.hpp",
        "../convolution/gcd_lcm_convolution.hpp",
    ],
    "data-structure": [
        # "../data-structure/foldable_deque.hpp",
        # "../data-structure/sqrt_tree.cpp",
        # "../data-structure/persistent_array.cpp",
        "../data-structure/sparse_table.cpp",
        # "../data-structure/inner_product_search.hpp",
        # "../data-structure/slope_trick.cpp",
        # "../data-structure/fenwick_tree_2d.cpp",
        # "../data-structure/wavelet_matrix.hpp",
        # "../data-structure/fenwick_tree.cpp",
        # "../data-structure/disjoint_sparse_table.cpp",
        # "../data-structure/min_max_heap.hpp",
        # "../data-structure/persistent_stack.cpp",
        # "../data-structure/partition_refinement.hpp",
        # "../data-structure/bit_vector.cpp",
        # "../data-structure/binary_trie.cpp",
        # "../data-structure/quadtree.cpp",
        # "../data-structure/persistent_queue.cpp",
        # "../data-structure/sliding_window_aggregation.cpp",
        # "../data-structure/kd_tree.cpp",
        # "../data-structure/leftist_heap.cpp",
        # "../data-structure/range_tree.cpp",
        # "../data-structure/slide_min.cpp",
        # "../data-structure/range_fenwick_tree.cpp",
        # "../data-structure/segtree/xor_segment_tree.hpp",
        # "../data-structure/segtree/sortable_segment_tree.hpp",
        "../data-structure/segtree/segment_tree_2d.hpp",
        # "../data-structure/segtree/dynamic_segment_tree.hpp",
        # "../data-structure/segtree/lazy_segment_tree.hpp",
        # "../data-structure/segtree/segment_tree_beats.cpp",
        # "../data-structure/segtree/persistent_segment_tree.hpp",
        # "../data-structure/segtree/dual_segment_tree.hpp",
        # "../data-structure/segtree/segment_tree.hpp",
        # "../data-structure/segtree/dynamic_lazy_segment_tree.hpp",
        # "../data-structure/unionfind/weighted_union_find.hpp",
        # "../data-structure/unionfind/union_find.hpp",
        # "../data-structure/unionfind/undoable_union_find.hpp",
        # "../data-structure/unionfind/partially_persistent_union_find.hpp",
        # "../data-structure/unionfind/persistent_union_find.hpp",
        # "../data-structure/bst/rbst.cpp",
        # "../data-structure/bst/lazy_treap.cpp",
        # "../data-structure/bst/treap.cpp",
        # "../data-structure/bst/red_black_tree.cpp",
        # "../data-structure/bst/splay_tree.cpp",
        # "../data-structure/cht/undoable_li_chao_tree.cpp",
        # "../data-structure/cht/offline_deletable_convex_hull_trick.cpp",
        # "../data-structure/cht/convex_hull_trick_binsearchtree.hpp",
        # "../data-structure/cht/convex_hull_trick.cpp",
        # "../data-structure/cht/li_chao_tree.cpp",
    ],
    # "dp": [
    #     "../dp/lis.hpp",
    #     "../dp/lcs.hpp",
    #     "../dp/hu_tucker.cpp",
    #     "../dp/largest_rectangle.cpp",
    #     "../dp/monotone_minima.cpp",
    #     "../dp/smawk.cpp",
    #     "../dp/edit_distance.hpp",
    # ],
    "flow": [
        "../flow/ford_fulkerson.cpp",
        "../flow/min_cost_flow.cpp",
        # "../flow/min_cost_b_flow.hpp",
        "../flow/dinic.cpp",
    ],
    "geometry": [
        "../geometry/geometry.hpp",
        "../geometry/intersect.hpp",
        "../geometry/intersection.hpp",
        "../geometry/dist.hpp",
        "../geometry/convex_hull.hpp",
        "../geometry/polygon.hpp",
        "../geometry/tangent.hpp",
        "../geometry/triangle.hpp",
        "../geometry/bisector.hpp",
        "../geometry/geometry3d.hpp",

        # "../geometry/delaunay_diagram.hpp",
        # "../geometry/minimum_bounding_circle.hpp",
        # "../geometry/closest_pair.hpp",
    ],
    "graph": [
        # "../graph/two_edge_connected_components.cpp",
        # "../graph/bipartite_matching.hpp",
        # "../graph/bipartite_edge_coloring.hpp",
        # "../graph/shortest_path.cpp",
        # "../graph/chromatic_number.cpp",
        # "../graph/chordal_graph_recognition.hpp",
        # "../graph/lex_bfs.hpp",
        # "../graph/range_edge_graph.cpp",
        "../graph/lowlink.cpp",
        # "../graph/topological_sort.cpp",
        # "../graph/edge.cpp",
        # "../graph/enumerate_triangles.cpp",
        # "../graph/mst.cpp",
        # "../graph/maximum_weight_independent_set.hpp",
        "../graph/scc.cpp",
        # "../graph/eulerian_walk.hpp",
        # "../graph/dominator_tree.cpp",
        # "../graph/biconnected_components.cpp",
        # "../graph/maximum_independent_set.cpp",
        # "../graph/dm_decomposition.cpp",
        # "../graph/general_matching.hpp",
        # "../graph/pseudotree_cycle.hpp",
        # "../graph/minimum_spanning_arborescence.cpp",
        # "../graph/offline_dynamic_connectivity.cpp",
        # "../graph/enumerate_cliques.cpp",
        # "../graph/junction_tree.hpp",
        # "../graph/minimum_steiner_tree.hpp",
        # "../graph/assignment.hpp",
    ],
    "math": [
        # "../math/kth_root.hpp",
        # "../math/isqrt.hpp",
        # "../math/system_of_linear_equations.cpp",
        # "../math/garner.cpp",
        # "../math/extgcd.cpp",
        # "../math/lagrange_polynomial.hpp",
        # "../math/euler_totient.cpp",
        # "../math/nimber.hpp",
        "../math/bostan_mori.hpp",
        # "../math/modint.hpp",
        # "../math/combination_arbitrary_mod.hpp",
        # "../math/combination.cpp",
        # "../math/carmichael.cpp",
        # "../math/arbitrary_modint.hpp",
        # "../math/fast_prime.cpp",
        # "../math/berlekamp_massey.cpp",
        # "../math/quotients.hpp",
        # "../math/prime.cpp",
        # "../math/prime_count.hpp",
        # "../math/mod_arithmetic.cpp",
        # "../math/floor_sum.cpp",
        # "../math/interpolation.cpp",
        # "../math/stirling_second.hpp",
        # "../math/farey_sequence.hpp",
        # "../math/combination_large.hpp",
        # "../math/convert_base.cpp",
        # "../math/divisor.cpp",
        # "../math/polynomial.cpp",
        # "../math/lagrange_interpolation.hpp",
        # "../math/montmort.cpp",
        # "../math/stern_brocot_tree.hpp",
        # "../math/moebius.hpp",
        # "../math/multipoint_evaluation.cpp",
        # "../math/stirling_first.hpp",
        # "../math/kitamasa.cpp",
        # "../math/matrix/matrix.hpp",
        # "../math/matrix/square_matrix.hpp",
    ],
    "misc": [
        # "../misc/enumerate_subsets.hpp",
        # "../misc/timer.cpp",
        # "../misc/matroid_intersection.hpp",
        # "../misc/golden_section_search.hpp",
        # "../misc/monoids.cpp",
        # "../misc/fraction.cpp",
        # "../misc/majority.hpp",
        # "../misc/marathon_template.cpp",
        # "../misc/stable_matching.hpp",
        # "../misc/min_periodic_function.hpp",
        # "../misc/sorting.hpp",
        "../misc/mo.cpp",
        # "../misc/discrete_log_monoid_action.hpp",
        # "../misc/random.cpp",
        # "../misc/median_set.cpp",
        # "../misc/intervals.hpp",
        "../misc/interval_set.hpp",
        # "../misc/permutation.hpp",
        # "../misc/compress.cpp",
        # "../misc/memo.hpp",
        # "../misc/boolean_square_matrix.hpp",
    ],
    "sat": [
        # "../sat/hornsat.hpp",
        "../sat/twosat.hpp",
    ],
    "string": [
        # "../string/rolling_hash.cpp",
        # "../string/suffix_array.cpp",
        # "../string/lcp_array.cpp",
        # "../string/z_array.cpp",
        # "../string/aho_corasick.cpp",
        # "../string/kmp.cpp",
        # "../string/trie.cpp",

        "../string/manacher.cpp",
        "../string/min_cyclic_shift.hpp",
        # "../string/pattern_search_2d.hpp",
        # "../string/enumerate_runs.hpp",
        # "../string/palindromic_tree.hpp",
    ],
    "tree": [
        "../tree/link_cut_tree.cpp",
        # "../tree/cartesian_tree.cpp",
        # "../tree/lca.cpp",
        # "../tree/tree_isomorphism.hpp",
        # "../tree/centroid_decomposition.hpp",
        # "../tree/binary_lifting.hpp",
        # "../tree/auxiliary_tree.cpp",
        # "../tree/permutation_tree.hpp",
        # "../tree/euler_tour.cpp",
        # "../tree/euler_tour_tree.cpp",
        # "../tree/hld.cpp",
        # "../tree/tree_diameter.cpp",
        # "../tree/rerooting.cpp",
        # "../tree/range_contour_aggregation.hpp",
    ],
}


def list_all_files():
    sections = ["convolution", "data-structure", "dp", "flow",
                "geometry", "graph", "math", "misc", "sat", "string", "tree"]

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
