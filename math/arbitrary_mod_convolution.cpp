#pragma once
#include <vector>
#include "garner.cpp"
#include "modint.cpp"
#include "ntt.cpp"

std::vector<int> arbitrary_mod_convolution(std::vector<int>& a, std::vector<int>& b, int mod) {
    using mint1 = Modint<167772161>;
    using mint2 = Modint<469762049>;
    using mint3 = Modint<754974721>;

    std::vector<mint1> a1(a.begin(), a.end()), b1(b.begin(), b.end());
    std::vector<mint2> a2(a.begin(), a.end()), b2(b.begin(), b.end());
    std::vector<mint3> a3(a.begin(), a.end()), b3(b.begin(), b.end());

    auto c1 = NTT<mint1>::convolve(a1, b1);
    auto c2 = NTT<mint2>::convolve(a2, b2);
    auto c3 = NTT<mint3>::convolve(a3, b3);

    std::vector<int> c(c1.size());
    std::vector<long long> d(3);
    const std::vector<long long> mods = {167772161, 469762049, 754974721};
    for (int i = 0; i < (int) c1.size(); ++i) {
        d[0] = c1[i].value();
        d[1] = c2[i].value();
        d[2] = c3[i].value();
        c[i] = garner(d, mods, mod);
    }
    return c;
}