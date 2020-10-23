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

/*
template <typename M>
class Treap {
    using T = typename M::T;

public:
    struct Node {
        std::unique_ptr<Node> left, right;
        T val, sum;
        int pri, cnt;
        bool rev;
        Node(T val, int pri) : left(nullptr), right(nullptr), val(val), sum(val), pri(pri), cnt(1), rev(false) {}
    };

    using node_ptr = std::unique_ptr<Node>;

    node_ptr merge(node_ptr tl, node_ptr tr) {
        if (!tl) return tr;
        if (!tr) return tl;
        push(tl);
        push(tr);
        if (tl->pri > tr->pri) {
            tl->right = merge(std::move(tl->right), std::move(tr));
            return recalc(tl);
        } else {
            tr->left = merge(std::move(tl), std::move(tr->left));
            return recalc(tr);
        }
    }

    std::pair<node_ptr, node_ptr> split(node_ptr t, int k) {
        if (!t) return {nullptr, nullptr};
        push(t);
        if (k <= count(t->left)) {
            auto s = split(std::move(t->left), k);
            t->left = std::move(s.second);
            return {s.first, recalc(t)};
        } else {
            auto s = split(std::move(t->right), k - count(t->left) - 1);
            t->right = std::move(s.first);
            return {recalc(t), s.second};
        }
    }

    node_ptr insert(node_ptr t, int k, T val, int pri) {
        auto s = split(std::move(t), k);
        return merge(merge(std::move(s.first), std::make_unique<Node>(val, pri)), std::move(s.second));
    }

    node_ptr erase(node_ptr t, int k) {
        auto sl = split(std::move(t), k - 1);
        auto sr = split(std::move(sl.second), 1);
        return merge(std::move(sl.first), std::move(sr.second));
    }

    node_ptr reverse(node_ptr t, int l, int r) {
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(t), l);
        std::tie(b, c) = split(std::move(b), r - l);
        b->rev ^= true;
        return merge(merge(std::move(a), std::move(b)), std::move(c));
    }

    T query(const node_ptr& t, int l, int r) { return query(t, l, r, 0, count(t)); }

private:
    inline int count(const node_ptr& t) { return t ? t->cnt : 0; }
    inline T sum(const node_ptr& t) { return t ? t->sum : M::id; }

    node_ptr recalc(const node_ptr& t) {
        t->cnt = count(t->left) + count(t->right) + 1;
        t->sum = t->val;
        if (t->left) t->sum = M::op(t->left->sum, t->sum);
        if (t->right) t->sum = M::op(t->sum, t->right->sum);
        return t;
    }

    void push(const node_ptr& t) {
        if (t->rev) {
            std::swap(t->left, t->right);
            if (t->left) t->left->rev ^= true;
            if (t->right) t->right->rev ^= true;
            t->rev = false;
        }
    }

    T query(const node_ptr& t, int a, int b, int l, int r) {
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return t->sum;
        push(t);
        return M::op(query(t->left, a, b, l, l + count(t->left)),
                     query(t->right, a, b, r - count(t->right), r));
    }
};
*/