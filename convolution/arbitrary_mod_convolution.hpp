#pragma once
#include <vector>

#include "../math/garner.cpp"
#include "../math/modint.hpp"
#include "ntt.hpp"

std::vector<int> convolution(const std::vector<int>& a,
                             const std::vector<int>& b, int mod) {
    using mint1 = Modint<167772161>;
    using mint2 = Modint<469762049>;
    using mint3 = Modint<754974721>;

    std::vector<mint1> a1(a.begin(), a.end()), b1(b.begin(), b.end());
    std::vector<mint2> a2(a.begin(), a.end()), b2(b.begin(), b.end());
    std::vector<mint3> a3(a.begin(), a.end()), b3(b.begin(), b.end());

    auto c1 = convolution(a1, b1);
    auto c2 = convolution(a2, b2);
    auto c3 = convolution(a3, b3);

    std::vector<int> c(c1.size());
    std::vector<long long> d(3);
    const std::vector<long long> mods = {167772161, 469762049, 754974721};
    for (int i = 0; i < (int)c1.size(); ++i) {
        d[0] = c1[i].val();
        d[1] = c2[i].val();
        d[2] = c3[i].val();
        c[i] = garner(d, mods, mod);
    }
    return c;
}