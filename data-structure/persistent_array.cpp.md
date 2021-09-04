---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_queue.cpp
    title: Persistent Queue
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/persistent_union_find.cpp
    title: Persistent Union Find
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/persistent_array.md
    document_title: Persistent Array
    links: []
  bundledCode: "#line 2 \"data-structure/persistent_array.cpp\"\n#include <memory>\n\
    #include <vector>\n\n/*\n * @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
    \ */\ntemplate <typename T, int B = 2>\nclass PersistentArray {\npublic:\n   \
    \ PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const {\n        return get(root, k);\n    }\n\n  \
    \  PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[B];\n    };\n\n    node_ptr\
    \ root = nullptr;\n\n    explicit PersistentArray(const node_ptr& root) : root(root)\
    \ {}\n\n    T get(const node_ptr& t, int k) const {\n        if (k == 0) return\
    \ t->val;\n        return get(t->ch[k % B], k / B);\n    }\n\n    node_ptr set(const\
    \ node_ptr& t, int k, const T& x) const {\n        node_ptr res = t ? std::make_shared<Node>(*t)\
    \ : std::make_shared<Node>();\n        if (k == 0) {\n            res->val = x;\n\
    \        } else {\n            res->ch[k % B] = set(res->ch[k % B], k / B, x);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n\n/*\n * @brief Persistent\
    \ Array\n * @docs docs/data-structure/persistent_array.md\n */\ntemplate <typename\
    \ T, int B = 2>\nclass PersistentArray {\npublic:\n    PersistentArray() = default;\n\
    \    explicit PersistentArray(const std::vector<T>& v) {\n        for (int i =\
    \ 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n    }\n\n    T get(int\
    \ k) const {\n        return get(root, k);\n    }\n\n    PersistentArray set(int\
    \ k, const T& x) const {\n        return PersistentArray(set(root, k, x));\n \
    \   }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[B];\n    };\n\n    node_ptr\
    \ root = nullptr;\n\n    explicit PersistentArray(const node_ptr& root) : root(root)\
    \ {}\n\n    T get(const node_ptr& t, int k) const {\n        if (k == 0) return\
    \ t->val;\n        return get(t->ch[k % B], k / B);\n    }\n\n    node_ptr set(const\
    \ node_ptr& t, int k, const T& x) const {\n        node_ptr res = t ? std::make_shared<Node>(*t)\
    \ : std::make_shared<Node>();\n        if (k == 0) {\n            res->val = x;\n\
    \        } else {\n            res->ch[k % B] = set(res->ch[k % B], k / B, x);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent_array.cpp
  requiredBy:
  - data-structure/unionfind/persistent_union_find.cpp
  - data-structure/persistent_queue.cpp
  timestamp: '2020-11-03 02:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
  - test/yosupo/persistent_queue.test.cpp
documentation_of: data-structure/persistent_array.cpp
layout: document
redirect_from:
- /library/data-structure/persistent_array.cpp
- /library/data-structure/persistent_array.cpp.html
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

## TODO

- $O(\log \log n)$ 時間の永続配列の実装 [http://web.mit.edu/andersk/Public/6.851-presentation.pdf]()