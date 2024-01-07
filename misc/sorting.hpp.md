---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/sorting.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <map>\n#include <vector>\n\ntemplate <typename T, typename Compare>\n\
    void merge_sort(std::vector<T>& arr, int l, int r, Compare cmp) {\n    if (r -\
    \ l == 1) return;\n\n    int m = (l + r) / 2;\n    merge_sort(arr, l, m, cmp);\n\
    \    merge_sort(arr, m, r, cmp);\n\n    std::vector<T> res;\n    res.reserve(r\
    \ - l);\n    int i = l, j = m;\n    while (i < m && j < r) {\n        if (cmp(arr[i],\
    \ arr[j])) {\n            res.push_back(arr[i++]);\n        } else {\n       \
    \     res.push_back(arr[j++]);\n        }\n    }\n\n    while (i < m) res.push_back(arr[i++]);\n\
    \    while (j < r) res.push_back(arr[j++]);\n\n    for (int k = 0; k < r - l;\
    \ ++k) arr[l + k] = res[k];\n}\n\n// elements need to be distinct\ntemplate <typename\
    \ Compare>\nvoid merge_insertion_sort(std::vector<int>& arr, Compare cmp) {\n\
    \    int n = arr.size();\n    if (n <= 1) return;\n\n    std::map<int, int> idx;\n\
    \    for (int k = 0; k < n; ++k) {\n        assert(!idx.contains(arr[k]));\n \
    \       idx[arr[k]] = k;\n    }\n\n    // pair elements and recursively sort the\
    \ bigger ones\n    std::vector<int> a;\n    for (int k = 0; k < n - 1; k += 2)\
    \ {\n        a.push_back(cmp(arr[k], arr[k + 1]) ? arr[k + 1] : arr[k]);\n   \
    \ }\n    merge_insertion_sort(a, cmp);\n\n    // a: sorted\n    // b: not sorted\n\
    \    a.insert(a.begin(), arr[idx[a[0]] ^ 1]);\n    std::vector<int> b;\n    for\
    \ (int k = 2; k < (int)a.size(); ++k) {\n        b.push_back(arr[idx[a[k]] ^ 1]);\n\
    \    }\n    if (n % 2 == 1) {\n        b.push_back(arr.back());\n    }\n\n   \
    \ // insert b into a\n    int s = 0, prev = 0;\n    for (int i = 0; s < (int)b.size();\
    \ ++i) {\n        int g = std::min((1 << (i + 1)) - prev, (int)b.size() - s);\n\
    \        for (int k = g - 1; k >= 0; --k) {\n            int x = b[s + k];\n \
    \           // the first element guaranteed to be bigger than x\n            int\
    \ right = a.size();\n            if ((idx[x] ^ 1) < n) {\n                // this\
    \ takes O(n)\n                // it can be made O(log n) with a Fenwick tree\n\
    \                right = std::ranges::find(a, arr[idx[x] ^ 1]) - a.begin();\n\
    \            }\n            // search insertion point\n            int lb = -1,\
    \ ub = right;\n            while (ub - lb > 1) {\n                int m = std::midpoint(lb,\
    \ ub);\n                if (cmp(x, a[m]))\n                    ub = m;\n     \
    \           else\n                    lb = m;\n            }\n            a.insert(a.begin()\
    \ + ub, x);\n        }\n        s += g;\n        prev = g;\n    }\n\n    arr =\
    \ a;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <map>\n\
    #include <vector>\n\ntemplate <typename T, typename Compare>\nvoid merge_sort(std::vector<T>&\
    \ arr, int l, int r, Compare cmp) {\n    if (r - l == 1) return;\n\n    int m\
    \ = (l + r) / 2;\n    merge_sort(arr, l, m, cmp);\n    merge_sort(arr, m, r, cmp);\n\
    \n    std::vector<T> res;\n    res.reserve(r - l);\n    int i = l, j = m;\n  \
    \  while (i < m && j < r) {\n        if (cmp(arr[i], arr[j])) {\n            res.push_back(arr[i++]);\n\
    \        } else {\n            res.push_back(arr[j++]);\n        }\n    }\n\n\
    \    while (i < m) res.push_back(arr[i++]);\n    while (j < r) res.push_back(arr[j++]);\n\
    \n    for (int k = 0; k < r - l; ++k) arr[l + k] = res[k];\n}\n\n// elements need\
    \ to be distinct\ntemplate <typename Compare>\nvoid merge_insertion_sort(std::vector<int>&\
    \ arr, Compare cmp) {\n    int n = arr.size();\n    if (n <= 1) return;\n\n  \
    \  std::map<int, int> idx;\n    for (int k = 0; k < n; ++k) {\n        assert(!idx.contains(arr[k]));\n\
    \        idx[arr[k]] = k;\n    }\n\n    // pair elements and recursively sort\
    \ the bigger ones\n    std::vector<int> a;\n    for (int k = 0; k < n - 1; k +=\
    \ 2) {\n        a.push_back(cmp(arr[k], arr[k + 1]) ? arr[k + 1] : arr[k]);\n\
    \    }\n    merge_insertion_sort(a, cmp);\n\n    // a: sorted\n    // b: not sorted\n\
    \    a.insert(a.begin(), arr[idx[a[0]] ^ 1]);\n    std::vector<int> b;\n    for\
    \ (int k = 2; k < (int)a.size(); ++k) {\n        b.push_back(arr[idx[a[k]] ^ 1]);\n\
    \    }\n    if (n % 2 == 1) {\n        b.push_back(arr.back());\n    }\n\n   \
    \ // insert b into a\n    int s = 0, prev = 0;\n    for (int i = 0; s < (int)b.size();\
    \ ++i) {\n        int g = std::min((1 << (i + 1)) - prev, (int)b.size() - s);\n\
    \        for (int k = g - 1; k >= 0; --k) {\n            int x = b[s + k];\n \
    \           // the first element guaranteed to be bigger than x\n            int\
    \ right = a.size();\n            if ((idx[x] ^ 1) < n) {\n                // this\
    \ takes O(n)\n                // it can be made O(log n) with a Fenwick tree\n\
    \                right = std::ranges::find(a, arr[idx[x] ^ 1]) - a.begin();\n\
    \            }\n            // search insertion point\n            int lb = -1,\
    \ ub = right;\n            while (ub - lb > 1) {\n                int m = std::midpoint(lb,\
    \ ub);\n                if (cmp(x, a[m]))\n                    ub = m;\n     \
    \           else\n                    lb = m;\n            }\n            a.insert(a.begin()\
    \ + ub, x);\n        }\n        s += g;\n        prev = g;\n    }\n\n    arr =\
    \ a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/sorting.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/sorting.hpp
layout: document
title: Sorting Algorithms
---

## Description

いくつかのソーティングアルゴリズムの実装．主にインタラクティブ問題での使用を想定しており，時間計算量よりも比較回数を重視している．

- `void merge_sort(vector<T> arr, int l, int r, Compare cmp)`
    - リスト $\mathrm{arr}$ の区間 $[l, r)$ を比較関数 $\mathrm{cmp}$ によってマージソートする
    - 時間計算量: $O(n \log n)$
- `void merge_insertion_sort(vector<T> arr, Compare cmp)`
    - 要素に重複のないリスト $\mathrm{arr}$ を比較関数 $\mathrm{cmp}$ によってソートする
    - 時間計算量: $O(n^2 \log n)$ ($O(n (\log n)^2)$ に高速化可能)

## Note

比較ソートの最悪比較回数の情報理論的下界は $\lceil \log_2 n! \rceil \approx n\log_2 n - 1.443 n$ 回である．

マージソートの最悪比較回数は $n\log_2 n-0.915n$ から $n\log_2 n-n$ の間になることが知られている．

マージ挿入ソートの最悪比較回数は $n\log_2 n-1.415n$ 程度であることが知られている．マージ挿入ソートは，最悪比較回数が情報理論的下界に最も近いソーティングアルゴリズムの一つである．