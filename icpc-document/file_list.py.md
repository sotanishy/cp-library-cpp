---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\n\npaths = {\n    \"convolution\": [\n        \"../convolution/xor_convolution.hpp\"\
    ,\n        \"../convolution/and_or_convolution.hpp\",\n        \"../convolution/gcd_lcm_convolution.hpp\"\
    ,\n        \"../convolution/fft.hpp\",\n    ],\n    \"data-structure\": [\n  \
    \      \"../data-structure/segtree/segment_tree.cpp\",\n        \"../data-structure/segtree/lazy_segment_tree.cpp\"\
    ,\n        \"../data-structure/fenwick_tree.cpp\",\n        \"../data-structure/range_tree.cpp\"\
    ,\n        \"../data-structure/unionfind/union_find.cpp\",\n        \"../data-structure/unionfind/weighted_union_find.cpp\"\
    ,\n        \"../data-structure/cht/convex_hull_trick.cpp\",\n        # \"../data-structure/bst/treap.cpp\"\
    ,\n        # \"../data-structure/kd_tree.cpp\",\n        # \"../data-structure/bit_vector.cpp\"\
    ,\n        # \"../data-structure/wavelet_matrix.cpp\",\n        # \"../data-structure/binary_trie.cpp\"\
    ,\n        # \"../data-structure/disjoint_sparse_table.cpp\",\n        # \"../data-structure/kd_tree.cpp\"\
    ,\n\n        # \"../data-structure/persistent_array.cpp\",\n        # \"../data-structure/sparse_table.cpp\"\
    ,\n        # \"../data-structure/slope_trick.cpp\",\n        # \"../data-structure/persistent_stack.cpp\"\
    ,\n        # \"../data-structure/persistent_queue.cpp\",\n        # \"../data-structure/segtree/segment_tree_2d.hpp\"\
    ,\n        # \"../data-structure/segtree/segment_tree_beats.cpp\",\n        #\
    \ \"../data-structure/segtree/persistent_segment_tree.cpp\",\n        # \"../data-structure/segtree/dual_segment_tree.cpp\"\
    ,\n        # \"../data-structure/unionfind/undoable_union_find.cpp\",\n      \
    \  # \"../data-structure/unionfind/partially_persistent_union_find.cpp\",\n  \
    \      # \"../data-structure/bst/rbst.cpp\",\n        # \"../data-structure/bst/lazy_treap.cpp\"\
    ,\n        # \"../data-structure/bst/red_black_tree.cpp\",\n        # \"../data-structure/bst/splay_tree.cpp\"\
    ,\n        # \"../data-structure/cht/convex_hull_trick_binsearchtree.hpp\",\n\
    \        # \"../data-structure/cht/li_chao_tree.cpp\",\n    ],\n    \"flow\":\
    \ [\n        \"../flow/ford_fulkerson.cpp\",\n        \"../flow/dinic.cpp\",\n\
    \        \"../flow/min_cost_flow.cpp\",\n    ],\n    \"geometry\": [\n       \
    \ \"../geometry/geometry.hpp\",\n        \"../geometry/intersection.hpp\",\n \
    \       \"../geometry/dist.hpp\",\n        \"../geometry/intersect.hpp\",\n  \
    \      \"../geometry/tangent.hpp\",\n        \"../geometry/polygon.hpp\",\n  \
    \      \"../geometry/triangle.hpp\",\n        \"../geometry/convex_hull.hpp\"\
    ,\n        \"../geometry/bisector.hpp\",\n        \"../geometry/geometry3d.hpp\"\
    ,\n    ],\n    \"graph\": [\n        \"../graph/scc.cpp\",\n        \"../graph/lowlink.cpp\"\
    ,\n\n        # \"../graph/topological_sort.cpp\",\n        # \"../graph/mst.cpp\"\
    ,\n        # \"../graph/range_edge_graph.cpp\",\n        # \"../graph/enumerate_cliques.cpp\"\
    ,\n        # \"../graph/chromatic_number.cpp\",\n        # \"../graph/enumerate_triangles.cpp\"\
    ,\n        # \"../graph/general_matching.hpp\",\n        # \"../graph/two_edge_connected_components.cpp\"\
    ,\n\n        # \"../graph/bipartite_matching.hpp\",\n        # \"../graph/bipartite_edge_coloring.hpp\"\
    ,\n        # \"../graph/shortest_path.cpp\",\n        # \"../graph/edge.cpp\"\
    ,\n        # \"../graph/eulerian_path.hpp\",\n        # \"../graph/maximum_weight_independent_set.hpp\"\
    ,\n        # \"../graph/dominator_tree.cpp\",\n        # \"../graph/biconnected_components.cpp\"\
    ,\n        # \"../graph/maximum_independent_set.cpp\",\n        # \"../graph/dm_decomposition.cpp\"\
    ,\n        # \"../graph/pseudotree_cycle.hpp\",\n        # \"../graph/offline_dynamic_connectivity.cpp\"\
    ,\n        # \"../graph/minimum_steiner_tree.hpp\",\n        # \"../graph/assignment.hpp\"\
    ,\n    ],\n    \"math\": [\n        \"../math/garner.cpp\",\n        \"../math/euler_totient.cpp\"\
    ,\n        \"../math/mod_arithmetic.cpp\",\n        \"../math/floor_sum.cpp\"\
    ,\n        \"../math/polynomial.cpp\",\n\n        # \"../math/bostan_mori.hpp\"\
    ,\n        # \"../math/berlekamp_massey.cpp\",\n    ],\n    \"misc\": [\n    \
    \    \"../misc/mo.cpp\",\n        \"../misc/interval_set.hpp\",\n        \"../sat/twosat.hpp\"\
    ,\n        # \"../misc/memo.hpp\",\n    ],\n    \"string\": [\n        \"../string/rolling_hash.cpp\"\
    ,\n        \"../string/suffix_array.cpp\",\n        \"../string/lcp_array.cpp\"\
    ,\n        \"../string/z_array.cpp\",\n        \"../string/trie.cpp\",\n     \
    \   \"../string/kmp.cpp\",\n        \"../string/aho_corasick.cpp\",\n    ],\n\
    \    \"tree\": [\n        \"../tree/lca.cpp\",\n        \"../tree/tree_isomorphism.hpp\"\
    ,\n        \"../tree/centroid_decomposition.hpp\",\n        \"../tree/hld.cpp\"\
    ,\n        \"../tree/tree_diameter.cpp\",\n        \"../tree/rerooting.cpp\",\n\
    \n        \"../tree/link_cut_tree.cpp\",\n\n        # \"../tree/auxiliary_tree.cpp\"\
    ,\n    ],\n}\n\ndef list_all_files():\n    sections = [\"convolution\", \"data-structure\"\
    , \"dp\", \"flow\", \"geometry\", \"graph\", \"math\", \"misc\", \"sat\", \"string\"\
    , \"tree\"]\n    # sections = [\"data-structure\"]\n    # sections = [\"convolution\"\
    ]\n\n    res = [\"paths = {\"]\n    for sec in sections:\n        res.append(f\"\
    \    \\\"{sec}\\\": [\")\n        for root, dirs, files in os.walk(os.path.join(\"\
    ..\", sec)):\n            for f in files:\n                if \".cpp\" in f or\
    \ \".hpp\" in f:\n                    res.append(f\"        \\\"{os.path.join(root,\
    \ f)}\\\",\")\n        res.append(\"    ],\")\n    res.append(\"}\")\n    print(\"\
    \\n\".join(res))\n\n\nif __name__ == \"__main__\":\n    list_all_files()"
  dependsOn: []
  isVerificationFile: false
  path: icpc-document/file_list.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc-document/file_list.py
layout: document
redirect_from:
- /library/icpc-document/file_list.py
- /library/icpc-document/file_list.py.html
title: icpc-document/file_list.py
---
