---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Minimum Spanning Arborescence
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data-structure/leftist_heap.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <memory>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n#include \"edge.cpp\"\
    \n#include \"../data-structure/unionfind/union_find.hpp\"\n#include \"../data-structure/leftist_heap.cpp\"\
    \n\n/*\n * @brief Minimum Spanning Arborescence\n */\ntemplate <typename T>\n\
    std::pair<T, std::vector<int>> minimum_spanning_arborescence(std::vector<Edge<T>>\
    \ G, int V, int root) {\n    std::vector<LeftistHeap<T>> incoming(V);\n    for\
    \ (int i = 0; i < (int) G.size(); ++i) {\n        auto& e = G[i];\n        incoming[e.to].push(i,\
    \ e.weight);\n    }\n    T weight = 0;\n    UnionFind uf(V);\n    std::vector<int>\
    \ from(V), stem(V, -1), prev_edge(G.size()), ord;\n    std::vector<T> from_cost(V);\n\
    \    std::vector<int> status(V); // 0: not checked, 1: cheking, 2: checked\n \
    \   status[root] = 2;\n\n    for (int s = 0; s < V; ++s) {\n        if (status[s]\
    \ != 0) continue;\n        int cur = s, cyc = 0;\n        std::vector<int> seen,\
    \ processing;\n        while (status[cur] != 2) {\n            status[cur] = 1;\n\
    \            processing.push_back(cur);\n            if (incoming[cur].empty())\
    \ { // no msa\n                return {std::numeric_limits<T>::max(), std::vector<int>()};\n\
    \            }\n\n            auto [i, c] = incoming[cur].top();\n           \
    \ int v = uf.find(G[i].from);\n            incoming[cur].pop();\n            if\
    \ (cur == v) continue;\n            from[cur] = v;\n            from_cost[cur]\
    \ = c;\n            weight += c;\n            ord.push_back(i);\n            if\
    \ (stem[cur] == -1) stem[cur] = i;\n            while (cyc) {\n              \
    \  prev_edge[seen.back()] = i;\n                seen.pop_back();\n           \
    \     --cyc;\n            }\n            seen.push_back(i);\n\n            if\
    \ (status[v] == 1) {\n                int p = cur;\n                do {\n   \
    \                 if (!incoming[p].empty()) incoming[p].add(-from_cost[p]);\n\
    \                    if (p != cur) {\n                        uf.unite(p, cur);\n\
    \                        auto newheap = LeftistHeap<T>::meld(std::move(incoming[cur]),\
    \ std::move(incoming[p]));\n                        incoming[cur = uf.find(cur)]\
    \ = std::move(newheap);\n                    }\n                    p = uf.find(from[p]);\n\
    \                    ++cyc;\n                } while (p != cur);\n           \
    \ } else {\n                cur = v;\n            }\n        }\n        for (int\
    \ v : processing) status[v] = 2;\n    }\n    std::reverse(ord.begin(), ord.end());\n\
    \    std::vector<bool> used_edge(G.size());\n    std::vector<int> par(V);\n  \
    \  std::iota(par.begin(), par.end(), 0);\n    for (int i : ord) {\n        if\
    \ (used_edge[i]) continue;\n        auto& e = G[i];\n        par[e.to] = e.from;\n\
    \        int x = stem[e.to];\n        while (x != i) {\n            used_edge[x]\
    \ = true;\n            x = prev_edge[x];\n        }\n    }\n    return {weight,\
    \ par};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimum_spanning_arborescence.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimum_spanning_arborescence.cpp
layout: document
redirect_from:
- /library/graph/minimum_spanning_arborescence.cpp
- /library/graph/minimum_spanning_arborescence.cpp.html
title: Minimum Spanning Arborescence
---
