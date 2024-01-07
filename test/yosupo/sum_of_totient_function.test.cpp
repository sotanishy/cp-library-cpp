#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

// #include "../../math/modint.hpp"

#include <bits/stdc++.h>
using namespace std;

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
std::pair<std::vector<mint>, std::vector<mint>> totient_summatory_table(long long n) {
    if (n == 0) return {{0}, {0}};
    const int b = std::min(n, (long long) 1e4);
    std::vector<mint> small(n/b + 1), large(b + 1);

    std::vector<int> totient(n/b + 1);
    std::iota(totient.begin(), totient.end(), 0);
    for (int i = 2; i <= n/b; ++i) {
        if (totient[i] != i) continue;
        for (int j = i; j <= n/b; j += i) {
            totient[j] = totient[j] / i * (i - 1);
        }
    }
    for (int i = 0; i < n/b; ++i) small[i+1] = small[i] + totient[i+1];

    for (int i = 1; i <= b; ++i) {
        mint k = n / i;
        large[i] = k * (k + 1) / 2;
    }
    for (long long i = b; i >= 1; --i) {
        for (long long l = 2; l <= n/i; ) {
            long long q = n/(i*l), r = n/(i*q) + 1;
            large[i] -= (i*l <= b ? large[i*l] : small[n/(i*l)]) * (r - l);
            l = r;
        }
    }
    return {small, large};
}

std::vector<int> euler_totient_table(int n) {
    std::vector<int> ret(n + 1);
    std::iota(ret.begin(), ret.end(), 0);
    for (int i = 2; i <= n; ++i) {
        if (ret[i] == i) {
            for (int j = i; j <= n; j += i) {
                ret[j] = ret[j] / i * (i - 1);
            }
        }
    }
    return ret;
}

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    auto [small, large] = totient_summatory_table<mint>(N);
    mint ans = large[1];
    cout << ans << endl;
}