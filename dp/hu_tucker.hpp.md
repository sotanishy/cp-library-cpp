---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/leftist_heap.hpp
    title: Leftist Heap
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2415.test.cpp
    title: test/aoj/2415.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/hu_tucker.hpp\"\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n#line 2 \"data-structure/leftist_heap.hpp\"\
    \n#include <algorithm>\n#include <memory>\n#line 5 \"data-structure/leftist_heap.hpp\"\
    \n\ntemplate <typename T>\nclass LeftistHeap {\n   public:\n    LeftistHeap()\
    \ = default;\n\n    static LeftistHeap meld(LeftistHeap a, LeftistHeap b) {\n\
    \        return LeftistHeap(meld(std::move(a.root), std::move(b.root)));\n   \
    \ }\n\n    std::pair<int, T> top() const {\n        push(root);\n        return\
    \ {root->id, root->val};\n    }\n\n    void pop() {\n        push(root);\n   \
    \     root = meld(std::move(root->left), std::move(root->right));\n    }\n\n \
    \   void push(int id, T x) {\n        root = meld(std::move(root), std::make_unique<Node>(id,\
    \ x));\n    }\n\n    bool empty() const { return root == nullptr; }\n\n    void\
    \ add(T x) { root->lazy += x; }\n\n   private:\n    struct Node;\n    using node_ptr\
    \ = std::unique_ptr<Node>;\n\n    struct Node {\n        node_ptr left, right;\n\
    \        int s;\n        int id;\n        T val, lazy;\n        Node(int id, T\
    \ x) : id(id), val(x), lazy(0) {}\n    };\n\n    node_ptr root = nullptr;\n\n\
    \    explicit LeftistHeap(node_ptr root) : root(std::move(root)) {}\n\n    static\
    \ node_ptr meld(node_ptr a, node_ptr b) {\n        if (!a) return b;\n       \
    \ if (!b) return a;\n        push(a);\n        push(b);\n        if (a->val >\
    \ b->val) std::swap(a, b);\n        a->right = meld(std::move(a->right), std::move(b));\n\
    \        if (!a->left || a->left->s < a->right->s) std::swap(a->left, a->right);\n\
    \        a->s = (a->right ? a->right->s : 0) + 1;\n        return a;\n    }\n\n\
    \    static void push(const node_ptr& t) {\n        if (t->left) t->left->lazy\
    \ += t->lazy;\n        if (t->right) t->right->lazy += t->lazy;\n        t->val\
    \ += t->lazy;\n        t->lazy = 0;\n    }\n};\n#line 9 \"dp/hu_tucker.hpp\"\n\
    \ntemplate <typename T>\nT hu_tucker(std::vector<T> w) {\n    const int n = w.size();\n\
    \    const T INF = std::numeric_limits<T>::max() / 2;\n    std::vector<LeftistHeap<T>>\
    \ heaps(n - 1);  // interior nodes in each group\n    std::vector<int> left(n),\
    \ right(n);\n    std::vector<T> cs(n - 1);\n    using P = std::pair<T, int>;\n\
    \    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n    for (int\
    \ i = 0; i < n - 1; ++i) {\n        left[i] = i - 1;\n        right[i] = i + 1;\n\
    \        cs[i] = w[i] + w[i + 1];\n        pq.emplace(cs[i], i);\n    }\n    T\
    \ ret = 0;\n    for (int k = 0; k < n - 1; ++k) {\n        T c;\n        int i;\n\
    \        // find the optimal nodes to merge\n        do {\n            std::tie(c,\
    \ i) = pq.top();\n            pq.pop();\n        } while (right[i] == -1 || cs[i]\
    \ != c);\n\n        bool merge_l = false, merge_r = false;\n        if (w[i] +\
    \ w[right[i]] == c) {  // lr\n            merge_l = merge_r = true;\n        }\
    \ else {\n            T top = heaps[i].top().second;\n            heaps[i].pop();\n\
    \            if (w[i] + top == c) {  // lm\n                merge_l = true;\n\
    \            } else if (top + w[right[i]] == c) {  // mr\n                merge_r\
    \ = true;\n            } else {  // mm\n                heaps[i].pop();\n    \
    \        }\n        }\n        ret += c;\n        heaps[i].push(-1, c);\n    \
    \    if (merge_l) {\n            w[i] = INF;\n        }\n        if (merge_r)\
    \ {\n            w[right[i]] = INF;\n        }\n\n        // merge left\n    \
    \    if (merge_l && i > 0) {\n            int j = left[i];\n            heaps[j]\
    \ =\n                LeftistHeap<T>::meld(std::move(heaps[j]), std::move(heaps[i]));\n\
    \            right[j] = right[i];\n            right[i] = -1;\n            left[right[j]]\
    \ = j;\n            i = j;\n        }\n        // merge right\n        if (merge_r\
    \ && right[i] < n - 1) {\n            int j = right[i];\n            heaps[i]\
    \ =\n                LeftistHeap<T>::meld(std::move(heaps[i]), std::move(heaps[j]));\n\
    \            right[i] = right[j];\n            right[j] = -1;\n            left[right[i]]\
    \ = i;\n        }\n\n        cs[i] = w[i] + w[right[i]];  // lr\n        if (!heaps[i].empty())\
    \ {\n            T top = heaps[i].top().second;\n            heaps[i].pop();\n\
    \            cs[i] =\n                std::min(cs[i], std::min(w[i], w[right[i]])\
    \ + top);  // lm or mr\n            if (!heaps[i].empty()) {\n               \
    \ cs[i] = std::min(cs[i], top + heaps[i].top().second);  // mm\n            }\n\
    \            heaps[i].push(-1, top);\n        }\n        pq.emplace(cs[i], i);\n\
    \    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\n#include \"../data-structure/leftist_heap.hpp\"\
    \n\ntemplate <typename T>\nT hu_tucker(std::vector<T> w) {\n    const int n =\
    \ w.size();\n    const T INF = std::numeric_limits<T>::max() / 2;\n    std::vector<LeftistHeap<T>>\
    \ heaps(n - 1);  // interior nodes in each group\n    std::vector<int> left(n),\
    \ right(n);\n    std::vector<T> cs(n - 1);\n    using P = std::pair<T, int>;\n\
    \    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n    for (int\
    \ i = 0; i < n - 1; ++i) {\n        left[i] = i - 1;\n        right[i] = i + 1;\n\
    \        cs[i] = w[i] + w[i + 1];\n        pq.emplace(cs[i], i);\n    }\n    T\
    \ ret = 0;\n    for (int k = 0; k < n - 1; ++k) {\n        T c;\n        int i;\n\
    \        // find the optimal nodes to merge\n        do {\n            std::tie(c,\
    \ i) = pq.top();\n            pq.pop();\n        } while (right[i] == -1 || cs[i]\
    \ != c);\n\n        bool merge_l = false, merge_r = false;\n        if (w[i] +\
    \ w[right[i]] == c) {  // lr\n            merge_l = merge_r = true;\n        }\
    \ else {\n            T top = heaps[i].top().second;\n            heaps[i].pop();\n\
    \            if (w[i] + top == c) {  // lm\n                merge_l = true;\n\
    \            } else if (top + w[right[i]] == c) {  // mr\n                merge_r\
    \ = true;\n            } else {  // mm\n                heaps[i].pop();\n    \
    \        }\n        }\n        ret += c;\n        heaps[i].push(-1, c);\n    \
    \    if (merge_l) {\n            w[i] = INF;\n        }\n        if (merge_r)\
    \ {\n            w[right[i]] = INF;\n        }\n\n        // merge left\n    \
    \    if (merge_l && i > 0) {\n            int j = left[i];\n            heaps[j]\
    \ =\n                LeftistHeap<T>::meld(std::move(heaps[j]), std::move(heaps[i]));\n\
    \            right[j] = right[i];\n            right[i] = -1;\n            left[right[j]]\
    \ = j;\n            i = j;\n        }\n        // merge right\n        if (merge_r\
    \ && right[i] < n - 1) {\n            int j = right[i];\n            heaps[i]\
    \ =\n                LeftistHeap<T>::meld(std::move(heaps[i]), std::move(heaps[j]));\n\
    \            right[i] = right[j];\n            right[j] = -1;\n            left[right[i]]\
    \ = i;\n        }\n\n        cs[i] = w[i] + w[right[i]];  // lr\n        if (!heaps[i].empty())\
    \ {\n            T top = heaps[i].top().second;\n            heaps[i].pop();\n\
    \            cs[i] =\n                std::min(cs[i], std::min(w[i], w[right[i]])\
    \ + top);  // lm or mr\n            if (!heaps[i].empty()) {\n               \
    \ cs[i] = std::min(cs[i], top + heaps[i].top().second);  // mm\n            }\n\
    \            heaps[i].push(-1, top);\n        }\n        pq.emplace(cs[i], i);\n\
    \    }\n    return ret;\n}"
  dependsOn:
  - data-structure/leftist_heap.hpp
  isVerificationFile: false
  path: dp/hu_tucker.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2415.test.cpp
documentation_of: dp/hu_tucker.hpp
layout: document
title: Hu-Tucker Algorithm
---

## Description

Hu-Tucker のアルゴリズムは，最適二分探索木問題を高速に解くアルゴリズムである．

正当性の証明は難しいらしい．

## Operations

- `T hu_tucker(vector<T> w)`
    - 各頂点の重み $w_i$ が与えられたとき，最適二分探索木の重みを求める．
    - 時間計算量: $O(n\log n)$

## Reference

- [C - 最適二分探索木](https://atcoder.jp/contests/atc002/tasks/atc002_c)