---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_union_find.cpp
    title: Persistent Union Find
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/persistent_array.md
    document_title: Persistent Array
    links: []
  bundledCode: "#line 1 \"data-structure/persistent_array.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
    \ */\ntemplate <typename T, int B = 2>\nclass PersistentArray {\npublic:\n   \
    \ PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const {\n        return get(root, k);\n    }\n\n  \
    \  PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\nprivate:\n    struct Node {\n        T val;\n        std::vector<std::shared_ptr<Node>>\
    \ ch;\n        Node() : ch(B) {}\n    };\n\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    node_ptr root = nullptr;\n\n    explicit PersistentArray(const node_ptr&\
    \ root) : root(root) {}\n\n    T get(const node_ptr& t, int k) const {\n     \
    \   if (k == 0) return t->val;\n        return get(t->ch[k % B], k / B);\n   \
    \ }\n\n    node_ptr set(const node_ptr& t, int k, const T& x) const {\n      \
    \  node_ptr res = t ? std::make_shared<Node>(*t) : std::make_shared<Node>();\n\
    \        if (k == 0) {\n            res->val = x;\n        } else {\n        \
    \    res->ch[k % B] = set(res->ch[k % B], k / B, x);\n        }\n        return\
    \ res;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
    \ */\ntemplate <typename T, int B = 2>\nclass PersistentArray {\npublic:\n   \
    \ PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const {\n        return get(root, k);\n    }\n\n  \
    \  PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\nprivate:\n    struct Node {\n        T val;\n        std::vector<std::shared_ptr<Node>>\
    \ ch;\n        Node() : ch(B) {}\n    };\n\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    node_ptr root = nullptr;\n\n    explicit PersistentArray(const node_ptr&\
    \ root) : root(root) {}\n\n    T get(const node_ptr& t, int k) const {\n     \
    \   if (k == 0) return t->val;\n        return get(t->ch[k % B], k / B);\n   \
    \ }\n\n    node_ptr set(const node_ptr& t, int k, const T& x) const {\n      \
    \  node_ptr res = t ? std::make_shared<Node>(*t) : std::make_shared<Node>();\n\
    \        if (k == 0) {\n            res->val = x;\n        } else {\n        \
    \    res->ch[k % B] = set(res->ch[k % B], k / B, x);\n        }\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent_array.cpp
  requiredBy:
  - data-structure/persistent_union_find.cpp
  timestamp: '2020-10-08 11:27:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: data-structure/persistent_array.cpp
layout: document
redirect_from:
- /library/data-structure/persistent_array.cpp
- /library/data-structure/persistent_array.cpp.html
title: Persistent Array
---
# Persistent Array

永続配列は，過去のバージョンを保持する配列である．永続配列の要素を変更したとき，変更された値を保持する新しい配列を生成する．これによって非破壊的な操作を提供する．

空間計算量: $O(n + m B \log_B n)$, $m$ は変更の数

## Template parameter

- `T`
    - 要素の型
- `B`
    - 子ノードの数．デフォルトは `2`

## Constructor

- `PersistentArray(vector<T> v)`
    - `v` の要素から永続配列を構築する
    - 時間計算量: $O(nB \log_B n)$

## Member functions

- `T get(int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log_B n)$
- `PersistentArray set(int k, T x)`
    - $k$ 番目の要素を $x$ に変更した永続配列を返す
    - 時間計算量: $O(B \log_B n)$
