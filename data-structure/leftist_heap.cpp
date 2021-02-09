#pragma once
#include <algorithm>
#include <memory>
#include <utility>

template <typename T>
class LeftistHeap {
public:
    LeftistHeap() = default;

    static LeftistHeap meld(LeftistHeap a, LeftistHeap b) {
        return LeftistHeap(meld(std::move(a.root), std::move(b.root)));
    }

    std::pair<int, T> top() const {
        push(root);
        return {root->id, root->val};
    }

    void pop() {
        push(root);
        root = meld(std::move(root->left), std::move(root->right));
    }

    void push(int id, T x) {
        root = meld(std::move(root), std::make_unique<Node>(id, x));
    }

    bool empty() const { return root == nullptr; }

    void add(T x) { root->lazy += x; }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        node_ptr left, right;
        int s;
        int id;
        T val, lazy;
        Node(int id, T x) : id(id), val(x) {}
    };

    node_ptr root = nullptr;

    explicit LeftistHeap(node_ptr root) : root(std::move(root)) {}

    static node_ptr meld(node_ptr a, node_ptr b) {
        if (!a) return b;
        if (!b) return a;
        push(a);
        push(b);
        if (a->val > b->val) std::swap(a, b);
        a->right = meld(std::move(a->right), std::move(b));
        if (!a->left || a->left->s < a->right->s) std::swap(a->left, a->right);
        a->s = (a->right ? a->right->s : 0) + 1;
        return a;
    }

    static void push(const node_ptr& t) {
        if (t->left) t->left->lazy += t->lazy;
        if (t->right) t->right->lazy += t->lazy;
        t->val += t->lazy;
        t->lazy = 0;
    }
};