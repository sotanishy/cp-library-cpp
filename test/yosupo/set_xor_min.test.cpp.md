---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary_trie.cpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#line 2 \"data-structure/binary_trie.cpp\"\n#include <cassert>\n#include <vector>\n\
    \n/*\n * @brief Binary Trie\n * @docs docs/data-structure/binary_trie.md\n */\n\
    template <typename T, int B = 32>\nclass BinaryTrie {\npublic:\n    BinaryTrie()\
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
    \ -1), count(0) {}\n    };\n\n    std::vector<Node> node;\n};\n#line 4 \"test/yosupo/set_xor_min.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    BinaryTrie<int> bt;\n    int Q;\n    cin >> Q;\n    while (Q--) {\n     \
    \   int t, x;\n        cin >> t >> x;\n        if (t == 0) {\n            if (!bt.count(x))\
    \ bt.insert(x);\n        }\n        if (t == 1) {\n            bt.erase(x);\n\
    \        }\n        if (t == 2) {\n            cout << bt.min_element(x) << \"\
    \\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../data-structure/binary_trie.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    BinaryTrie<int> bt;\n    int Q;\n    cin >> Q;\n\
    \    while (Q--) {\n        int t, x;\n        cin >> t >> x;\n        if (t ==\
    \ 0) {\n            if (!bt.count(x)) bt.insert(x);\n        }\n        if (t\
    \ == 1) {\n            bt.erase(x);\n        }\n        if (t == 2) {\n      \
    \      cout << bt.min_element(x) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/binary_trie.cpp
  isVerificationFile: true
  path: test/yosupo/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2020-10-26 22:28:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/set_xor_min.test.cpp
- /verify/test/yosupo/set_xor_min.test.cpp.html
title: test/yosupo/set_xor_min.test.cpp
---
