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
    \ <vector>\n\n/*\n * @brief Binary Trie\n * @docs docs/data-structure/binary_trie.md\n\
    \ */\ntemplate <typename T, int B = 32>\nclass BinaryTrie {\npublic:\n    BinaryTrie()\
    \ : node(1) {}\n\n    int size() const {\n        return node[0].count;\n    }\n\
    \n    bool empty() const {\n        return size() == 0;\n    }\n\n    int count(T\
    \ x) const {\n        int t = 0;\n        for (int i = B - 1; i >= 0; --i) {\n\
    \            bool b = x >> i & 1;\n            if (node[t].ch[b] == -1) return\
    \ 0;\n            t = node[t].ch[b];\n        }\n        return node[t].count;\n\
    \    }\n\n    void insert(T x) {\n        int t = 0;\n        for (int i = B -\
    \ 1; i >= 0; --i) {\n            bool b = x >> i & 1;\n            if (node[t].ch[b]\
    \ == -1) {\n                node[t].ch[b] = node.size();\n                node.emplace_back();\n\
    \            }\n            ++node[t].count;\n            t = node[t].ch[b];\n\
    \        }\n        ++node[t].count;\n    }\n\n    void erase(T x) {\n       \
    \ if (!count(x)) return;\n        int t = 0;\n        for (int i = B - 1; i >=\
    \ 0; --i) {\n            --node[t].count;\n            t = node[t].ch[x >> i &\
    \ 1];\n        }\n        --node[t].count;\n    }\n\n    T min_element(T x = 0)\
    \ const {\n        assert(size());\n        int t = 0;\n        T ret = 0;\n \
    \       for (int i = B - 1; i >= 0; --i) {\n            bool b = x >> i & 1;\n\
    \            int c = node[t].ch[b];\n            if (c != -1 && node[c].count\
    \ > 0) {\n                t = c;\n            } else {\n                t = node[t].ch[1\
    \ - b];\n                ret |= T(1) << i;\n            }\n        }\n       \
    \ return ret;\n    }\n\n    T max_element(T x = 0) const {\n        assert(size());\n\
    \        int t = 0;\n        T ret = 0;\n        for (int i = B - 1; i >= 0; --i)\
    \ {\n            bool b = x >> i & 1;\n            int c = node[t].ch[1 - b];\n\
    \            if (c != -1 && node[c].count > 0) {\n                t = c;\n   \
    \             ret |= T(1) << i;\n            } else {\n                t = node[t].ch[b];\n\
    \            }\n        }\n        return ret;\n    }\n\nprivate:\n    struct\
    \ Node {\n        std::vector<int> ch;\n        int count;\n        Node() : ch(2,\
    \ -1), count(0) {}\n    };\n\n    std::vector<Node> node;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n/*\n * @brief Binary\
    \ Trie\n * @docs docs/data-structure/binary_trie.md\n */\ntemplate <typename T,\
    \ int B = 32>\nclass BinaryTrie {\npublic:\n    BinaryTrie() : node(1) {}\n\n\
    \    int size() const {\n        return node[0].count;\n    }\n\n    bool empty()\
    \ const {\n        return size() == 0;\n    }\n\n    int count(T x) const {\n\
    \        int t = 0;\n        for (int i = B - 1; i >= 0; --i) {\n            bool\
    \ b = x >> i & 1;\n            if (node[t].ch[b] == -1) return 0;\n          \
    \  t = node[t].ch[b];\n        }\n        return node[t].count;\n    }\n\n   \
    \ void insert(T x) {\n        int t = 0;\n        for (int i = B - 1; i >= 0;\
    \ --i) {\n            bool b = x >> i & 1;\n            if (node[t].ch[b] == -1)\
    \ {\n                node[t].ch[b] = node.size();\n                node.emplace_back();\n\
    \            }\n            ++node[t].count;\n            t = node[t].ch[b];\n\
    \        }\n        ++node[t].count;\n    }\n\n    void erase(T x) {\n       \
    \ if (!count(x)) return;\n        int t = 0;\n        for (int i = B - 1; i >=\
    \ 0; --i) {\n            --node[t].count;\n            t = node[t].ch[x >> i &\
    \ 1];\n        }\n        --node[t].count;\n    }\n\n    T min_element(T x = 0)\
    \ const {\n        assert(size());\n        int t = 0;\n        T ret = 0;\n \
    \       for (int i = B - 1; i >= 0; --i) {\n            bool b = x >> i & 1;\n\
    \            int c = node[t].ch[b];\n            if (c != -1 && node[c].count\
    \ > 0) {\n                t = c;\n            } else {\n                t = node[t].ch[1\
    \ - b];\n                ret |= T(1) << i;\n            }\n        }\n       \
    \ return ret;\n    }\n\n    T max_element(T x = 0) const {\n        assert(size());\n\
    \        int t = 0;\n        T ret = 0;\n        for (int i = B - 1; i >= 0; --i)\
    \ {\n            bool b = x >> i & 1;\n            int c = node[t].ch[1 - b];\n\
    \            if (c != -1 && node[c].count > 0) {\n                t = c;\n   \
    \             ret |= T(1) << i;\n            } else {\n                t = node[t].ch[b];\n\
    \            }\n        }\n        return ret;\n    }\n\nprivate:\n    struct\
    \ Node {\n        std::vector<int> ch;\n        int count;\n        Node() : ch(2,\
    \ -1), count(0) {}\n    };\n\n    std::vector<Node> node;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary_trie.cpp
  requiredBy: []
  timestamp: '2020-10-26 22:28:07+09:00'
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
# Binary Trie

Binary trie は，正整数の多重集合を扱うデータ構造である．

空間計算量: $O(n)$

## Template parameter

- `T`
    - 要素の型
- `B`
    - 要素の bit 数．デフォルトは32

## Member functions

- `int size()`
    - 集合の大きさを返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 集合が空か判定する
    - 時間計算量: $O(1)$
- `int count(T x)`
    - 集合内の $x$ の数を返す
    - 時間計算量: $O(B)$
- `void insert(T x)`
    - $x$ を集合に追加する．
    - 時間計算量: $O(B)$
- `void erase(T x)`
    - $x$ が存在すればそれを1つ集合から取り除く
    - 時間計算量: $O(B)$
- `T min_element(T x)`
    - 集合全体を $\oplus x$ した時の最小値を返す
    - 時間計算量: $O(B)$
- `T max_element(T x)`
    - 集合全体を $\oplus x$ した時の最大値を返す
    - 時間計算量: $O(B)$
