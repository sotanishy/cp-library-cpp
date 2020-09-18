#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Treap {
public:

    int count(T key) { count(root, key); }

    void insert(T key, int priority = -1) {
        if (priority == -1) priority = rand() % 100000000;
        root = insert(root, key, priority);
    }

    void erase(T key) {
        root = erase(root, key);
    }

    void print_inorder() {
        print_inorder(root);
        cout << "\n";
    }

    void print_preorder() {
        print_preorder(root);
        cout << "\n";
    }

private:
    struct Node {
        Node* left;
        Node* right;
        T key;
        int priority;
        Node(T key, int priority) : left(nullptr), right(nullptr), key(key), priority(priority) {}
    } *root = nullptr;

    int count(Node* t, T key) {
        if (t == nullptr) return 0;
        if (key == t->key) return 1;
        if (key < t->key) return count(t->left, key);
        else return count(t->right, key);
    }

    Node* rotate_left(Node* t) {
        Node* s = t->right;
        t->right = s->left;
        s->left = t;
        return s;
    }

    Node* rotate_right(Node* t) {
        Node* s = t->left;
        t->left = s->right;
        s->right = t;
        return s;
    }

    Node* insert(Node* t, T key, int priority) {
        if (t == nullptr) return new Node(key, priority);
        if (key == t->key) return t;
        if (key < t->key) {
            t->left = insert(t->left, key, priority);
            if (t->priority < t->left->priority) t = rotate_right(t);
        } else {
            t->right = insert(t->right, key, priority);
            if (t->priority < t->right->priority) t = rotate_left(t);
        }
        return t;
    }

    Node* erase(Node* t, T key) {
        if (t == nullptr) return nullptr;
        if (key == t->key) {
            if (t->left == nullptr && t->right == nullptr) return nullptr;
            else if (t->left == nullptr) t = rotate_left(t);
            else if (t->right == nullptr) t = rotate_right(t);
            else {
                if (t->left->priority > t->right->priority) t = rotate_right(t);
                else t = rotate_left(t);
            }
            return erase(t, key);
        }
        if (key < t->key) t->left = erase(t->left, key);
        else t->right = erase(t->right, key);
        return t;
    }

    void print_inorder(Node* t) {
        if (t == nullptr) return;
        print_inorder(t->left);
        cout << " " << t->key;
        print_inorder(t->right);
    }

    void print_preorder(Node* t) {
        if (t == nullptr) return;
        cout << " " << t->key;
        print_preorder(t->left);
        print_preorder(t->right);
    }
};