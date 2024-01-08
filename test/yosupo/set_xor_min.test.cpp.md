---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary_trie.hpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#include <bits/stdc++.h>\n\n#line 4 \"data-structure/binary_trie.hpp\"\n\n\
    template <typename T, int B = 32>\nclass BinaryTrie {\n   public:\n    BinaryTrie()\
    \ : root(std::make_unique<Node>()) {}\n\n    int size() const { return root->count;\
    \ }\n\n    bool empty() const { return size() == 0; }\n\n    int count(T x) const\
    \ { return count(root, x, B - 1); }\n\n    int count_less(T x, T xor_val = 0)\
    \ const {\n        return count_less(root, x, xor_val, B - 1);\n    }\n\n    void\
    \ insert(T x) { insert(root, x, B - 1); }\n\n    void erase(T x) { erase(root,\
    \ x, B - 1); }\n\n    T min_element(T xor_val = 0) const {\n        assert(!empty());\n\
    \        return min_element(root, xor_val, B - 1);\n    }\n\n    T max_element(T\
    \ xor_val = 0) const {\n        assert(!empty());\n        return max_element(root,\
    \ xor_val, B - 1);\n    }\n\n   private:\n    struct Node;\n    using node_ptr\
    \ = std::unique_ptr<Node>;\n\n    struct Node {\n        node_ptr ch[2];\n   \
    \     int count = 0;\n    };\n\n    const node_ptr root;\n\n    int count(const\
    \ node_ptr& t, T x, int k) const {\n        if (k == -1) return t->count;\n  \
    \      bool b = x >> k & 1;\n        return t->ch[b] ? count(t->ch[b], x, k -\
    \ 1) : 0;\n    }\n\n    int count_less(const node_ptr& t, T x, T xor_val, int\
    \ k) const {\n        if (k == -1) return 0;\n        bool b = x >> k & 1;\n \
    \       bool f = xor_val >> k & 1;\n        int ret = 0;\n        if (f ^ b) {\n\
    \            if (t->ch[f]) ret += t->ch[f]->count;\n            if (t->ch[1 -\
    \ f])\n                ret += count_less(t->ch[1 - f], x, xor_val, k - 1);\n \
    \       } else {\n            if (t->ch[f]) ret += count_less(t->ch[f], x, xor_val,\
    \ k - 1);\n        }\n        return ret;\n    }\n\n    void insert(const node_ptr&\
    \ t, T x, int k) {\n        if (k == -1) {\n            ++t->count;\n        \
    \    return;\n        }\n        bool b = x >> k & 1;\n        if (!t->ch[b])\
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
    \ k - 1);\n        }\n        return ret;\n    }\n};\n#line 6 \"test/yosupo/set_xor_min.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    BinaryTrie<int> bt;\n    int Q;\n    cin >> Q;\n\
    \    while (Q--) {\n        int t, x;\n        cin >> t >> x;\n        if (t ==\
    \ 0) {\n            if (!bt.count(x)) bt.insert(x);\n        }\n        if (t\
    \ == 1) {\n            if (bt.count(x)) bt.erase(x);\n        }\n        if (t\
    \ == 2) {\n            cout << bt.min_element(x) << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../data-structure/binary_trie.hpp\"\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    BinaryTrie<int> bt;\n    int Q;\n    cin >> Q;\n\
    \    while (Q--) {\n        int t, x;\n        cin >> t >> x;\n        if (t ==\
    \ 0) {\n            if (!bt.count(x)) bt.insert(x);\n        }\n        if (t\
    \ == 1) {\n            if (bt.count(x)) bt.erase(x);\n        }\n        if (t\
    \ == 2) {\n            cout << bt.min_element(x) << \"\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - data-structure/binary_trie.hpp
  isVerificationFile: true
  path: test/yosupo/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/set_xor_min.test.cpp
- /verify/test/yosupo/set_xor_min.test.cpp.html
title: test/yosupo/set_xor_min.test.cpp
---
