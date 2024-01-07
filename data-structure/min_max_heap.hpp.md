---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/double_ended_priority_queue.test.cpp
    title: test/yosupo/double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/min_max_heap.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <vector>\n\ntemplate <typename T>\n\
    class MinMaxHeap {\n   public:\n    MinMaxHeap() = default;\n    explicit MinMaxHeap(const\
    \ std::vector<T>& v) : heap(v) {\n        for (int i = (int)heap.size() / 2 -\
    \ 1; i >= 0; --i) {\n            pushdown(i);\n        }\n    }\n\n    void insert(T\
    \ x) {\n        heap.push_back(x);\n        pushup(heap.size() - 1);\n    }\n\n\
    \    T min_element() const {\n        assert(!heap.empty());\n        return heap[0];\n\
    \    }\n\n    T max_element() const {\n        assert(!heap.empty());\n      \
    \  if (heap.size() <= 2) return heap.back();\n        return std::max(heap[1],\
    \ heap[2]);\n    }\n\n    void erase_min() {\n        assert(!heap.empty());\n\
    \        heap[0] = heap.back();\n        heap.pop_back();\n        pushdown(0);\n\
    \    }\n\n    void erase_max() {\n        assert(!heap.empty());\n        if (heap.size()\
    \ <= 2) {\n            heap.pop_back();\n            return;\n        }\n    \
    \    if (heap.size() == 3) {\n            heap[1] = std::min(heap[1], heap[2]);\n\
    \            heap.pop_back();\n            return;\n        }\n        int i =\
    \ heap[1] > heap[2] ? 1 : 2;\n        heap[i] = heap.back();\n        heap.pop_back();\n\
    \        pushdown(i);\n    }\n\n   private:\n    std::vector<T> heap;\n\n    void\
    \ pushdown(int i) {\n        int d = std::bit_width((unsigned int)i + 1) - 1;\n\
    \        int n = heap.size();\n\n        while (true) {\n            int l = 2\
    \ * i + 1, r = l + 1;\n            if (l >= n) return;\n\n            int m =\
    \ i;  // idx of smallest child or grandchild\n            std::vector<int> check\
    \ = {l,         r,         2 * l + 1,\n                                      2\
    \ * l + 2, 2 * r + 1, 2 * r + 2};\n            for (int j : check) {\n       \
    \         if (j < n && ((d % 2) ^ (heap[j] < heap[m]))) m = j;\n            }\n\
    \n            if (m >= 2 * l + 1) {  // grandchild\n                if ((d % 2)\
    \ ^ (heap[m] < heap[i])) {\n                    std::swap(heap[m], heap[i]);\n\
    \                    int p = (m - 1) / 2;  // parent of m\n                  \
    \  if ((d % 2) ^ (heap[m] > heap[p]))\n                        std::swap(heap[m],\
    \ heap[p]);\n                    i = m;\n                } else {\n          \
    \          break;\n                }\n            } else {\n                std::swap(heap[m],\
    \ heap[i]);\n                break;\n            }\n        }\n    }\n\n    void\
    \ pushup(int i) {\n        if (i == 0) return;\n        int p = (i - 1) / 2;\n\
    \        int d = std::bit_width((unsigned int)i + 1) - 1;\n        if ((d % 2)\
    \ ^ (heap[i] > heap[p])) {\n            std::swap(heap[i], heap[p]);\n       \
    \     i = p;\n            --d;\n        }\n        while (i >= 3) {  // while\
    \ i has a grandparent\n            int g = ((i - 1) / 2 - 1) / 2;\n          \
    \  if ((d % 2) ^ (heap[i] > heap[g])) break;\n            std::swap(heap[i], heap[g]);\n\
    \            i = g;\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <vector>\n\ntemplate <typename T>\nclass MinMaxHeap {\n   public:\n \
    \   MinMaxHeap() = default;\n    explicit MinMaxHeap(const std::vector<T>& v)\
    \ : heap(v) {\n        for (int i = (int)heap.size() / 2 - 1; i >= 0; --i) {\n\
    \            pushdown(i);\n        }\n    }\n\n    void insert(T x) {\n      \
    \  heap.push_back(x);\n        pushup(heap.size() - 1);\n    }\n\n    T min_element()\
    \ const {\n        assert(!heap.empty());\n        return heap[0];\n    }\n\n\
    \    T max_element() const {\n        assert(!heap.empty());\n        if (heap.size()\
    \ <= 2) return heap.back();\n        return std::max(heap[1], heap[2]);\n    }\n\
    \n    void erase_min() {\n        assert(!heap.empty());\n        heap[0] = heap.back();\n\
    \        heap.pop_back();\n        pushdown(0);\n    }\n\n    void erase_max()\
    \ {\n        assert(!heap.empty());\n        if (heap.size() <= 2) {\n       \
    \     heap.pop_back();\n            return;\n        }\n        if (heap.size()\
    \ == 3) {\n            heap[1] = std::min(heap[1], heap[2]);\n            heap.pop_back();\n\
    \            return;\n        }\n        int i = heap[1] > heap[2] ? 1 : 2;\n\
    \        heap[i] = heap.back();\n        heap.pop_back();\n        pushdown(i);\n\
    \    }\n\n   private:\n    std::vector<T> heap;\n\n    void pushdown(int i) {\n\
    \        int d = std::bit_width((unsigned int)i + 1) - 1;\n        int n = heap.size();\n\
    \n        while (true) {\n            int l = 2 * i + 1, r = l + 1;\n        \
    \    if (l >= n) return;\n\n            int m = i;  // idx of smallest child or\
    \ grandchild\n            std::vector<int> check = {l,         r,         2 *\
    \ l + 1,\n                                      2 * l + 2, 2 * r + 1, 2 * r +\
    \ 2};\n            for (int j : check) {\n                if (j < n && ((d % 2)\
    \ ^ (heap[j] < heap[m]))) m = j;\n            }\n\n            if (m >= 2 * l\
    \ + 1) {  // grandchild\n                if ((d % 2) ^ (heap[m] < heap[i])) {\n\
    \                    std::swap(heap[m], heap[i]);\n                    int p =\
    \ (m - 1) / 2;  // parent of m\n                    if ((d % 2) ^ (heap[m] > heap[p]))\n\
    \                        std::swap(heap[m], heap[p]);\n                    i =\
    \ m;\n                } else {\n                    break;\n                }\n\
    \            } else {\n                std::swap(heap[m], heap[i]);\n        \
    \        break;\n            }\n        }\n    }\n\n    void pushup(int i) {\n\
    \        if (i == 0) return;\n        int p = (i - 1) / 2;\n        int d = std::bit_width((unsigned\
    \ int)i + 1) - 1;\n        if ((d % 2) ^ (heap[i] > heap[p])) {\n            std::swap(heap[i],\
    \ heap[p]);\n            i = p;\n            --d;\n        }\n        while (i\
    \ >= 3) {  // while i has a grandparent\n            int g = ((i - 1) / 2 - 1)\
    \ / 2;\n            if ((d % 2) ^ (heap[i] > heap[g])) break;\n            std::swap(heap[i],\
    \ heap[g]);\n            i = g;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/min_max_heap.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/double_ended_priority_queue.test.cpp
documentation_of: data-structure/min_max_heap.hpp
layout: document
title: Min-Max Heap
---

## Description

Min-max heap は，要素の最大値と最小値を取得することのできるヒープである．

## Operations

- `MinMaxHeap(vector<T> v)`
    - $v$ の要素から min-max heap を構築する
    - 時間計算量: $O(n)$
- `void insert(T x)`
    - $x$ を挿入する
    - 時間計算量: $O(\log n)$
- `T min_element()`
    - 最小値を求める
    - 時間計算量: $O(1)$
- `T max_element()`
    - 最大値を求める
    - 時間計算量: $O(1)$
- `void erase_min()`
    - 最小値を削除する
    - 時間計算量: $O(\log n)$
- `void erase_max()`
    - 最大値を削除する
    - 時間計算量: $O(\log n)$

## Reference

- [Min-max heap - Wikipedia](https://en.wikipedia.org/wiki/Min-max_heap)