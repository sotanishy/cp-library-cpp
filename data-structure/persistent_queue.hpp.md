---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.hpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent_queue.hpp\"\n#include <cassert>\n\
    \n#line 2 \"data-structure/persistent_array.hpp\"\n#include <memory>\n#include\
    \ <vector>\n\ntemplate <typename T, int B = 2>\nclass PersistentArray {\n   public:\n\
    \    PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int)v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const { return get(root, k); }\n\n    PersistentArray\
    \ set(int k, const T& x) const {\n        return PersistentArray(set(root, k,\
    \ x));\n    }\n\n   private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[B];\n    };\n\n    node_ptr\
    \ root = nullptr;\n\n    explicit PersistentArray(const node_ptr& root) : root(root)\
    \ {}\n\n    T get(const node_ptr& t, int k) const {\n        if (k == 0) return\
    \ t->val;\n        return get(t->ch[k % B], k / B);\n    }\n\n    node_ptr set(const\
    \ node_ptr& t, int k, const T& x) const {\n        node_ptr res =\n          \
    \  t ? std::make_shared<Node>(*t) : std::make_shared<Node>();\n        if (k ==\
    \ 0) {\n            res->val = x;\n        } else {\n            res->ch[k % B]\
    \ = set(res->ch[k % B], k / B, x);\n        }\n        return res;\n    }\n};\n\
    #line 5 \"data-structure/persistent_queue.hpp\"\n\ntemplate <typename T>\nclass\
    \ PersistentQueue {\n   public:\n    PersistentQueue() : first(0), last(0) {}\n\
    \n    int size() const { return last - first; }\n\n    bool empty() const { return\
    \ size() == 0; }\n\n    T front() const {\n        assert(!empty());\n       \
    \ return pa.get(first);\n    }\n\n    T back() const {\n        assert(!empty());\n\
    \        return pa.get(last - 1);\n    }\n\n    PersistentQueue push(const T&\
    \ val) const {\n        return PersistentQueue(pa.set(last, val), first, last\
    \ + 1);\n    }\n\n    PersistentQueue pop() const {\n        assert(!empty());\n\
    \        return PersistentQueue(pa, first + 1, last);\n    }\n\n   private:\n\
    \    PersistentArray<T> pa;\n    int first, last;\n\n    PersistentQueue(const\
    \ PersistentArray<T>& pa, int first, int last)\n        : pa(pa), first(first),\
    \ last(last) {}\n};\n"
  code: "#pragma once\n#include <cassert>\n\n#include \"persistent_array.hpp\"\n\n\
    template <typename T>\nclass PersistentQueue {\n   public:\n    PersistentQueue()\
    \ : first(0), last(0) {}\n\n    int size() const { return last - first; }\n\n\
    \    bool empty() const { return size() == 0; }\n\n    T front() const {\n   \
    \     assert(!empty());\n        return pa.get(first);\n    }\n\n    T back()\
    \ const {\n        assert(!empty());\n        return pa.get(last - 1);\n    }\n\
    \n    PersistentQueue push(const T& val) const {\n        return PersistentQueue(pa.set(last,\
    \ val), first, last + 1);\n    }\n\n    PersistentQueue pop() const {\n      \
    \  assert(!empty());\n        return PersistentQueue(pa, first + 1, last);\n \
    \   }\n\n   private:\n    PersistentArray<T> pa;\n    int first, last;\n\n   \
    \ PersistentQueue(const PersistentArray<T>& pa, int first, int last)\n       \
    \ : pa(pa), first(first), last(last) {}\n};"
  dependsOn:
  - data-structure/persistent_array.hpp
  isVerificationFile: false
  path: data-structure/persistent_queue.hpp
  requiredBy: []
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
documentation_of: data-structure/persistent_queue.hpp
layout: document
title: Persistent Queue
---

## Description

永続キューは，過去のバージョンを保持するキューである．この実装では内部で永続配列を用いている．

空間計算量: $O(m \log n)$, $m$ は変更の数

## Operations

- `int size()`
    - キューの要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 時間計算量: $O(1)$
- `T front()`
    - 先頭の要素を返す
    - 時間計算量: $O(1)$
- `T back()`
    - 末尾の要素を返す
    - 時間計算量: $O(1)$
- `PersistentQueue push(T val)`
    - `val` をキューの末尾に追加する
    - 時間計算量: $O(\log n)$
- `PersistentQueue pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $O(1)$