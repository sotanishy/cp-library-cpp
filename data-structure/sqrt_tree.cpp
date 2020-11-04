#pragma once
#include <algorithm>
#include <vector>

/*
 * @brief Sqrt Tree
 * @docs docs/data-structure/sqrt_tree.md
 */
template <typename S>
class SqrtTree {
    using T = typename S::T;

public:
    SqrtTree() = default;
    explicit SqrtTree(const std::vector<T>& v) : v(v) {
        int n = v.size(), lg = 0;
        while ((1 << lg) < n) ++lg;
        on_layer.resize(lg + 1);
        int n_layer = 0;
        for (int i = lg; i > 1; i = (i + 1) / 2) {
            on_layer[i] = n_layer++;
            layer_lg.push_back(i);
        }
        for (int i = lg - 1; i >= 0; --i) on_layer[i] = std::max(on_layer[i], on_layer[i + 1]);
        pref.resize(n_layer, std::vector<T>(n));
        suf.resize(n_layer, std::vector<T>(n));
        btwn.resize(n_layer, std::vector<T>(1 << lg));

        for (int layer = 0; layer < n_layer; ++layer) {
            int prev_b_sz = 1 << layer_lg[layer];
            int b_sz = 1 << ((layer_lg[layer] + 1) / 2);
            int b_cnt = 1 << (layer_lg[layer] / 2);

            for (int l = 0; l < n; l += prev_b_sz) {
                int r = std::min(l + prev_b_sz, n);

                // calculate pref and suf
                for (int a = l; a < r; a += b_sz) {
                    int b = std::min(a + b_sz, r);
                    pref[layer][a] = v[a];
                    for (int i = a + 1; i < b; ++i) {
                        pref[layer][i] = S::op(pref[layer][i - 1], v[i]);
                    }
                    suf[layer][b - 1] = v[b - 1];
                    for (int i = b - 2; i >= a; --i) {
                        suf[layer][i] = S::op(v[i], suf[layer][i + 1]);
                    }
                }
                // calculate btwn
                for (int i = 0; i < b_cnt; ++i) {
                    T val = suf[layer][l + i * b_sz];
                    btwn[layer][l + i * b_cnt + i] = val;
                    for (int j = i + 1; j < b_cnt; ++j) {
                        val = S::op(val, suf[layer][l + j * b_sz]);
                        btwn[layer][l + i * b_cnt + j] = val;
                    }
                }
            }
        }
    }

    T fold(int l, int r) const {
        --r;
        if (l == r) return v[l];
        if (l + 1 == r) return S::op(v[l], v[r]);
        int layer = on_layer[32 - __builtin_clz(l ^ r)];
        int b_sz = 1 << ((layer_lg[layer] + 1) / 2);
        int b_cnt = 1 << (layer_lg[layer] / 2);
        int a = (l >> layer_lg[layer]) << layer_lg[layer];
        int lblock = (l - a) / b_sz + 1;
        int rblock = (r - a) / b_sz - 1;
        T val = suf[layer][l];
        if (lblock <= rblock) val = S::op(val, btwn[layer][a + lblock * b_cnt + rblock]);
        val = S::op(val, pref[layer][r]);
        return val;
    }

private:
    std::vector<int> layer_lg, on_layer;
    std::vector<T> v;
    std::vector<std::vector<T>> pref, suf, btwn;
};