#pragma once
#include <cstdint>
#include <vector>

/*
 * @brief Bit Vector
 */
class BitVector {
    using u32 = uint32_t;

public:
    BitVector() = default;
    explicit BitVector(const std::vector<bool>& v) {
        int n = (v.size() + sz - 1) / sz;
        data.resize(n);
        sum.resize(n + 1);
        for (int i = 0; i < (int) v.size(); ++i) data[i / sz] |= v[i] << (i % sz);
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + __builtin_popcount(data[i]);
    }

    int access(int k) const {
        return data[k / sz] >> (k % sz) & 1;
    }

    int rank(int k, bool b) const {
        int mask = (1 << (k % sz)) - 1;
        int r = sum[k / sz] + __builtin_popcount(data[k / sz] & mask);
        return b ? r : k - r;
    }

    int select(int k, bool b) const {
        int lb = 0, ub = data.size();
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (rank(m, b) <= k) lb = m;
            else ub = m;
        }
        return lb;
    }

private:
    static constexpr int sz = 32;

    std::vector<u32> data;
    std::vector<int> sum;
};