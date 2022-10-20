#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

// #include "../../math/modint.cpp"
// #include "../../math/polynomial.cpp"
// #include "../../math/multipoint_evaluation.cpp"

#include <bits/stdc++.h>
using namespace std;

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

using mint = Modint<998244353>;

template <typename mint>
class Polynomial : public std::vector<mint> {
    using Poly = Polynomial;

public:
    using std::vector<mint>::vector;
    using std::vector<mint>::operator=;

    Poly& operator+=(const Poly& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];
        return *this;
    }

    Poly& operator+=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] += rhs;
        return *this;
    }

    Poly& operator-=(const Poly& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] -= rhs[i];
        return *this;
    }

    Poly& operator-=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= rhs;
        return *this;
    }

    Poly& operator*=(const Poly& rhs) {
        *this = NTT<mint>::convolve(*this, rhs);
        return *this;
    }

    Poly& operator*=(const mint& rhs) {
        for (int i = 0; i < (int) this->size(); ++i) (*this)[i] *= rhs;
        return *this;
    }

    Poly& operator/=(Poly rhs) {
        if(this->size() < rhs.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - rhs.size() + 1;
        std::reverse(this->begin(), this->end());
        std::reverse(rhs.begin(), rhs.end());
        auto q = (*this) * rhs.inv();
        if ((int) q.size() > n) q.resize(n);
        std::reverse(q.begin(), q.end());
        return *this = q;
    }

    Poly& operator%=(const Poly& rhs) {
        return *this -= *this / rhs * rhs;
    }

    Poly& operator-() const {
        Poly ret(this->size());
        for (int i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];
        return ret;
    }

    Poly operator+(const Poly& rhs) const { return Poly(*this) += rhs; }
    Poly operator+(const mint& rhs) const { return Poly(*this) += rhs; }
    Poly operator-(const Poly& rhs) const { return Poly(*this) -= rhs; }
    Poly operator-(const mint& rhs) const { return Poly(*this) -= rhs; }
    Poly operator*(const Poly& rhs) const { return Poly(*this) *= rhs; }
    Poly operator*(const mint& rhs) const { return Poly(*this) *= rhs; }
    Poly operator/(const Poly& rhs) const { return Poly(*this) /= rhs; }
    Poly operator%(const Poly& rhs) const { return Poly(*this) %= rhs; }

    mint operator()(const mint& x) {
        mint y = 0, powx = 1;
        for (int i = 0; i < (int) this->size(); ++i) {
            y += (*this)[i] * powx;
            powx *= x;
        }
        return y;
    }

    Poly inv(int deg = -1) const {
        assert((*this)[0] != mint(0));
        if (deg == -1) deg = this->size();
        Poly ret({mint(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * mint(2) - ret * ret * this->pre(i << 1)).pre(i << 1);
        }
        return ret;
    }

    Poly exp(int deg = -1) const {
        assert((*this)[0] == mint(0));
        if (deg == -1) deg = this->size();
        Poly ret({mint(1)});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (this->pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret;
    }

    Poly log(int deg = -1) const {
        assert((*this)[0] == mint(1));
        if (deg == -1) deg = this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }

    Poly pow(long long k, int deg = -1) const {
        if (deg == -1) deg = this->size();
        Poly ret(*this);
        int cnt = 0;
        while (cnt < (int) ret.size() && ret[cnt] == mint(0)) ++cnt;
        if (cnt * k >= deg) return Poly(deg, mint(0));
        ret.erase(ret.begin(), ret.begin() + cnt);
        deg -= cnt * k;
        ret = ((ret * mint(ret[0]).inv()).log(deg) * mint(k)).pre(deg).exp(deg) * mint(ret[0]).pow(k);
        ret.insert(ret.begin(), cnt * k, mint(0));
        return ret;
    }

    Poly diff() const {
        Poly ret(std::max(0, (int) this->size() - 1));
        for (int i = 1; i <= (int) ret.size(); ++i) ret[i - 1] = (*this)[i] * mint(i);
        return ret;
    }

    Poly integral() const {
        Poly ret(this->size() + 1);
        ret[0] = mint(0);
        for (int i = 0; i < (int) ret.size() - 1; ++i) ret[i + 1] = (*this)[i] / mint(i + 1);
        return ret;
    }

private:
    Poly pre(int size) const { return Poly(this->begin(), this->begin() + std::min((int) this->size(), size)); }

    Poly rev(int deg = -1) const {
        Poly ret(*this);
        if(deg != -1) ret.resize(deg, 0);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

template <typename T>
std::vector<T> multipoint_evaluation(const Polynomial<T>& p, const std::vector<T>& x) {
    int m = x.size();
    int n = 1;
    while (n < m) n <<= 1;
    std::vector<Polynomial<T>> q(2 * n, {1});
    for (int i = 0; i < m; ++i) q[n + i] = {-x[i], 1};
    for (int i = n - 1; i > 0; --i) q[i] = q[2 * i] * q[2 * i + 1];
    q[1] = p % q[1];
    for (int i = 2; i < n + m; ++i) q[i] = q[i / 2] % q[i];
    std::vector<T> y(m);
    for (int i = 0; i < m; ++i) y[i] = q[n + i][0];
    return y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Polynomial<mint> f(N);
    for (int i = 0; i < N; ++i) cin >> f[i];
    vector<mint> p(M);
    for (int i = 0; i < M; ++i) cin >> p[i];
    auto y = multipoint_evaluation(f, p);
    for (int i = 0; i < M; ++i) cout << y[i] << (i < M - 1 ? " " : "\n");
}
