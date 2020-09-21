---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_8_D.test.cpp
    title: test/aoj/ALDS1_8_D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/treap.md
    document_title: Treap
    links: []
  bundledCode: "#line 1 \"data-structure/treap.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/*\n * @brief Treap\n * @docs docs/data-structure/treap.md\n\
    \ */\ntemplate <typename T>\nclass Treap {\npublic:\n    int count(T key) const\
    \ { return count(root, key); }\n\n    void insert(T key, int priority = -1) {\n\
    \        if (priority == -1) priority = rand() % 100000000;\n        root = insert(root,\
    \ key, priority);\n    }\n\n    void erase(T key) {\n        root = erase(root,\
    \ key);\n    }\n\n    void print_inorder() const {\n        print_inorder(root);\n\
    \        cout << \"\\n\";\n    }\n\n    void print_preorder() const {\n      \
    \  print_preorder(root);\n        cout << \"\\n\";\n    }\n\nprivate:\n    struct\
    \ Node {\n        Node* left;\n        Node* right;\n        T key;\n        int\
    \ priority;\n        Node(T key, int priority) : left(nullptr), right(nullptr),\
    \ key(key), priority(priority) {}\n    } *root = nullptr;\n\n    int count(Node*\
    \ t, T key) const {\n        if (t == nullptr) return 0;\n        if (key == t->key)\
    \ return 1;\n        if (key < t->key) return count(t->left, key);\n        else\
    \ return count(t->right, key);\n    }\n\n    Node* rotate_left(Node* t) {\n  \
    \      Node* s = t->right;\n        t->right = s->left;\n        s->left = t;\n\
    \        return s;\n    }\n\n    Node* rotate_right(Node* t) {\n        Node*\
    \ s = t->left;\n        t->left = s->right;\n        s->right = t;\n        return\
    \ s;\n    }\n\n    Node* insert(Node* t, T key, int priority) {\n        if (t\
    \ == nullptr) return new Node(key, priority);\n        if (key == t->key) return\
    \ t;\n        if (key < t->key) {\n            t->left = insert(t->left, key,\
    \ priority);\n            if (t->priority < t->left->priority) t = rotate_right(t);\n\
    \        } else {\n            t->right = insert(t->right, key, priority);\n \
    \           if (t->priority < t->right->priority) t = rotate_left(t);\n      \
    \  }\n        return t;\n    }\n\n    Node* erase(Node* t, T key) {\n        if\
    \ (t == nullptr) return nullptr;\n        if (key == t->key) {\n            if\
    \ (t->left == nullptr && t->right == nullptr) return nullptr;\n            else\
    \ if (t->left == nullptr) t = rotate_left(t);\n            else if (t->right ==\
    \ nullptr) t = rotate_right(t);\n            else {\n                if (t->left->priority\
    \ > t->right->priority) t = rotate_right(t);\n                else t = rotate_left(t);\n\
    \            }\n            return erase(t, key);\n        }\n        if (key\
    \ < t->key) t->left = erase(t->left, key);\n        else t->right = erase(t->right,\
    \ key);\n        return t;\n    }\n\n    void print_inorder(Node* t) const {\n\
    \        if (t == nullptr) return;\n        print_inorder(t->left);\n        cout\
    \ << \" \" << t->key;\n        print_inorder(t->right);\n    }\n\n    void print_preorder(Node*\
    \ t) const {\n        if (t == nullptr) return;\n        cout << \" \" << t->key;\n\
    \        print_preorder(t->left);\n        print_preorder(t->right);\n    }\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Treap\n *\
    \ @docs docs/data-structure/treap.md\n */\ntemplate <typename T>\nclass Treap\
    \ {\npublic:\n    int count(T key) const { return count(root, key); }\n\n    void\
    \ insert(T key, int priority = -1) {\n        if (priority == -1) priority = rand()\
    \ % 100000000;\n        root = insert(root, key, priority);\n    }\n\n    void\
    \ erase(T key) {\n        root = erase(root, key);\n    }\n\n    void print_inorder()\
    \ const {\n        print_inorder(root);\n        cout << \"\\n\";\n    }\n\n \
    \   void print_preorder() const {\n        print_preorder(root);\n        cout\
    \ << \"\\n\";\n    }\n\nprivate:\n    struct Node {\n        Node* left;\n   \
    \     Node* right;\n        T key;\n        int priority;\n        Node(T key,\
    \ int priority) : left(nullptr), right(nullptr), key(key), priority(priority)\
    \ {}\n    } *root = nullptr;\n\n    int count(Node* t, T key) const {\n      \
    \  if (t == nullptr) return 0;\n        if (key == t->key) return 1;\n       \
    \ if (key < t->key) return count(t->left, key);\n        else return count(t->right,\
    \ key);\n    }\n\n    Node* rotate_left(Node* t) {\n        Node* s = t->right;\n\
    \        t->right = s->left;\n        s->left = t;\n        return s;\n    }\n\
    \n    Node* rotate_right(Node* t) {\n        Node* s = t->left;\n        t->left\
    \ = s->right;\n        s->right = t;\n        return s;\n    }\n\n    Node* insert(Node*\
    \ t, T key, int priority) {\n        if (t == nullptr) return new Node(key, priority);\n\
    \        if (key == t->key) return t;\n        if (key < t->key) {\n         \
    \   t->left = insert(t->left, key, priority);\n            if (t->priority < t->left->priority)\
    \ t = rotate_right(t);\n        } else {\n            t->right = insert(t->right,\
    \ key, priority);\n            if (t->priority < t->right->priority) t = rotate_left(t);\n\
    \        }\n        return t;\n    }\n\n    Node* erase(Node* t, T key) {\n  \
    \      if (t == nullptr) return nullptr;\n        if (key == t->key) {\n     \
    \       if (t->left == nullptr && t->right == nullptr) return nullptr;\n     \
    \       else if (t->left == nullptr) t = rotate_left(t);\n            else if\
    \ (t->right == nullptr) t = rotate_right(t);\n            else {\n           \
    \     if (t->left->priority > t->right->priority) t = rotate_right(t);\n     \
    \           else t = rotate_left(t);\n            }\n            return erase(t,\
    \ key);\n        }\n        if (key < t->key) t->left = erase(t->left, key);\n\
    \        else t->right = erase(t->right, key);\n        return t;\n    }\n\n \
    \   void print_inorder(Node* t) const {\n        if (t == nullptr) return;\n \
    \       print_inorder(t->left);\n        cout << \" \" << t->key;\n        print_inorder(t->right);\n\
    \    }\n\n    void print_preorder(Node* t) const {\n        if (t == nullptr)\
    \ return;\n        cout << \" \" << t->key;\n        print_preorder(t->left);\n\
    \        print_preorder(t->right);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/treap.cpp
  requiredBy: []
  timestamp: '2020-09-22 01:15:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_8_D.test.cpp
documentation_of: data-structure/treap.cpp
layout: document
redirect_from:
- /library/data-structure/treap.cpp
- /library/data-structure/treap.cpp.html
title: Treap
---
# Treap

Treap は，平衡二分探索木の一種である．キーと別に，ランダムに割り当てられた優先度を用いてヒープ性を持たせることで，木の平衡を保つ．

## Template parameters

- `T`
    - キーの型

## Member functions

- `int count(T key)`
    - $key$ をキーとするノードの個数 (0 か 1) を返す
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void insert(T key, int priority = -1)`
    - $key$ をキー，$priority$ を優先度とするノードを追加する．$priority$ は指定しない場合ランダムに決定される
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void erase(T key)`
    - $key$ をキーとするノードを削除する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$