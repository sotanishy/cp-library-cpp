#pragma once
#include <functional>
#include <vector>

template <typename M>
class FenwickTree {
    using T = typename M::T;

   public:
    FenwickTree() = default;
    explicit FenwickTree(int n) : n(n), data(n + 1, M::id()) {}

    T prefix_fold(int i) const {
        T ret = M::id();
        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);
        return ret;
    }

    void update(int i, const T& x) {
        for (++i; i <= n; i += i & -i) data[i] = M::op(data[i], x);
    }

    int lower_bound(const T& x) const {
        if (x <= M::id()) return 0;
        int k = 1;
        while (k * 2 <= n) k <<= 1;
        int i = 0;
        T v = M::id();
        for (; k > 0; k >>= 1) {
            if (i + k > n) continue;
            T nv = M::op(v, data[i + k]);
            if (nv < x) {
                v = nv;
                i += k;
            }
        }
        return i + 1;
    }

   private:
    int n;
    std::vector<T> data;
};