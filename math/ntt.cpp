#include <bits/stdc++.h>

/*
 * @brief Number Theoretic Transform
 * @docs docs/math/ntt.md
 */
template <typename mint, int primitive_root>
class NTT {
    static constexpr int mod = mint::get_mod();

public:
    NTT() = delete;

    static std::vector<mint> convolution(const std::vector<mint>& a, const std::vector<mint>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        std::vector<mint> na(n), nb(n);
        for (int i = 0; i < (int) a.size(); ++i) na[i] = a[i];
        for (int i = 0; i < (int) b.size(); ++i) nb[i] = b[i];
        untt(na);
        untt(nb);
        for (int i = 0; i < n; ++i) na[i] *= nb[i];
        iuntt(na);
        na.resize(size);
        mint n_inv = mint(n).inv();
        for (int i = 0; i < size; ++i) na[i] *= n_inv;
        return na;
    }

private:
    static void untt(std::vector<mint>& a) {
        int n = a.size();
        for (int m = n; m > 1; m >>= 1) {
            mint omega = mint(primitive_root).pow((mod - 1) / m);
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

    static void iuntt(std::vector<mint>& a) {
        int n = a.size();
        for (int m = 2; m <= n; m <<= 1) {
            mint omega = mint(primitive_root).pow((mod - 1) / m).inv();
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
};

// <167772161, 3>
// <469762049, 3>
// <754974721, 11>
// <998244353, 3>
// <1224736769, 3>