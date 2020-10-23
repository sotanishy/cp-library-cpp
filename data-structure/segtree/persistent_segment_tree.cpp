#include <vector>
#include <memory>

/*
 * @brief Persistent Segment Tree
 */
template <typename M>
class PersistentSegmentTree {
    using T = typename M::T;

public:
    PersistentSegmentTree() = default;
    explicit PersistentSegmentTree(int n): PersistentSegmentTree(std::vector<T>(n, M::id)) {}
    explicit PersistentSegmentTree(const std::vector<T>& v) : root(std::make_shared<Node>()) {
        size = 1;
        while (size < (int) v.size()) size <<= 1;
        build(v, root, 0, size);
    }

    T operator[](int k) const {
        return fold(k, k + 1);
    }

    PersistentSegmentTree update(int k, const T& x) const {
        return PersistentSegmentTree(update(k, x, root, 0, size));
    }

    T fold(int l, int r) const {
        return fold(l, r, root, 0, size);
    }

private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        T val;
        node_ptr left, right;
        Node() : val(M::id), left(nullptr), right(nullptr) {}
        Node(const T& val, const node_ptr& left, const node_ptr& right) : val(val), left(left), right(right) {}
    };

    const node_ptr root;
    int size;

    explicit PersistentSegmentTree(const node_ptr& root) : root(root) {}

    void build(const std::vector<T>& v, const node_ptr& n, int l, int r) const {
        if (r - l == 1) {
            n->val = l < (int) v.size() ? v[l] : M::id;
        }
        int m = (l + r) / 2;
        n->left = std::make_shared<Node>();
        build(v, n->left, l, m);
        n->right = std::make_shared<Node>();
        build(v, n->right, m, r);
        n->val = M::op(n->left->val, n->right->val);
    }

    node_ptr update(int k, const T& x, const node_ptr& n, int l, int r) const {
        if (r - l == 1) {
            return std::make_shared<Node>(x, nullptr, nullptr);
        }
        int m = (l + r) / 2;
        if (k < m) {
            node_ptr left = update(k, x, n->left, l, m);
            T val = M::op(left->val, n->right->val);
            return std::make_shared<Node>(val, left, n->right);
        } else {
            node_ptr right = update(k, x, n->right, m, r);
            T val = M::op(n->left->val, right->val);
            return std::make_shared<Node>(val, n->left, right);
        }
    }

    T fold(int a, int b, const node_ptr& n, int l, int r) const {
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return n->val;
        int m = (l + r) / 2;
        T vl = fold(a, b, n->left, l, m);
        T vr = fold(a, b, n->right, m, r);
        return M::op(vl, vr);
    }
};