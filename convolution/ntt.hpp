#pragma once
#include <vector>

constexpr int get_primitive_root(int mod) {
    if (mod == 167772161) return 3;
    if (mod == 469762049) return 3;
    if (mod == 754974721) return 11;
    if (mod == 998244353) return 3;
    if (mod == 1224736769) return 3;
}

template <typename T>
void bit_reverse(std::vector<T>& a) {
    int n = a.size();
    for (int i = 0, j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (i < j) std::swap(a[i], a[j]);
    }
}

template <typename mint>
void ntt(std::vector<mint>& a, bool ordered = true) {
    constexpr int mod = mint::get_mod();
    constexpr mint primitive_root = primitive_root(mod);

    int n = a.size();
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
    if (ordered) bit_reverse(a);
}

template <typename mint>
void intt(std::vector<mint>& a, bool ordered = true) {
    constexpr int mod = mint::get_mod();
    constexpr mint primitive_root = primitive_root(mod);

    if (ordered) bit_reverse(a);
    int n = a.size();
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
    int size = a.size() + b.size() - 1;
    int n = 1;
    while (n < size) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    intt(a, false);
    a.resize(size);
    mint n_inv = mint(n).inv();
    for (int i = 0; i < size; ++i) a[i] *= n_inv;
    return a;
}