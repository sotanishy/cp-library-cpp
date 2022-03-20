#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

// #include "../../graph/chromatic_number.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <int mod>
class Modint {
    using mint = Modint;
    static_assert(mod > 0, "Modulus must be positive");

public:
    static constexpr int get_mod() noexcept { return mod; }

    constexpr Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}

    constexpr int value() const noexcept { return x; }

    constexpr mint& operator+=(const mint& r) noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }
    constexpr mint& operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod; return *this; }
    constexpr mint& operator*=(const mint& r) noexcept { x = static_cast<int>(1LL * x * r.x % mod); return *this; }
    constexpr mint& operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }

    constexpr mint operator-() const noexcept { return mint(-x); }

    constexpr mint operator+(const mint& r) const noexcept { return mint(*this) += r; }
    constexpr mint operator-(const mint& r) const noexcept { return mint(*this) -= r; }
    constexpr mint operator*(const mint& r) const noexcept { return mint(*this) *= r; }
    constexpr mint operator/(const mint& r) const noexcept { return mint(*this) /= r; }

    constexpr bool operator==(const mint& r) const noexcept { return x == r.x; }
    constexpr bool operator!=(const mint& r) const noexcept { return x != r.x; }

    constexpr mint inv() const noexcept {
        int a = x, b = mod, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return mint(u);
    }

    constexpr mint pow(long long n) const noexcept {
        mint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend std::ostream& operator<<(std::ostream& os, const mint& r) {
        return os << r.x;
    }

    friend std::istream& operator>>(std::istream& is, mint& r) {
        long long t;
        is >> t;
        r = mint(t);
        return is;
    }

private:
    int x;
};

template <typename mint>
class NTT {
public:
    NTT() = delete;

    static std::vector<mint> convolve(const std::vector<mint>& a, const std::vector<mint>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        std::vector<mint> na(a.begin(), a.end()), nb(b.begin(), b.end());
        na.resize(n);
        nb.resize(n);
        ntt(na, false);
        ntt(nb, false);
        for (int i = 0; i < n; ++i) na[i] *= nb[i];
        intt(na, false);
        na.resize(size);
        mint n_inv = mint(n).inv();
        for (int i = 0; i < size; ++i) na[i] *= n_inv;
        return na;
    }

    static void ntt(std::vector<mint>& a, bool ordered = true) {
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

    static void intt(std::vector<mint>& a, bool ordered = true) {
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

private:
    static constexpr mint get_primitive_root(int mod) {
        if (mod == 167772161) return 3;
        if (mod == 469762049) return 3;
        if (mod == 754974721) return 11;
        if (mod == 998244353) return 3;
        if (mod == 1224736769) return 3;
    }

    static constexpr int mod = mint::get_mod();
    static constexpr mint primitive_root = get_primitive_root(mod);

    static void bit_reverse(std::vector<mint>& a) {
        int n = a.size();
        for (int i = 0, j = 1; j < n - 1; ++j) {
            for (int k = n >> 1; k > (i ^= k); k >>= 1);
            if (i < j) std::swap(a[i], a[j]);
        }
    }
};

std::pair<long long, long long> extgcd(long long a, long long b) {
    long long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;
    while (t) {
        long long q = s / t;
        std::swap(s -= t * q, t);
        std::swap(sx -= tx * q, tx);
        std::swap(sy -= ty * q, ty);
    }
    return {sx, sy};
}

long long mod_inv(long long a, long long mod) {
    long long inv = extgcd(a, mod).first;
    return (inv % mod + mod) % mod;
}

long long garner(const std::vector<long long>& b, std::vector<long long> m, long long mod) {
    m.push_back(mod);
    int n = m.size();
    std::vector<long long> coeffs(n, 1);
    std::vector<long long> consts(n, 0);
    for (int k = 0; k < n - 1; ++k) {
        long long t = (b[k] - consts[k]) * mod_inv(coeffs[k], m[k]) % m[k];
        if (t < 0) t += m[k];
        for (int i = k + 1; i < n; ++i) {
            consts[i] = (consts[i] + t * coeffs[i]) % m[i];
            coeffs[i] = coeffs[i] * m[k] % m[i];
        }
    }
    return consts.back();
}

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
    const vector<long long> mods = {167772161, 469762049, 754974721};
    for (int i = 0; i < (int) c1.size(); ++i) {
        d[0] = c1[i].value();
        d[1] = c2[i].value();
        d[2] = c3[i].value();
        c[i] = garner(d, mods, mod);
    }
    return c;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    auto c = arbitrary_mod_convolution(a, b, 1e9+7);
    for (int i = 0; i < (int) c.size(); ++i) cout << c[i] << (i < (int)c.size()-1 ? " " : "\n");
}

