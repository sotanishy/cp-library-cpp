#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>

#include "bit_vector.hpp"

template <typename T, int MAX_LOG>
class WaveletMatrix {
   public:
    WaveletMatrix() = default;
    explicit WaveletMatrix(std::vector<T> v) : mat(MAX_LOG), cnt0(MAX_LOG) {
        const int n = v.size();
        for (int d = MAX_LOG - 1; d >= 0; --d) {
            std::vector<bool> bit(n);
            for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;
            mat[d] = BitVector(bit);
            std::vector<int> cnt(2);
            for (int i = 0; i < n; ++i) {
                if (!bit[i]) cnt[0]++;
            }
            cnt0[d] = cnt[0];
            cnt[1] = n;
            std::vector<T> nv(n);
            for (int i = n - 1; i >= 0; --i) {
                nv[--cnt[bit[i]]] = v[i];
            }
            v.swap(nv);
        }
        for (int i = 0; i < n; ++i) {
            if (!start.contains(v[i])) start[v[i]] = i;
        }
    }

    T operator[](int k) const {
        T ret = 0;
        for (int d = mat.size() - 1; d >= 0; --d) {
            bool b = mat[d][k];
            ret |= T(b) << d;
            k = cnt0[d] * b + mat[d].rank(k, b);
        }
        return ret;
    }

    int rank(int k, T x) const {
        for (int d = mat.size() - 1; d >= 0; --d) {
            bool b = x >> d & 1;
            k = cnt0[d] * b + mat[d].rank(k, b);
        }
        if (start.contains(x)) return k - start.at(x);
        return k;
    }

    int range_freq(int l, int r, T ub) const {
        if (l >= r) return 0;
        int ret = 0;
        for (int d = mat.size() - 1; d >= 0; --d) {
            bool b = ub >> d & 1;
            if (b) ret += mat[d].rank(r, 0) - mat[d].rank(l, 0);
            l = cnt0[d] * b + mat[d].rank(l, b);
            r = cnt0[d] * b + mat[d].rank(r, b);
        }
        return ret;
    }

    int range_freq(int l, int r, T lb, T ub) const {
        if (lb >= ub) return 0;
        return range_freq(l, r, ub) - range_freq(l, r, lb);
    }

    int select(int k, T x) const {
        k += start.at(x);
        for (int d = 0; d < (int)mat.size(); ++d) {
            bool b = x >> d & 1;
            k = mat[d].select(k - cnt0[d] * b, b);
        }
        return k;
    }

    T quantile(int l, int r, int k) const {
        T ret = 0;
        for (int d = (int)mat.size() - 1; d >= 0; --d) {
            int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);
            bool b = k < cnt ? 0 : 1;
            l = cnt0[d] * b + mat[d].rank(l, b);
            r = cnt0[d] * b + mat[d].rank(r, b);
            if (b) {
                ret |= T(1) << d;
                k -= cnt;
            }
        }
        return ret;
    }

   private:
    std::vector<BitVector> mat;
    std::vector<int> cnt0;
    std::unordered_map<T, int> start;
};