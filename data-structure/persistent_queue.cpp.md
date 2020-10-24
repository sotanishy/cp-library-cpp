---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.cpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent_queue.cpp\"\n#include <cassert>\n\
    #line 2 \"data-structure/persistent_array.cpp\"\n#include <memory>\n#include <vector>\n\
    \n/*\n * @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
    \ */\ntemplate <typename T, int B = 2>\nclass PersistentArray {\npublic:\n   \
    \ PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const {\n        return get(root, k);\n    }\n\n  \
    \  PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        std::vector<node_ptr> ch;\n     \
    \   Node() : ch(B) {}\n    };\n\n    node_ptr root = nullptr;\n\n    explicit\
    \ PersistentArray(const node_ptr& root) : root(root) {}\n\n    T get(const node_ptr&\
    \ t, int k) const {\n        if (k == 0) return t->val;\n        return get(t->ch[k\
    \ % B], k / B);\n    }\n\n    node_ptr set(const node_ptr& t, int k, const T&\
    \ x) const {\n        node_ptr res = t ? std::make_shared<Node>(*t) : std::make_shared<Node>();\n\
    \        if (k == 0) {\n            res->val = x;\n        } else {\n        \
    \    res->ch[k % B] = set(res->ch[k % B], k / B, x);\n        }\n        return\
    \ res;\n    }\n};\n#line 4 \"data-structure/persistent_queue.cpp\"\n\ntemplate\
    \ <typename T, int Cap = (int) 1e7>\nclass PersistentQueue {\npublic:\n    PersistentQueue()\
    \ : first(0), last(0) {}\n\n    int size() const {\n        return (last - first\
    \ + Cap) % Cap;\n    }\n\n    bool empty() const {\n        return size() == 0;\n\
    \    }\n\n    T front() const {\n        assert(!empty());\n        return pa.get(first);\n\
    \    }\n\n    T back() const {\n        assert(!empty());\n        return pa.get((last\
    \ + Cap - 1) % Cap);\n    }\n\n    PersistentQueue push(const T& val) const {\n\
    \        assert(size() < Cap);\n        return PersistentQueue(pa.set(last, val),\
    \ first, (last + 1) % Cap);\n    }\n\n    PersistentQueue pop() const {\n    \
    \    assert(!empty());\n        return PersistentQueue(pa, (first + 1) % Cap,\
    \ last);\n    }\n\nprivate:\n    PersistentArray<T> pa;\n    int first, last;\n\
    \n    PersistentQueue(const PersistentArray<T>& pa, int first, int last)\n   \
    \     : pa(pa), first(first), last(last) {}\n};\n"
  code: "#pragma once\n#include <cassert>\n#include \"persistent_array.cpp\"\n\ntemplate\
    \ <typename T, int Cap = (int) 1e7>\nclass PersistentQueue {\npublic:\n    PersistentQueue()\
    \ : first(0), last(0) {}\n\n    int size() const {\n        return (last - first\
    \ + Cap) % Cap;\n    }\n\n    bool empty() const {\n        return size() == 0;\n\
    \    }\n\n    T front() const {\n        assert(!empty());\n        return pa.get(first);\n\
    \    }\n\n    T back() const {\n        assert(!empty());\n        return pa.get((last\
    \ + Cap - 1) % Cap);\n    }\n\n    PersistentQueue push(const T& val) const {\n\
    \        assert(size() < Cap);\n        return PersistentQueue(pa.set(last, val),\
    \ first, (last + 1) % Cap);\n    }\n\n    PersistentQueue pop() const {\n    \
    \    assert(!empty());\n        return PersistentQueue(pa, (first + 1) % Cap,\
    \ last);\n    }\n\nprivate:\n    PersistentArray<T> pa;\n    int first, last;\n\
    \n    PersistentQueue(const PersistentArray<T>& pa, int first, int last)\n   \
    \     : pa(pa), first(first), last(last) {}\n};"
  dependsOn:
  - data-structure/persistent_array.cpp
  isVerificationFile: false
  path: data-structure/persistent_queue.cpp
  requiredBy: []
  timestamp: '2020-10-24 14:54:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
documentation_of: data-structure/persistent_queue.cpp
layout: document
redirect_from:
- /library/data-structure/persistent_queue.cpp
- /library/data-structure/persistent_queue.cpp.html
title: data-structure/persistent_queue.cpp
---
