---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/treap.cpp
    title: Treap
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_8_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_D\"\
    \n\n#line 1 \"data-structure/treap.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Treap\n * @docs docs/data-structure/treap.md\n */\ntemplate <typename T>\nclass\
    \ Treap {\npublic:\n    int count(T key) const { return count(root, key); }\n\n\
    \    void insert(T key, int priority = -1) {\n        if (priority == -1) priority\
    \ = std::rand() % 100000000;\n        root = insert(std::move(root), key, priority);\n\
    \    }\n\n    void erase(T key) {\n        root = erase(std::move(root), key);\n\
    \    }\n\n    void print_inorder() const {\n        print_inorder(root);\n   \
    \     std::cout << \"\\n\";\n    }\n\n    void print_preorder() const {\n    \
    \    print_preorder(root);\n        std::cout << \"\\n\";\n    }\n\nprivate:\n\
    \    struct Node {\n        std::unique_ptr<Node> left, right;\n        T key;\n\
    \        int priority;\n        Node(T key, int priority) : left(nullptr), right(nullptr),\
    \ key(key), priority(priority) {}\n    };\n\n    std::unique_ptr<Node> root =\
    \ nullptr;\n\n    int count(std::unique_ptr<Node> const& t, T key) const {\n \
    \       if (t == nullptr) return 0;\n        if (key == t->key) return 1;\n  \
    \      if (key < t->key) return count(t->left, key);\n        else return count(t->right,\
    \ key);\n    }\n\n    std::unique_ptr<Node> rotate_left(std::unique_ptr<Node>\
    \ t) {\n        std::unique_ptr<Node> s = std::move(t->right);\n        t->right\
    \ = std::move(s->left);\n        s->left = std::move(t);\n        return s;\n\
    \    }\n\n    std::unique_ptr<Node> rotate_right(std::unique_ptr<Node> t) {\n\
    \        std::unique_ptr<Node> s = std::move(t->left);\n        t->left = std::move(s->right);\n\
    \        s->right = std::move(t);\n        return s;\n    }\n\n    std::unique_ptr<Node>\
    \ insert(std::unique_ptr<Node> t, T key, int priority) {\n        if (t == nullptr)\
    \ return std::make_unique<Node>(key, priority);\n        if (key == t->key) return\
    \ t;\n        if (key < t->key) {\n            t->left = insert(std::move(t->left),\
    \ key, priority);\n            if (t->priority < t->left->priority) t = rotate_right(std::move(t));\n\
    \        } else {\n            t->right = insert(std::move(t->right), key, priority);\n\
    \            if (t->priority < t->right->priority) t = rotate_left(std::move(t));\n\
    \        }\n        return t;\n    }\n\n    std::unique_ptr<Node> erase(std::unique_ptr<Node>\
    \ t, T key) {\n        if (t == nullptr) return nullptr;\n        if (key == t->key)\
    \ {\n            if (t->left == nullptr && t->right == nullptr) return nullptr;\n\
    \            else if (t->left == nullptr) t = rotate_left(std::move(t));\n   \
    \         else if (t->right == nullptr) t = rotate_right(std::move(t));\n    \
    \        else {\n                if (t->left->priority > t->right->priority) t\
    \ = rotate_right(std::move(t));\n                else t = rotate_left(std::move(t));\n\
    \            }\n            return erase(std::move(t), key);\n        }\n    \
    \    if (key < t->key) t->left = erase(std::move(t->left), key);\n        else\
    \ t->right = erase(std::move(t->right), key);\n        return t;\n    }\n\n  \
    \  void print_inorder(std::unique_ptr<Node> const& t) const {\n        if (t ==\
    \ nullptr) return;\n        print_inorder(t->left);\n        std::cout << \" \"\
    \ << t->key;\n        print_inorder(t->right);\n    }\n\n    void print_preorder(std::unique_ptr<Node>\
    \ const& t) const {\n        if (t == nullptr) return;\n        std::cout << \"\
    \ \" << t->key;\n        print_preorder(t->left);\n        print_preorder(t->right);\n\
    \    }\n};\n#line 4 \"test/aoj/ALDS1_8_D.test.cpp\"\n\nusing namespace std;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ m;\n    cin >> m;\n    Treap<int> treap;\n    for (int i = 0; i < m; i++) {\n\
    \        string op;\n        cin >> op;\n        if (op == \"insert\") {\n   \
    \         int k, p;\n            cin >> k >> p;\n            treap.insert(k, p);\n\
    \        } else if (op == \"find\") {\n            int k;\n            cin >>\
    \ k;\n            if (treap.count(k)) cout << \"yes\\n\";\n            else cout\
    \ << \"no\\n\";\n        } else if (op == \"delete\") {\n            int k;\n\
    \            cin >> k;\n            treap.erase(k);\n        } else {\n      \
    \      treap.print_inorder();\n            treap.print_preorder();\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_D\"\
    \n\n#include \"../../data-structure/treap.cpp\"\n\nusing namespace std;\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ m;\n    cin >> m;\n    Treap<int> treap;\n    for (int i = 0; i < m; i++) {\n\
    \        string op;\n        cin >> op;\n        if (op == \"insert\") {\n   \
    \         int k, p;\n            cin >> k >> p;\n            treap.insert(k, p);\n\
    \        } else if (op == \"find\") {\n            int k;\n            cin >>\
    \ k;\n            if (treap.count(k)) cout << \"yes\\n\";\n            else cout\
    \ << \"no\\n\";\n        } else if (op == \"delete\") {\n            int k;\n\
    \            cin >> k;\n            treap.erase(k);\n        } else {\n      \
    \      treap.print_inorder();\n            treap.print_preorder();\n        }\n\
    \    }\n}"
  dependsOn:
  - data-structure/treap.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_8_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 00:47:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_8_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_8_D.test.cpp
- /verify/test/aoj/ALDS1_8_D.test.cpp.html
title: test/aoj/ALDS1_8_D.test.cpp
---
