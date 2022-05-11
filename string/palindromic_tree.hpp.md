---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2292.test.cpp
    title: test/aoj/2292.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/palindromic_tree.hpp\"\n#include <map>\n#include\
    \ <string>\n#include <vector>\n\nclass PalindromicTree {\npublic:\n    PalindromicTree()\
    \ : nodes(2) {\n        nodes[0] = Node(-1, -1, 0);  // root for odd length palindromes\n\
    \        nodes[1] = Node(0, -1, 0);   // root for even length palindromes\n  \
    \      nodes[1].suffix_link = 0;\n        suff = 0;\n    }\n\n    explicit PalindromicTree(const\
    \ std::string& s) : PalindromicTree() {\n        for (char c : s) add(c);\n  \
    \  }\n\n    void add(char c) {\n        str.push_back(c);\n\n        //  find\
    \ a palidrome cAc\n        int k = find_next_palindrome(suff);\n\n        // the\
    \ palindrome already exists\n        if (nodes[k].link.count(c)) {\n         \
    \   ++nodes[nodes[k].link[c]].cnt;\n            suff = nodes[k].link[c];\n   \
    \         return;\n        }\n\n        // create a new node\n        nodes[k].link[c]\
    \ = nodes.size();\n        suff = nodes.size();\n        nodes.emplace_back(nodes[k].len\
    \ + 2, (int) str.size() - nodes[k].len - 2, 1);\n\n        // add a suffix link\n\
    \        if (nodes.back().len == 1) {\n            nodes.back().suffix_link =\
    \ 1;\n        } else {\n            const int n = find_next_palindrome(nodes[k].suffix_link);\n\
    \            nodes.back().suffix_link = nodes[n].link[c];\n        }\n    }\n\n\
    \    std::vector<int> get_suffix_palindromes() const {\n        std::vector<int>\
    \ ret;\n        int k = suff;\n        while (nodes[k].len > 0) {\n          \
    \  ret.push_back(nodes[k].len);\n            k = nodes[k].suffix_link;\n     \
    \   }\n        return ret;\n    }\n\n    // returns {length, one of the starting\
    \ indices, count}\n    std::vector<std::tuple<int, int, int>> get_palindrome_frequencies()\
    \ {\n        std::vector<std::tuple<int, int, int>> ret;\n        for (int i =\
    \ (int) nodes.size() - 1; i > 1; --i) {\n            ret.emplace_back(nodes[i].len,\
    \ nodes[i].idx, nodes[i].cnt);\n            nodes[nodes[i].suffix_link].cnt +=\
    \ nodes[i].cnt;\n        }\n        return ret;\n    }\n\nprivate:\n    struct\
    \ Node {\n        std::map<char, int> link;\n        int suffix_link;\n      \
    \  int len, idx, cnt;\n\n        Node() = default;\n        Node(int len, int\
    \ idx, int cnt) : len(len), idx(idx), cnt(cnt) {}\n    };\n\n    std::vector<Node>\
    \ nodes;\n    int suff;\n    std::string str;\n\n    int find_next_palindrome(int\
    \ k) const {\n        const int pos = str.size() - 1;\n        while (true) {\n\
    \            int i = pos - 1 - nodes[k].len;\n            if (i >= 0 && str[i]\
    \ == str[pos]) break;\n            k = nodes[k].suffix_link;\n        }\n    \
    \    return k;\n    }\n};\n"
  code: "#pragma once\n#include <map>\n#include <string>\n#include <vector>\n\nclass\
    \ PalindromicTree {\npublic:\n    PalindromicTree() : nodes(2) {\n        nodes[0]\
    \ = Node(-1, -1, 0);  // root for odd length palindromes\n        nodes[1] = Node(0,\
    \ -1, 0);   // root for even length palindromes\n        nodes[1].suffix_link\
    \ = 0;\n        suff = 0;\n    }\n\n    explicit PalindromicTree(const std::string&\
    \ s) : PalindromicTree() {\n        for (char c : s) add(c);\n    }\n\n    void\
    \ add(char c) {\n        str.push_back(c);\n\n        //  find a palidrome cAc\n\
    \        int k = find_next_palindrome(suff);\n\n        // the palindrome already\
    \ exists\n        if (nodes[k].link.count(c)) {\n            ++nodes[nodes[k].link[c]].cnt;\n\
    \            suff = nodes[k].link[c];\n            return;\n        }\n\n    \
    \    // create a new node\n        nodes[k].link[c] = nodes.size();\n        suff\
    \ = nodes.size();\n        nodes.emplace_back(nodes[k].len + 2, (int) str.size()\
    \ - nodes[k].len - 2, 1);\n\n        // add a suffix link\n        if (nodes.back().len\
    \ == 1) {\n            nodes.back().suffix_link = 1;\n        } else {\n     \
    \       const int n = find_next_palindrome(nodes[k].suffix_link);\n          \
    \  nodes.back().suffix_link = nodes[n].link[c];\n        }\n    }\n\n    std::vector<int>\
    \ get_suffix_palindromes() const {\n        std::vector<int> ret;\n        int\
    \ k = suff;\n        while (nodes[k].len > 0) {\n            ret.push_back(nodes[k].len);\n\
    \            k = nodes[k].suffix_link;\n        }\n        return ret;\n    }\n\
    \n    // returns {length, one of the starting indices, count}\n    std::vector<std::tuple<int,\
    \ int, int>> get_palindrome_frequencies() {\n        std::vector<std::tuple<int,\
    \ int, int>> ret;\n        for (int i = (int) nodes.size() - 1; i > 1; --i) {\n\
    \            ret.emplace_back(nodes[i].len, nodes[i].idx, nodes[i].cnt);\n   \
    \         nodes[nodes[i].suffix_link].cnt += nodes[i].cnt;\n        }\n      \
    \  return ret;\n    }\n\nprivate:\n    struct Node {\n        std::map<char, int>\
    \ link;\n        int suffix_link;\n        int len, idx, cnt;\n\n        Node()\
    \ = default;\n        Node(int len, int idx, int cnt) : len(len), idx(idx), cnt(cnt)\
    \ {}\n    };\n\n    std::vector<Node> nodes;\n    int suff;\n    std::string str;\n\
    \n    int find_next_palindrome(int k) const {\n        const int pos = str.size()\
    \ - 1;\n        while (true) {\n            int i = pos - 1 - nodes[k].len;\n\
    \            if (i >= 0 && str[i] == str[pos]) break;\n            k = nodes[k].suffix_link;\n\
    \        }\n        return k;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromic_tree.hpp
  requiredBy: []
  timestamp: '2022-05-11 13:44:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2292.test.cpp
documentation_of: string/palindromic_tree.hpp
layout: document
title: Palindromic Tree
---

## Description

Palindromic Tree は，文字列の回文の情報を保持するデータ構造である．

## Operations

- `void add(char c)`
    - 文字 $c$ を現在の文字列の末尾に追加する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `vector<int> get_suffix_palindromes()`
    - 現在の文字列の suffix である回文の長さを列挙する
    - 時間計算量: $O(k)$, $k$ は回文の個数
- `vector<tuple<int, int, int>> get_palindrome_frequencies()`
    - 文字列の相異なる回文部分文字列の位置と長さと個数を列挙する．破壊的．
    - 時間計算量: $O(n)$

## Reference

- [Palindromic Tree - slideshare](https://www.slideshare.net/__math/palindromic-tree)


