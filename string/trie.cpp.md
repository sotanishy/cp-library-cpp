---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/trie.cpp\"\n#include <bits/stdc++.h>\n\nclass Trie\
    \ {\npublic:\n    Trie() : nodes(1) {}\n\n    void add(const std::string& s, int\
    \ id) {\n        int node = 0;\n        for (char c : s) {\n            if (nodes[node].child[c\
    \ - 'a'] == -1) {\n                nodes[node].child[c - 'a'] = nodes.size();\n\
    \                nodes.emplace_back();\n            }\n            ++nodes[node].count;\n\
    \            node = nodes[node].child[c - 'a'];\n        }\n        nodes[node].is_end\
    \ = true;\n    }\n\n    int query(const std::string& s) const {\n        int node\
    \ = 0;\n        for (char c : s) {\n            if (nodes[node].child[c - 'a']\
    \ == -1) return 0;\n            node = nodes[node].child[c - 'a'];\n        }\n\
    \        return nodes[node].count;\n    }\n\nprivate:\n    struct Node {\n   \
    \     std::vector<int> child;\n        bool is_end = false;\n        int count\
    \ = 0;\n\n        Node() : child(26, -1) {}\n    };\n\n    std::vector<Node> nodes;\n\
    };\n"
  code: "#include <bits/stdc++.h>\n\nclass Trie {\npublic:\n    Trie() : nodes(1)\
    \ {}\n\n    void add(const std::string& s, int id) {\n        int node = 0;\n\
    \        for (char c : s) {\n            if (nodes[node].child[c - 'a'] == -1)\
    \ {\n                nodes[node].child[c - 'a'] = nodes.size();\n            \
    \    nodes.emplace_back();\n            }\n            ++nodes[node].count;\n\
    \            node = nodes[node].child[c - 'a'];\n        }\n        nodes[node].is_end\
    \ = true;\n    }\n\n    int query(const std::string& s) const {\n        int node\
    \ = 0;\n        for (char c : s) {\n            if (nodes[node].child[c - 'a']\
    \ == -1) return 0;\n            node = nodes[node].child[c - 'a'];\n        }\n\
    \        return nodes[node].count;\n    }\n\nprivate:\n    struct Node {\n   \
    \     std::vector<int> child;\n        bool is_end = false;\n        int count\
    \ = 0;\n\n        Node() : child(26, -1) {}\n    };\n\n    std::vector<Node> nodes;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.cpp
layout: document
redirect_from:
- /library/string/trie.cpp
- /library/string/trie.cpp.html
title: string/trie.cpp
---
