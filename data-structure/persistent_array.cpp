#include <bits/stdc++.h>

/*
 * @brief Persistent Array
 * @docs docs/data-structure/persistent_array.md
 */
template <typename T, int B = 2>
class PersistentArray {
public:
    PersistentArray() = default;
    explicit PersistentArray(const std::vector<T>& v) {
        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);
    }

    T get(int k) const {
        return get(root, k);
    }

    PersistentArray set(int k, const T& x) const {
        return PersistentArray(set(root, k, x));
    }

private:
    struct Node {
        T val;
        std::vector<std::shared_ptr<Node>> ch;
        Node() : ch(B) {}
    };

    using node_ptr = std::shared_ptr<Node>;

    node_ptr root = nullptr;

    explicit PersistentArray(const node_ptr& root) : root(root) {}

    T get(const node_ptr& t, int k) const {
        if (k == 0) return t->val;
        return get(t->ch[k % B], k / B);
    }

    node_ptr set(const node_ptr& t, int k, const T& x) const {
        node_ptr res = t ? std::make_shared<Node>(*t) : std::make_shared<Node>();
        if (k == 0) {
            res->val = x;
        } else {
            res->ch[k % B] = set(res->ch[k % B], k / B, x);
        }
        return res;
    }
};