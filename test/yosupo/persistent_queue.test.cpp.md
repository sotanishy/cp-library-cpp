---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.cpp
    title: Persistent Array
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_queue.cpp
    title: Persistent Queue
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/yosupo/persistent_queue.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n#line 2 \"data-structure/persistent_queue.cpp\"\
    \n#include <cassert>\n#line 2 \"data-structure/persistent_array.cpp\"\n#include\
    \ <memory>\n#include <vector>\n\n/*\n * @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
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
    \ res;\n    }\n};\n#line 4 \"data-structure/persistent_queue.cpp\"\n\n/*\n * @brief\
    \ Persistent Queue\n */\ntemplate <typename T, int Cap = (int) 1e7>\nclass PersistentQueue\
    \ {\npublic:\n    PersistentQueue() : first(0), last(0) {}\n\n    int size() const\
    \ {\n        return (last - first + Cap) % Cap;\n    }\n\n    bool empty() const\
    \ {\n        return size() == 0;\n    }\n\n    T front() const {\n        assert(!empty());\n\
    \        return pa.get(first);\n    }\n\n    T back() const {\n        assert(!empty());\n\
    \        return pa.get((last + Cap - 1) % Cap);\n    }\n\n    PersistentQueue\
    \ push(const T& val) const {\n        assert(size() < Cap);\n        return PersistentQueue(pa.set(last,\
    \ val), first, (last + 1) % Cap);\n    }\n\n    PersistentQueue pop() const {\n\
    \        assert(!empty());\n        return PersistentQueue(pa, (first + 1) % Cap,\
    \ last);\n    }\n\nprivate:\n    PersistentArray<T> pa;\n    int first, last;\n\
    \n    PersistentQueue(const PersistentArray<T>& pa, int first, int last)\n   \
    \     : pa(pa), first(first), last(last) {}\n};\n#line 4 \"test/yosupo/persistent_queue.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int Q;\n    cin >> Q;\n    PersistentQueue<int>\
    \ init;\n    vector<PersistentQueue<int>> ver(Q);\n    for (int i = 0; i < Q;\
    \ ++i) {\n        int q, t;\n        cin >> q >> t;\n        if (q == 0) {\n \
    \           int x;\n            cin >> x;\n            if (t == -1) ver[i] = init.push(x);\n\
    \            else ver[i] = ver[t].push(x);\n        } else {\n            cout\
    \ << ver[t].front() << \"\\n\";\n            ver[i] = ver[t].pop();\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include \"../../data-structure/persistent_queue.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int Q;\n    cin >> Q;\n    PersistentQueue<int>\
    \ init;\n    vector<PersistentQueue<int>> ver(Q);\n    for (int i = 0; i < Q;\
    \ ++i) {\n        int q, t;\n        cin >> q >> t;\n        if (q == 0) {\n \
    \           int x;\n            cin >> x;\n            if (t == -1) ver[i] = init.push(x);\n\
    \            else ver[i] = ver[t].push(x);\n        } else {\n            cout\
    \ << ver[t].front() << \"\\n\";\n            ver[i] = ver[t].pop();\n        }\n\
    \    }\n}"
  dependsOn:
  - data-structure/persistent_queue.cpp
  - data-structure/persistent_array.cpp
  isVerificationFile: true
  path: test/yosupo/persistent_queue.test.cpp
  requiredBy: []
  timestamp: '2020-10-26 19:52:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_queue.test.cpp
- /verify/test/yosupo/persistent_queue.test.cpp.html
title: test/yosupo/persistent_queue.test.cpp
---
