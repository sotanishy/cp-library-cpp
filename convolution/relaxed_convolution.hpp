#pragma once
#include <vector>

#include "ntt.hpp"

template <typename mint>
class RelaxedConvolution {
   public:
    mint get(mint a, mint b) {
        f.push_back(a);
        g.push_back(b);
        ++n;
        int m = 1 << __builtin_ctz(n + 1);
        int s = 0, x = 1;
        while (x <= m) {
            calc(n - x, n, s, s + x);
            if (n + 1 == m && x == m >> 1) break;
            calc(s, s + x, n - x, n);
            s += x;
            x <<= 1;
        }
        return h[n - 1];
    }

   private:
    int n = 0;
    std::vector<mint> f, g, h;

    void calc(int lf, int rf, int lg, int rg) {
        if ((int)h.size() < rf + rg - 1) {
            h.resize(rf + rg - 1);
        }
        auto res =
            convolution(std::vector<mint>(f.begin() + lf, f.begin() + rf),
                        std::vector<mint>(g.begin() + lg, g.begin() + rg));
        for (int i = 0; i < (int)res.size(); ++i) {
            h[lf + lg + i] += res[i];
        }
    }
};