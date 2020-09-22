#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fenwick Tree
 * @docs docs/data-structure/fenwick_tree.md
 */
template <typename M>
class FenwickTree {
    using T = typename M::T;

public:
    FenwickTree() = default;
    explicit FenwickTree(int n) : n(n), data(n + 1, M::id) {}

    T prefix_fold(int i) const {
        T ret = M::id;
        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);
        return ret;
    }

    void update(int i, T x) {
        for (++i; i <= n; i += i & -i) data[i] = M::op(data[i], x);
    }

    int find_first(const std::function<bool(T)>& cond) const {
        int k = 1;
        while (k * 2 <= n) k <<= 1;
        int i = 0;
        T x = M::id;
        for (; k > 0; k >>= 1) {
            if (i + k <= n && !cond(M::op(x, data[i + k]))) {
                x = M::op(x, data[i + k]);
                i += k;
            }
        }
        return i - 1;
    }

private:
    int n;
    std::vector<T> data;
};