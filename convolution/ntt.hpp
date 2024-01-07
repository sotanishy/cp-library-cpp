#pragma once
#include <vector>

constexpr int get_primitive_root(int mod) {
    if (mod == 167772161) return 3;
    if (mod == 469762049) return 3;
    if (mod == 754974721) return 11;
    if (mod == 998244353) return 3;
    if (mod == 1224736769) return 3;
}

template <typename mint>
void ntt(std::vector<mint>& a) {
    constexpr int mod = mint::mod();
    constexpr mint primitive_root = get_primitive_root(mod);

    const int n = a.size();
    for (int m = n; m > 1; m >>= 1) {
        mint omega = primitive_root.pow((mod - 1) / m);
        for (int s = 0; s < n / m; ++s) {
            mint w = 1;
            for (int i = 0; i < m / 2; ++i) {
                mint l = a[s * m + i];
                mint r = a[s * m + i + m / 2];
                a[s * m + i] = l + r;
                a[s * m + i + m / 2] = (l - r) * w;
                w *= omega;
            }
        }
    }
}

template <typename mint>
void intt(std::vector<mint>& a) {
    constexpr int mod = mint::mod();
    constexpr mint primitive_root = get_primitive_root(mod);

    const int n = a.size();
    for (int m = 2; m <= n; m <<= 1) {
        mint omega = primitive_root.pow((mod - 1) / m).inv();
        for (int s = 0; s < n / m; ++s) {
            mint w = 1;
            for (int i = 0; i < m / 2; ++i) {
                mint l = a[s * m + i];
                mint r = a[s * m + i + m / 2] * w;
                a[s * m + i] = l + r;
                a[s * m + i + m / 2] = l - r;
                w *= omega;
            }
        }
    }
}

template <typename mint>
std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
    const int size = a.size() + b.size() - 1;
    const int n = std::bit_ceil(size);
    a.resize(n);
    b.resize(n);
    ntt(a);
    ntt(b);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    intt(a);
    a.resize(size);
    mint n_inv = mint(n).inv();
    for (int i = 0; i < size; ++i) a[i] *= n_inv;
    return a;
}