#include <bits/stdc++.h>

/*
 * @brief Treap
 * @docs docs/data-structure/treap.md
 */
template <typename T>
class Treap {
public:
    int count(T key) const { return count(root, key); }

    void insert(T key, int priority = -1) {
        if (priority == -1) priority = std::rand() % 100000000;
        root = insert(std::move(root), key, priority);
    }

    void erase(T key) {
        root = erase(std::move(root), key);
    }

    void print_inorder() const {
        print_inorder(root);
        std::cout << "\n";
    }

    void print_preorder() const {
        print_preorder(root);
        std::cout << "\n";
    }

private:
    struct Node {
        std::unique_ptr<Node> left, right;
        T key;
        int priority;
        Node(T key, int priority) : left(nullptr), right(nullptr), key(key), priority(priority) {}
    };

    std::unique_ptr<Node> root = nullptr;

    int count(std::unique_ptr<Node> const& t, T key) const {
        if (t == nullptr) return 0;
        if (key == t->key) return 1;
        if (key < t->key) return count(t->left, key);
        else return count(t->right, key);
    }

    std::unique_ptr<Node> rotate_left(std::unique_ptr<Node> t) {
        std::unique_ptr<Node> s = std::move(t->right);
        t->right = std::move(s->left);
        s->left = std::move(t);
        return s;
    }

    std::unique_ptr<Node> rotate_right(std::unique_ptr<Node> t) {
        std::unique_ptr<Node> s = std::move(t->left);
        t->left = std::move(s->right);
        s->right = std::move(t);
        return s;
    }

    std::unique_ptr<Node> insert(std::unique_ptr<Node> t, T key, int priority) {
        if (t == nullptr) return std::make_unique<Node>(key, priority);
        if (key == t->key) return t;
        if (key < t->key) {
            t->left = insert(std::move(t->left), key, priority);
            if (t->priority < t->left->priority) t = rotate_right(std::move(t));
        } else {
            t->right = insert(std::move(t->right), key, priority);
            if (t->priority < t->right->priority) t = rotate_left(std::move(t));
        }
        return t;
    }

    std::unique_ptr<Node> erase(std::unique_ptr<Node> t, T key) {
        if (t == nullptr) return nullptr;
        if (key == t->key) {
            if (t->left == nullptr && t->right == nullptr) return nullptr;
            else if (t->left == nullptr) t = rotate_left(std::move(t));
            else if (t->right == nullptr) t = rotate_right(std::move(t));
            else {
                if (t->left->priority > t->right->priority) t = rotate_right(std::move(t));
                else t = rotate_left(std::move(t));
            }
            return erase(std::move(t), key);
        }
        if (key < t->key) t->left = erase(std::move(t->left), key);
        else t->right = erase(std::move(t->right), key);
        return t;
    }

    void print_inorder(std::unique_ptr<Node> const& t) const {
        if (t == nullptr) return;
        print_inorder(t->left);
        std::cout << " " << t->key;
        print_inorder(t->right);
    }

    void print_preorder(std::unique_ptr<Node> const& t) const {
        if (t == nullptr) return;
        std::cout << " " << t->key;
        print_preorder(t->left);
        print_preorder(t->right);
    }
};