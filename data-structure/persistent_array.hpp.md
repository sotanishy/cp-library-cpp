---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_queue.hpp
    title: Persistent Queue
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/persistent_union_find.hpp
    title: Persistent Union Find
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent_array.hpp\"\n#include <memory>\n\
    #include <vector>\n\ntemplate <typename T, int B = 2>\nclass PersistentArray {\n\
    \   public:\n    PersistentArray() = default;\n    explicit PersistentArray(const\
    \ std::vector<T>& v) {\n        for (int i = 0; i < (int)v.size(); ++i) root =\
    \ set(root, i, v[i]);\n    }\n\n    T get(int k) const { return get(root, k);\
    \ }\n\n    PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\n   private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[B];\n    };\n\n    node_ptr\
    \ root = nullptr;\n\n    explicit PersistentArray(const node_ptr& root) : root(root)\
    \ {}\n\n    T get(const node_ptr& t, int k) const {\n        if (k == 0) return\
    \ t->val;\n        return get(t->ch[k % B], k / B);\n    }\n\n    node_ptr set(const\
    \ node_ptr& t, int k, const T& x) const {\n        node_ptr res =\n          \
    \  t ? std::make_shared<Node>(*t) : std::make_shared<Node>();\n        if (k ==\
    \ 0) {\n            res->val = x;\n        } else {\n            res->ch[k % B]\
    \ = set(res->ch[k % B], k / B, x);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n\ntemplate <typename\
    \ T, int B = 2>\nclass PersistentArray {\n   public:\n    PersistentArray() =\
    \ default;\n    explicit PersistentArray(const std::vector<T>& v) {\n        for\
    \ (int i = 0; i < (int)v.size(); ++i) root = set(root, i, v[i]);\n    }\n\n  \
    \  T get(int k) const { return get(root, k); }\n\n    PersistentArray set(int\
    \ k, const T& x) const {\n        return PersistentArray(set(root, k, x));\n \
    \   }\n\n   private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[B];\n    };\n\n    node_ptr\
    \ root = nullptr;\n\n    explicit PersistentArray(const node_ptr& root) : root(root)\
    \ {}\n\n    T get(const node_ptr& t, int k) const {\n        if (k == 0) return\
    \ t->val;\n        return get(t->ch[k % B], k / B);\n    }\n\n    node_ptr set(const\
    \ node_ptr& t, int k, const T& x) const {\n        node_ptr res =\n          \
    \  t ? std::make_shared<Node>(*t) : std::make_shared<Node>();\n        if (k ==\
    \ 0) {\n            res->val = x;\n        } else {\n            res->ch[k % B]\
    \ = set(res->ch[k % B], k / B, x);\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent_array.hpp
  requiredBy:
  - data-structure/unionfind/persistent_union_find.hpp
  - data-structure/persistent_queue.hpp
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: data-structure/persistent_array.hpp
layout: document
title: Persistent Array
---

## Description

永続配列は，過去のバージョンを保持する配列である．永続配列の要素を変更したとき，変更された値を保持する新しい配列を生成する．

空間計算量: $O(m b \log_b n)$, $m$ は変更の数

## Operations

- `PersistentArray(vector<T> v)`
    - `v` の要素から永続配列を構築する
    - 時間計算量: $O(nb \log_b n)$
- `T get(int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log_b n)$
- `PersistentArray set(int k, T x)`
    - $k$ 番目の要素を $x$ に変更した永続配列を返す
    - 時間計算量: $O(b \log_b n)$

## Reference

- [ゼロから作る永続データ構造](https://qiita.com/wotsushi/items/72e7f8cdd674741ffd61)