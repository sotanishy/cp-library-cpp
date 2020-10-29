#pragma once
#include <iostream>
#include <memory>

/*
 * @brief Red Black Tree
 */
template <typename T>
class RedBlackTree {
public:
    int count(T key) {
        if (find(root, key)) return 1;
        return 0;
    }

    void insert(T key) {
        insert(std::make_shared<Node>(key));
    }

    void erase(T key) {
        erase(find(root, key));
    }

private:
    enum Color {
        BLACK, RED
    };

    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        node_ptr par, left, right;
        Color color = BLACK;
        T key;

        Node() = default;
        Node(T key) : key(key) {}
    };

    const node_ptr nil = std::make_shared<Node>();
    node_ptr root = nil;

    node_ptr find(const node_ptr& x, T key) {
        if (x == nullptr) return nullptr;
        if (key == x->key) return x;
        if (key < x->key) return find(x->left, key);
        else return find(x->right, key);
    }

    node_ptr minimum(node_ptr x) {
        while (x->left != nil) x = x->left;
        return x;
    }

    node_ptr maximum(node_ptr x) {
        while (x->right != nil) x = x->right;
        return x;
    }

    node_ptr successor(node_ptr x) {
        if (x->right != nil) return minimum(x->right);
        node_ptr y = x->par;
        while (y != nil && x == y->right) {
            x = y;
            y = y->par;
        }
        return y;
    }

    node_ptr predecessor(node_ptr x) {
        if (x->left != nil) return maximum(x->left);
        node_ptr y = x->par;
        while (y != nil && x == y->left) {
            x = y;
            y = y->par;
        }
        return y;
    }

    void rotate_left(node_ptr x) {
        node_ptr y = x->right;
        x->right = y->left;
        if (y->left == nil) {
            y->left->par = x;
        }
        y->par = x->par;
        if (x->par == nil) {
            root = y;
        } else if (x == x->par->left) {
            x->par->left = y;
        } else {
            x->par->right = y;
        }
        y->left = x;
        x->par = y;
    }

    void rotate_right(node_ptr x) {
        node_ptr y = x->left;
        x->left = y->right;
        if (y->right != nil) {
            y->right->par = x;
        }
        y->par = x->par;
        if (x->par == nil) {
            root = y;
        } else if (x == x->par->left) {
            x->par->left = y;
        } else {
            x->par->right = y;
        }
        y->right = x;
        x->par = y;
    }

    void insert_fixup(node_ptr z) {
        while (z->par->color == RED) {
            if (z->par == z->par->par->left) {
                node_ptr y = z->par->par->right;
                if (y->color == RED) {
                    z->par->color = y->color = BLACK;
                    z->par->par->color = RED;
                    z = z->par->par;
                } else {
                    if (z == z->par->right) {
                        z = z->par;
                        rotate_left(z);
                    }
                    z->par->color = BLACK;
                    z->par->par->color = RED;
                    rotate_right(z->par->par);
                }
            } else {
                node_ptr y = z->par->par->left;
                if (y->color == RED) {
                    z->par->color = y->color = BLACK;
                    z->par->par->color = RED;
                    z = z->par->par;
                } else {
                    if (z == z->par->left) {
                        z = z->par;
                        rotate_right(z);
                    }
                    z->par->color = BLACK;
                    z->par->par->color = RED;
                    rotate_left(z->par->par);
                }
            }
        }
        root->color = BLACK;
    }

    void insert(node_ptr z) {
        node_ptr y = nil;
        node_ptr x = root;
        while (x != nil) {
            y = x;
            if (z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->par = y;
        if (y == nil) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        z->left = z->right = nil;
        z->color = RED;
        insert_fixup(z);
    }

    void transplant(node_ptr u, node_ptr v) {
        if (u->par == nil) {
            root = v;
        } else if (u == u->par->left) {
            u->par->left = v;
        } else {
            u->par->right = v;
        }
        v->par = u->par;
    }

    void erase_fixup(node_ptr x) {
        while (x != root && x->color == BLACK) {
            if (x == x->par->left) {
                node_ptr w = x->par->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->par->color = RED;
                    rotate_left(x->par);
                    w = x->par->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->par;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotate_right(w);
                        w = x->par->right;
                    }
                    w->color = x->par->color;
                    x->par->color = BLACK;
                    w->right->color = BLACK;
                    rotate_left(x->par);
                    x = root;
                }
            } else {
                node_ptr w = x->par->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->par->color = RED;
                    rotate_right(x->par);
                    w = x->par->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->par;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotate_left(w);
                        w = x->par->left;
                    }
                    w->color = x->par->color;
                    x->par->color = BLACK;
                    w->left->color = BLACK;
                    rotate_right(x->par);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void erase(node_ptr z) {
        node_ptr y = z;
        Color y_original_color = y->color;
        node_ptr x;
        if (z->left == nil) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nil) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->par == z) {
                x->par = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->par = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->par = y;
            y->color = z->color;
        }
        if (y_original_color == BLACK) {
            erase_fixup(x);
        }
    }
};
