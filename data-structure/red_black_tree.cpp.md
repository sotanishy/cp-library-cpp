---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Red Black Tree
    links: []
  bundledCode: "#line 2 \"data-structure/red_black_tree.cpp\"\n#include <iostream>\n\
    #include <memory>\n\n/*\n * @brief Red Black Tree\n */\ntemplate <typename T>\n\
    class RedBlackTree {\npublic:\n    int count(T key) {\n        if (find(root,\
    \ key)) return 1;\n        return 0;\n    }\n\n    void insert(T key) {\n    \
    \    insert(std::make_shared<Node>(key));\n    }\n\n    void erase(T key) {\n\
    \        erase(find(root, key));\n    }\n\nprivate:\n    enum Color {\n      \
    \  BLACK, RED\n    };\n\n    struct Node;\n\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        node_ptr par, left, right;\n        Color color =\
    \ BLACK;\n        T key;\n\n        Node() = default;\n        Node(T key) : key(key)\
    \ {}\n    };\n\n    const node_ptr nil = std::make_shared<Node>();\n    node_ptr\
    \ root = nil;\n\n    node_ptr find(const node_ptr& x, T key) {\n        if (x\
    \ == nullptr) return nullptr;\n        if (key == x->key) return x;\n        if\
    \ (key < x->key) return find(x->left, key);\n        else return find(x->right,\
    \ key);\n    }\n\n    node_ptr minimum(node_ptr x) {\n        while (x->left !=\
    \ nil) x = x->left;\n        return x;\n    }\n\n    node_ptr maximum(node_ptr\
    \ x) {\n        while (x->right != nil) x = x->right;\n        return x;\n   \
    \ }\n\n    node_ptr successor(node_ptr x) {\n        if (x->right != nil) return\
    \ minimum(x->right);\n        node_ptr y = x->par;\n        while (y != nil &&\
    \ x == y->right) {\n            x = y;\n            y = y->par;\n        }\n \
    \       return y;\n    }\n\n    node_ptr predecessor(node_ptr x) {\n        if\
    \ (x->left != nil) return maximum(x->left);\n        node_ptr y = x->par;\n  \
    \      while (y != nil && x == y->left) {\n            x = y;\n            y =\
    \ y->par;\n        }\n        return y;\n    }\n\n    void rotate_left(node_ptr\
    \ x) {\n        node_ptr y = x->right;\n        x->right = y->left;\n        if\
    \ (y->left == nil) {\n            y->left->par = x;\n        }\n        y->par\
    \ = x->par;\n        if (x->par == nil) {\n            root = y;\n        } else\
    \ if (x == x->par->left) {\n            x->par->left = y;\n        } else {\n\
    \            x->par->right = y;\n        }\n        y->left = x;\n        x->par\
    \ = y;\n    }\n\n    void rotate_right(node_ptr x) {\n        node_ptr y = x->left;\n\
    \        x->left = y->right;\n        if (y->right != nil) {\n            y->right->par\
    \ = x;\n        }\n        y->par = x->par;\n        if (x->par == nil) {\n  \
    \          root = y;\n        } else if (x == x->par->left) {\n            x->par->left\
    \ = y;\n        } else {\n            x->par->right = y;\n        }\n        y->right\
    \ = x;\n        x->par = y;\n    }\n\n    void insert_fixup(node_ptr z) {\n  \
    \      while (z->par->color == RED) {\n            if (z->par == z->par->par->left)\
    \ {\n                node_ptr y = z->par->par->right;\n                if (y->color\
    \ == RED) {\n                    z->par->color = y->color = BLACK;\n         \
    \           z->par->par->color = RED;\n                    z = z->par->par;\n\
    \                } else {\n                    if (z == z->par->right) {\n   \
    \                     z = z->par;\n                        rotate_left(z);\n \
    \                   }\n                    z->par->color = BLACK;\n          \
    \          z->par->par->color = RED;\n                    rotate_right(z->par->par);\n\
    \                }\n            } else {\n                node_ptr y = z->par->par->left;\n\
    \                if (y->color == RED) {\n                    z->par->color = y->color\
    \ = BLACK;\n                    z->par->par->color = RED;\n                  \
    \  z = z->par->par;\n                } else {\n                    if (z == z->par->left)\
    \ {\n                        z = z->par;\n                        rotate_right(z);\n\
    \                    }\n                    z->par->color = BLACK;\n         \
    \           z->par->par->color = RED;\n                    rotate_left(z->par->par);\n\
    \                }\n            }\n        }\n        root->color = BLACK;\n \
    \   }\n\n    void insert(node_ptr z) {\n        node_ptr y = nil;\n        node_ptr\
    \ x = root;\n        while (x != nil) {\n            y = x;\n            if (z->key\
    \ < x->key) x = x->left;\n            else x = x->right;\n        }\n        z->par\
    \ = y;\n        if (y == nil) {\n            root = z;\n        } else if (z->key\
    \ < y->key) {\n            y->left = z;\n        } else {\n            y->right\
    \ = z;\n        }\n        z->left = z->right = nil;\n        z->color = RED;\n\
    \        insert_fixup(z);\n    }\n\n    void transplant(node_ptr u, node_ptr v)\
    \ {\n        if (u->par == nil) {\n            root = v;\n        } else if (u\
    \ == u->par->left) {\n            u->par->left = v;\n        } else {\n      \
    \      u->par->right = v;\n        }\n        v->par = u->par;\n    }\n\n    void\
    \ erase_fixup(node_ptr x) {\n        while (x != root && x->color == BLACK) {\n\
    \            if (x == x->par->left) {\n                node_ptr w = x->par->right;\n\
    \                if (w->color == RED) {\n                    w->color = BLACK;\n\
    \                    x->par->color = RED;\n                    rotate_left(x->par);\n\
    \                    w = x->par->right;\n                }\n                if\
    \ (w->left->color == BLACK && w->right->color == BLACK) {\n                  \
    \  w->color = RED;\n                    x = x->par;\n                } else {\n\
    \                    if (w->right->color == BLACK) {\n                       \
    \ w->left->color = BLACK;\n                        w->color = RED;\n         \
    \               rotate_right(w);\n                        w = x->par->right;\n\
    \                    }\n                    w->color = x->par->color;\n      \
    \              x->par->color = BLACK;\n                    w->right->color = BLACK;\n\
    \                    rotate_left(x->par);\n                    x = root;\n   \
    \             }\n            } else {\n                node_ptr w = x->par->left;\n\
    \                if (w->color == RED) {\n                    w->color = BLACK;\n\
    \                    x->par->color = RED;\n                    rotate_right(x->par);\n\
    \                    w = x->par->left;\n                }\n                if\
    \ (w->right->color == BLACK && w->left->color == BLACK) {\n                  \
    \  w->color = RED;\n                    x = x->par;\n                } else {\n\
    \                    if (w->left->color == BLACK) {\n                        w->right->color\
    \ = BLACK;\n                        w->color = RED;\n                        rotate_left(w);\n\
    \                        w = x->par->left;\n                    }\n          \
    \          w->color = x->par->color;\n                    x->par->color = BLACK;\n\
    \                    w->left->color = BLACK;\n                    rotate_right(x->par);\n\
    \                    x = root;\n                }\n            }\n        }\n\
    \        x->color = BLACK;\n    }\n\n    void erase(node_ptr z) {\n        node_ptr\
    \ y = z;\n        Color y_original_color = y->color;\n        node_ptr x;\n  \
    \      if (z->left == nil) {\n            x = z->right;\n            transplant(z,\
    \ z->right);\n        } else if (z->right == nil) {\n            x = z->left;\n\
    \            transplant(z, z->left);\n        } else {\n            y = minimum(z->right);\n\
    \            y_original_color = y->color;\n            x = y->right;\n       \
    \     if (y->par == z) {\n                x->par = y;\n            } else {\n\
    \                transplant(y, y->right);\n                y->right = z->right;\n\
    \                y->right->par = y;\n            }\n            transplant(z,\
    \ y);\n            y->left = z->left;\n            y->left->par = y;\n       \
    \     y->color = z->color;\n        }\n        if (y_original_color == BLACK)\
    \ {\n            erase_fixup(x);\n        }\n    }\n\n    void print_inorder(node_ptr\
    \ x) {\n        if (x == nil) return;\n        print_inorder(x->left);\n     \
    \   std::cout << x->key << \" \";\n        print_inorder(x->right);\n    }\n};\n"
  code: "#pragma once\n#include <iostream>\n#include <memory>\n\n/*\n * @brief Red\
    \ Black Tree\n */\ntemplate <typename T>\nclass RedBlackTree {\npublic:\n    int\
    \ count(T key) {\n        if (find(root, key)) return 1;\n        return 0;\n\
    \    }\n\n    void insert(T key) {\n        insert(std::make_shared<Node>(key));\n\
    \    }\n\n    void erase(T key) {\n        erase(find(root, key));\n    }\n\n\
    private:\n    enum Color {\n        BLACK, RED\n    };\n\n    struct Node;\n\n\
    \    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node {\n        node_ptr\
    \ par, left, right;\n        Color color = BLACK;\n        T key;\n\n        Node()\
    \ = default;\n        Node(T key) : key(key) {}\n    };\n\n    const node_ptr\
    \ nil = std::make_shared<Node>();\n    node_ptr root = nil;\n\n    node_ptr find(const\
    \ node_ptr& x, T key) {\n        if (x == nullptr) return nullptr;\n        if\
    \ (key == x->key) return x;\n        if (key < x->key) return find(x->left, key);\n\
    \        else return find(x->right, key);\n    }\n\n    node_ptr minimum(node_ptr\
    \ x) {\n        while (x->left != nil) x = x->left;\n        return x;\n    }\n\
    \n    node_ptr maximum(node_ptr x) {\n        while (x->right != nil) x = x->right;\n\
    \        return x;\n    }\n\n    node_ptr successor(node_ptr x) {\n        if\
    \ (x->right != nil) return minimum(x->right);\n        node_ptr y = x->par;\n\
    \        while (y != nil && x == y->right) {\n            x = y;\n           \
    \ y = y->par;\n        }\n        return y;\n    }\n\n    node_ptr predecessor(node_ptr\
    \ x) {\n        if (x->left != nil) return maximum(x->left);\n        node_ptr\
    \ y = x->par;\n        while (y != nil && x == y->left) {\n            x = y;\n\
    \            y = y->par;\n        }\n        return y;\n    }\n\n    void rotate_left(node_ptr\
    \ x) {\n        node_ptr y = x->right;\n        x->right = y->left;\n        if\
    \ (y->left == nil) {\n            y->left->par = x;\n        }\n        y->par\
    \ = x->par;\n        if (x->par == nil) {\n            root = y;\n        } else\
    \ if (x == x->par->left) {\n            x->par->left = y;\n        } else {\n\
    \            x->par->right = y;\n        }\n        y->left = x;\n        x->par\
    \ = y;\n    }\n\n    void rotate_right(node_ptr x) {\n        node_ptr y = x->left;\n\
    \        x->left = y->right;\n        if (y->right != nil) {\n            y->right->par\
    \ = x;\n        }\n        y->par = x->par;\n        if (x->par == nil) {\n  \
    \          root = y;\n        } else if (x == x->par->left) {\n            x->par->left\
    \ = y;\n        } else {\n            x->par->right = y;\n        }\n        y->right\
    \ = x;\n        x->par = y;\n    }\n\n    void insert_fixup(node_ptr z) {\n  \
    \      while (z->par->color == RED) {\n            if (z->par == z->par->par->left)\
    \ {\n                node_ptr y = z->par->par->right;\n                if (y->color\
    \ == RED) {\n                    z->par->color = y->color = BLACK;\n         \
    \           z->par->par->color = RED;\n                    z = z->par->par;\n\
    \                } else {\n                    if (z == z->par->right) {\n   \
    \                     z = z->par;\n                        rotate_left(z);\n \
    \                   }\n                    z->par->color = BLACK;\n          \
    \          z->par->par->color = RED;\n                    rotate_right(z->par->par);\n\
    \                }\n            } else {\n                node_ptr y = z->par->par->left;\n\
    \                if (y->color == RED) {\n                    z->par->color = y->color\
    \ = BLACK;\n                    z->par->par->color = RED;\n                  \
    \  z = z->par->par;\n                } else {\n                    if (z == z->par->left)\
    \ {\n                        z = z->par;\n                        rotate_right(z);\n\
    \                    }\n                    z->par->color = BLACK;\n         \
    \           z->par->par->color = RED;\n                    rotate_left(z->par->par);\n\
    \                }\n            }\n        }\n        root->color = BLACK;\n \
    \   }\n\n    void insert(node_ptr z) {\n        node_ptr y = nil;\n        node_ptr\
    \ x = root;\n        while (x != nil) {\n            y = x;\n            if (z->key\
    \ < x->key) x = x->left;\n            else x = x->right;\n        }\n        z->par\
    \ = y;\n        if (y == nil) {\n            root = z;\n        } else if (z->key\
    \ < y->key) {\n            y->left = z;\n        } else {\n            y->right\
    \ = z;\n        }\n        z->left = z->right = nil;\n        z->color = RED;\n\
    \        insert_fixup(z);\n    }\n\n    void transplant(node_ptr u, node_ptr v)\
    \ {\n        if (u->par == nil) {\n            root = v;\n        } else if (u\
    \ == u->par->left) {\n            u->par->left = v;\n        } else {\n      \
    \      u->par->right = v;\n        }\n        v->par = u->par;\n    }\n\n    void\
    \ erase_fixup(node_ptr x) {\n        while (x != root && x->color == BLACK) {\n\
    \            if (x == x->par->left) {\n                node_ptr w = x->par->right;\n\
    \                if (w->color == RED) {\n                    w->color = BLACK;\n\
    \                    x->par->color = RED;\n                    rotate_left(x->par);\n\
    \                    w = x->par->right;\n                }\n                if\
    \ (w->left->color == BLACK && w->right->color == BLACK) {\n                  \
    \  w->color = RED;\n                    x = x->par;\n                } else {\n\
    \                    if (w->right->color == BLACK) {\n                       \
    \ w->left->color = BLACK;\n                        w->color = RED;\n         \
    \               rotate_right(w);\n                        w = x->par->right;\n\
    \                    }\n                    w->color = x->par->color;\n      \
    \              x->par->color = BLACK;\n                    w->right->color = BLACK;\n\
    \                    rotate_left(x->par);\n                    x = root;\n   \
    \             }\n            } else {\n                node_ptr w = x->par->left;\n\
    \                if (w->color == RED) {\n                    w->color = BLACK;\n\
    \                    x->par->color = RED;\n                    rotate_right(x->par);\n\
    \                    w = x->par->left;\n                }\n                if\
    \ (w->right->color == BLACK && w->left->color == BLACK) {\n                  \
    \  w->color = RED;\n                    x = x->par;\n                } else {\n\
    \                    if (w->left->color == BLACK) {\n                        w->right->color\
    \ = BLACK;\n                        w->color = RED;\n                        rotate_left(w);\n\
    \                        w = x->par->left;\n                    }\n          \
    \          w->color = x->par->color;\n                    x->par->color = BLACK;\n\
    \                    w->left->color = BLACK;\n                    rotate_right(x->par);\n\
    \                    x = root;\n                }\n            }\n        }\n\
    \        x->color = BLACK;\n    }\n\n    void erase(node_ptr z) {\n        node_ptr\
    \ y = z;\n        Color y_original_color = y->color;\n        node_ptr x;\n  \
    \      if (z->left == nil) {\n            x = z->right;\n            transplant(z,\
    \ z->right);\n        } else if (z->right == nil) {\n            x = z->left;\n\
    \            transplant(z, z->left);\n        } else {\n            y = minimum(z->right);\n\
    \            y_original_color = y->color;\n            x = y->right;\n       \
    \     if (y->par == z) {\n                x->par = y;\n            } else {\n\
    \                transplant(y, y->right);\n                y->right = z->right;\n\
    \                y->right->par = y;\n            }\n            transplant(z,\
    \ y);\n            y->left = z->left;\n            y->left->par = y;\n       \
    \     y->color = z->color;\n        }\n        if (y_original_color == BLACK)\
    \ {\n            erase_fixup(x);\n        }\n    }\n\n    void print_inorder(node_ptr\
    \ x) {\n        if (x == nil) return;\n        print_inorder(x->left);\n     \
    \   std::cout << x->key << \" \";\n        print_inorder(x->right);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/red_black_tree.cpp
  requiredBy: []
  timestamp: '2020-10-26 19:52:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/red_black_tree.cpp
layout: document
redirect_from:
- /library/data-structure/red_black_tree.cpp
- /library/data-structure/red_black_tree.cpp.html
title: Red Black Tree
---
