#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>
#include "bit_vector.cpp"

template <typename T>
class WaveletMatrix {
public:
    WaveletMatrix() = default;
    explicit WaveletMatrix(std::vector<T> v) {
        int n = v.size() ;
        T m = *std::max_element(v.begin(), v.end());
        int d = 0;
        while ((1 << d) <= m) ++d;
        mat.resize(d);
        cnt0.resize(d);
        for (d -= 1; d >= 0; --d) {
            std::vector<bool> bit(n);
            for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;
            mat[d] = BitVector(bit);
            std::vector<int> cnt(2);
            for (int i = 0; i < n; ++i) if (!bit[i]) cnt[0]++;
            cnt0[d] = cnt[0];
            cnt[1] = n;
            std::vector<T> nv(n);
            for (int i = n - 1; i >= 0; --i) nv[--cnt[bit[i]]] = v[i];
            v.swap(nv);
        }
        for (int i = 0; i < n; ++i) if (!start.count(v[i])) start[v[i]] = i;
    }

    T access(int k) const {
        T ret = 0;
        for (int d = mat.size() - 1; d >= 0; --d) {
            bool b = mat[d].access(k);
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
        if (start.count(x)) return k - start.at(x);
        return k;
    }

    int rank_less(int k, T x) const {
        int ret = 0;
        int l = 0;
        for (int d = mat.size() - 1; d >= 0; --d) {
            bool b = x >> d & 1;
            if (b) ret += mat[d].rank(k, 0) - mat[d].rank(l, 0);
            l = cnt0[d] * b + mat[d].rank(l, b);
            k = cnt0[d] * b + mat[d].rank(k, b);
        }
        return ret;
    }

    int select(int k, T x) const {
        k += start.at(x);
        for (int d = 0; d < (int) mat.size(); ++d) {
            bool b = x >> d & 1;
            k = mat[d].select(k - cnt0[d] * b, b);
        }
        return k;
    }

    T quantile(int l, int r, int k) const {
        T ret = 0;
        for (int d = (int) mat.size() - 1; d >= 0; --d) {
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