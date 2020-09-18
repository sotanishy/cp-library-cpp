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
    \n\n#line 1 \"data-structure/treap.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/*\n * @brief Treap\n * @docs docs/data-structure/treap.md\n */\ntemplate\
    \ <typename T>\nstruct Treap {\npublic:\n\n    int count(T key) { return count(root,\
    \ key); }\n\n    void insert(T key, int priority = -1) {\n        if (priority\
    \ == -1) priority = rand() % 100000000;\n        root = insert(root, key, priority);\n\
    \    }\n\n    void erase(T key) {\n        root = erase(root, key);\n    }\n\n\
    \    void print_inorder() {\n        print_inorder(root);\n        cout << \"\\\
    n\";\n    }\n\n    void print_preorder() {\n        print_preorder(root);\n  \
    \      cout << \"\\n\";\n    }\n\nprivate:\n    struct Node {\n        Node* left;\n\
    \        Node* right;\n        T key;\n        int priority;\n        Node(T key,\
    \ int priority) : left(nullptr), right(nullptr), key(key), priority(priority)\
    \ {}\n    } *root = nullptr;\n\n    int count(Node* t, T key) {\n        if (t\
    \ == nullptr) return 0;\n        if (key == t->key) return 1;\n        if (key\
    \ < t->key) return count(t->left, key);\n        else return count(t->right, key);\n\
    \    }\n\n    Node* rotate_left(Node* t) {\n        Node* s = t->right;\n    \
    \    t->right = s->left;\n        s->left = t;\n        return s;\n    }\n\n \
    \   Node* rotate_right(Node* t) {\n        Node* s = t->left;\n        t->left\
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
    \   void print_inorder(Node* t) {\n        if (t == nullptr) return;\n       \
    \ print_inorder(t->left);\n        cout << \" \" << t->key;\n        print_inorder(t->right);\n\
    \    }\n\n    void print_preorder(Node* t) {\n        if (t == nullptr) return;\n\
    \        cout << \" \" << t->key;\n        print_preorder(t->left);\n        print_preorder(t->right);\n\
    \    }\n};\n#line 4 \"test/aoj/ALDS1_8_D.test.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int m;\n    cin >> m;\n    Treap<int> treap;\n    for\
    \ (int i = 0; i < m; i++) {\n        string op;\n        cin >> op;\n        if\
    \ (op == \"insert\") {\n            int k, p;\n            cin >> k >> p;\n  \
    \          treap.insert(k, p);\n        } else if (op == \"find\") {\n       \
    \     int k;\n            cin >> k;\n            if (treap.count(k)) cout << \"\
    yes\\n\";\n            else cout << \"no\\n\";\n        } else if (op == \"delete\"\
    ) {\n            int k;\n            cin >> k;\n            treap.erase(k);\n\
    \        } else {\n            treap.print_inorder();\n            treap.print_preorder();\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_D\"\
    \n\n#include \"../../data-structure/treap.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int m;\n    cin >> m;\n    Treap<int> treap;\n    for\
    \ (int i = 0; i < m; i++) {\n        string op;\n        cin >> op;\n        if\
    \ (op == \"insert\") {\n            int k, p;\n            cin >> k >> p;\n  \
    \          treap.insert(k, p);\n        } else if (op == \"find\") {\n       \
    \     int k;\n            cin >> k;\n            if (treap.count(k)) cout << \"\
    yes\\n\";\n            else cout << \"no\\n\";\n        } else if (op == \"delete\"\
    ) {\n            int k;\n            cin >> k;\n            treap.erase(k);\n\
    \        } else {\n            treap.print_inorder();\n            treap.print_preorder();\n\
    \        }\n    }\n}"
  dependsOn:
  - data-structure/treap.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_8_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-19 00:10:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_8_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_8_D.test.cpp
- /verify/test/aoj/ALDS1_8_D.test.cpp.html
title: test/aoj/ALDS1_8_D.test.cpp
---
