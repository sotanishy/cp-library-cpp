#pragma once
#include <algorithm>
#include <vector>

template <typename M>
class SqrtTree {
    using T = typename M::T;

public:
    SqrtTree() = default;
    explicit SqrtTree(const std::vector<T>& vs) : n(vs.size()), v(vs) {
        int size = 1;
        lg = 0;
        while (size < (int) v.size()) size <<= 1, ++lg;
        bitlen.resize(size);
        for (int i = 1; i < size; ++i) bitlen[i] = bitlen[i >> 1] + 1;
        on_layer.resize(lg + 1);
        for (int i = lg; i > 1; i = (i + 1) / 2) {
            on_layer[i] = layer_lg.size();
            layer_lg.push_back(i);
        }
        for (int i = lg - 1; i >= 0; --i) on_layer[i] = std::max(on_layer[i], on_layer[i + 1]);
        v.resize(size);
        pref.resize(layer_lg.size(), std::vector<T>(size));
        suf.resize(layer_lg.size(), std::vector<T>(size));
        btwn.resize(layer_lg.size(), std::vector<T>(size));
        build(0, 0, n);
    }

    T fold(int l, int r) const {
        --r;
        if (l == r) return v[l];
        if (l + 1 == r) return M::op(v[l], v[r]);
        int layer = on_layer[bitlen[l ^ r]];
        int b_sz = 1 << ((layer_lg[layer] + 1) / 2);
        int b_cnt = 1 << (layer_lg[layer] / 2);
        int a = (l >> layer_lg[layer]) << layer_lg[layer];
        int lblock = (l - a) / b_sz + 1;
        int rblock = (r - a) / b_sz - 1;
        T val = suf[layer][l];
        if (lblock <= rblock) {
            val = M::op(val, btwn[layer][a + lblock * b_cnt + rblock]);
        }
        val = M::op(val, pref[layer][r]);
        return val;
    }

private:
    int n, lg;
    std::vector<int> bitlen, layer_lg, on_layer;
    std::vector<T> v;
    std::vector<std::vector<T>> pref, suf, btwn;

    void build(int layer, int l, int r) {
        if (layer >= (int) layer_lg.size()) return;
        int b_sz = 1 << ((layer_lg[layer] + 1) / 2);
        for (int a = l; a < r; a += b_sz) {
            int b = std::min(a + b_sz, r);
            // build a block
            pref[layer][a] = v[a];
            for (int i = a + 1; i < b; ++i) {
                pref[layer][i] = M::op(pref[layer][i - 1], v[i]);
            }
            suf[layer][b - 1] = v[b - 1];
            for (int i = b - 2; i >= a; --i) {
                suf[layer][i] = M::op(v[i], suf[layer][i + 1]);
            }
            build(layer + 1, a, b);
        }
        // build btwn
        int b_cnt = 1 << (layer_lg[layer] / 2);
        for (int i = 0; i < b_cnt; ++i) {
            T val = M::id;
            for (int j = i; j < b_cnt; ++j) {
                val = M::op(val, suf[layer][l + j * b_sz]);
                btwn[layer][l + i * b_cnt + j] = val;
            }
        }
    }
};