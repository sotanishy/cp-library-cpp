---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/binary_trie.md
    document_title: Binary Trie
    links: []
  bundledCode: "#line 2 \"data-structure/binary_trie.cpp\"\n#include <cassert>\n#include\
    \ <memory>\n\n/*\n * @brief Binary Trie\n * @docs docs/data-structure/binary_trie.md\n\
    \ */\ntemplate <typename T, int B = 32>\nclass BinaryTrie {\npublic:\n    BinaryTrie()\
    \ : root(std::make_unique<Node>()) {}\n\n    int size() const {\n        return\
    \ root->count;\n    }\n\n    bool empty() const {\n        return size() == 0;\n\
    \    }\n\n    int count(T x) const {\n        return count(root, x, B - 1);\n\
    \    }\n\n    int count_less(T x, T xor_val = 0) const {\n        return count_less(root,\
    \ x, xor_val, B - 1);\n    }\n\n    void insert(T x) {\n        insert(root, x,\
    \ B - 1);\n    }\n\n    void erase(T x) {\n        erase(root, x, B - 1);\n  \
    \  }\n\n    T min_element(T xor_val = 0) const {\n        assert(!empty());\n\
    \        return min_element(root, xor_val, B - 1);\n    }\n\n    T max_element(T\
    \ xor_val = 0) const {\n        assert(!empty());\n        return max_element(root,\
    \ xor_val, B - 1);\n    }\n\nprivate:\n    struct Node;\n    using node_ptr =\
    \ std::unique_ptr<Node>;\n\n    struct Node {\n        node_ptr ch[2];\n     \
    \   int count = 0;\n    };\n\n    const node_ptr root;\n\n    int count(const\
    \ node_ptr& t, T x, int k) const {\n        if (k == -1) return t->count;\n  \
    \      bool b = x >> k & 1;\n        return t->ch[b] ? count(t->ch[b], x, k -\
    \ 1) : 0;\n    }\n\n    int count_less(const node_ptr& t, T x, T xor_val, int\
    \ k) const {\n        if (k == -1) return 0;\n        bool b = x >> k & 1;\n \
    \       bool f = xor_val >> k & 1;\n        int ret = 0;\n        if (f ^ b) {\n\
    \            if (t->ch[f]) ret += t->ch[f]->count;\n            if (t->ch[1 -\
    \ f]) ret += count_less(t->ch[1 - f], x, xor_val, k - 1);\n        } else {\n\
    \            if (t->ch[f]) ret += count_less(t->ch[f], x, xor_val, k - 1);\n \
    \       }\n        return ret;\n    }\n\n    void insert(const node_ptr& t, T\
    \ x, int k) {\n        if (k == -1) {\n            ++t->count;\n            return;\n\
    \        }\n        bool b = x >> k & 1;\n        if (!t->ch[b]) t->ch[b] = std::make_unique<Node>();\n\
    \        ++t->count;\n        insert(t->ch[b], x, k - 1);\n    }\n\n    void erase(const\
    \ node_ptr& t, T x, int k) {\n        if (k == -1) {\n            --t->count;\n\
    \            return;\n        }\n        --t->count;\n        erase(t->ch[x >>\
    \ k & 1], x, k - 1);\n    }\n\n    T min_element(const node_ptr& t, T xor_val,\
    \ int k) const {\n        if (k == -1) return 0;\n        bool b = xor_val >>\
    \ k & 1;\n        T ret = 0;\n        if (t->ch[b] && t->ch[b]->count > 0) {\n\
    \            ret += min_element(t->ch[b], xor_val, k - 1);\n        } else {\n\
    \            ret += T(1) << k;\n            ret += min_element(t->ch[1 - b], xor_val,\
    \ k - 1);\n        }\n        return ret;\n    }\n\n    T max_element(const node_ptr&\
    \ t, T xor_val, int k) const {\n        if (k == -1) return 0;\n        bool b\
    \ = xor_val >> k & 1;\n        T ret = 0;\n        if (t->ch[1 - b] && t->ch[1\
    \ - b].count > 0) {\n            ret += T(1) << k;\n            ret += max_element(t->ch[1\
    \ - b], xor_val, k - 1);\n        } else {\n            ret += max_element(t->ch[b],\
    \ xor_val, k - 1);\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n\n/*\n * @brief Binary\
    \ Trie\n * @docs docs/data-structure/binary_trie.md\n */\ntemplate <typename T,\
    \ int B = 32>\nclass BinaryTrie {\npublic:\n    BinaryTrie() : root(std::make_unique<Node>())\
    \ {}\n\n    int size() const {\n        return root->count;\n    }\n\n    bool\
    \ empty() const {\n        return size() == 0;\n    }\n\n    int count(T x) const\
    \ {\n        return count(root, x, B - 1);\n    }\n\n    int count_less(T x, T\
    \ xor_val = 0) const {\n        return count_less(root, x, xor_val, B - 1);\n\
    \    }\n\n    void insert(T x) {\n        insert(root, x, B - 1);\n    }\n\n \
    \   void erase(T x) {\n        erase(root, x, B - 1);\n    }\n\n    T min_element(T\
    \ xor_val = 0) const {\n        assert(!empty());\n        return min_element(root,\
    \ xor_val, B - 1);\n    }\n\n    T max_element(T xor_val = 0) const {\n      \
    \  assert(!empty());\n        return max_element(root, xor_val, B - 1);\n    }\n\
    \nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n\
    \    struct Node {\n        node_ptr ch[2];\n        int count = 0;\n    };\n\n\
    \    const node_ptr root;\n\n    int count(const node_ptr& t, T x, int k) const\
    \ {\n        if (k == -1) return t->count;\n        bool b = x >> k & 1;\n   \
    \     return t->ch[b] ? count(t->ch[b], x, k - 1) : 0;\n    }\n\n    int count_less(const\
    \ node_ptr& t, T x, T xor_val, int k) const {\n        if (k == -1) return 0;\n\
    \        bool b = x >> k & 1;\n        bool f = xor_val >> k & 1;\n        int\
    \ ret = 0;\n        if (f ^ b) {\n            if (t->ch[f]) ret += t->ch[f]->count;\n\
    \            if (t->ch[1 - f]) ret += count_less(t->ch[1 - f], x, xor_val, k -\
    \ 1);\n        } else {\n            if (t->ch[f]) ret += count_less(t->ch[f],\
    \ x, xor_val, k - 1);\n        }\n        return ret;\n    }\n\n    void insert(const\
    \ node_ptr& t, T x, int k) {\n        if (k == -1) {\n            ++t->count;\n\
    \            return;\n        }\n        bool b = x >> k & 1;\n        if (!t->ch[b])\
    \ t->ch[b] = std::make_unique<Node>();\n        ++t->count;\n        insert(t->ch[b],\
    \ x, k - 1);\n    }\n\n    void erase(const node_ptr& t, T x, int k) {\n     \
    \   if (k == -1) {\n            --t->count;\n            return;\n        }\n\
    \        --t->count;\n        erase(t->ch[x >> k & 1], x, k - 1);\n    }\n\n \
    \   T min_element(const node_ptr& t, T xor_val, int k) const {\n        if (k\
    \ == -1) return 0;\n        bool b = xor_val >> k & 1;\n        T ret = 0;\n \
    \       if (t->ch[b] && t->ch[b]->count > 0) {\n            ret += min_element(t->ch[b],\
    \ xor_val, k - 1);\n        } else {\n            ret += T(1) << k;\n        \
    \    ret += min_element(t->ch[1 - b], xor_val, k - 1);\n        }\n        return\
    \ ret;\n    }\n\n    T max_element(const node_ptr& t, T xor_val, int k) const\
    \ {\n        if (k == -1) return 0;\n        bool b = xor_val >> k & 1;\n    \
    \    T ret = 0;\n        if (t->ch[1 - b] && t->ch[1 - b].count > 0) {\n     \
    \       ret += T(1) << k;\n            ret += max_element(t->ch[1 - b], xor_val,\
    \ k - 1);\n        } else {\n            ret += max_element(t->ch[b], xor_val,\
    \ k - 1);\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary_trie.cpp
  requiredBy: []
  timestamp: '2021-01-11 09:27:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: data-structure/binary_trie.cpp
layout: document
redirect_from:
- /library/data-structure/binary_trie.cpp
- /library/data-structure/binary_trie.cpp.html
title: Binary Trie
---
## Description

二分トライ木 (binary trie) は，非負整数の多重集合を扱うデータ構造である．整数をビット列とみなしてトライ木に格納する．平衡二分木による多重集合の実装よりも実装が簡単であるほか，要素全体をある値で xor した時の最大/最小値を求めるなどの操作が可能である．

`xor_val` を指定すると，集合全体を `xor_val` で xor したとして振舞う．

空間計算量: $O(nb)$

## Operations

- `int size()`
    - 集合の大きさを返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 集合が空か判定する
    - 時間計算量: $O(1)$
- `int count(T x)`
    - 集合内の $x$ の数を返す
    - 時間計算量: $O(b)$
- `int count_less(T x, T xor_val = 0)`
    - 集合内の $x$ より小さい要素の数を返す
    - 時間計算量: $O(b)$
- `void insert(T x)`
    - $x$ を集合に追加する．
    - 時間計算量: $O(b)$
- `void erase(T x)`
    - $x$ が存在すればそれを1つ集合から取り除く
    - 時間計算量: $O(b)$
- `T min_element(T xor_val = 0)`
    - 集合の最小値を返す
    - 時間計算量: $O(b)$
- `T max_element(T xor_val = 0)`
    - 集合の最大値を返す
    - 時間計算量: $O(b)$

## Reference

- [非負整数値を扱う Trie について](https://kazuma8128.hatenablog.com/entry/2018/05/06/022654)
- [binaryTrie: A digital search tree](http://opendatastructures.org/ods-java/13_1_binaryTrie_digital_sea.html)

## TODO

- `lower_bound`, `upper_bound`, `kth_element` の実装
- jump ポインタによる高速化
- 遅延評価
- 永続化