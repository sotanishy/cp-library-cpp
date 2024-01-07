#pragma once
#include <algorithm>
#include <iostream>

/**
 * @brief Mod int
 */
template <int m>
class Modint {
    using mint = Modint;
    static_assert(m > 0, "Modulus must be positive");

   public:
    static constexpr int mod() { return m; }

    constexpr Modint(long long y = 0) : x(y >= 0 ? y % m : (y % m + m) % m) {}

    constexpr int val() const { return x; }

    constexpr mint& operator+=(const mint& r) {
        if ((x += r.x) >= m) x -= m;
        return *this;
    }
    constexpr mint& operator-=(const mint& r) {
        if ((x += m - r.x) >= m) x -= m;
        return *this;
    }
    constexpr mint& operator*=(const mint& r) {
        x = static_cast<int>(1LL * x * r.x % m);
        return *this;
    }
    constexpr mint& operator/=(const mint& r) { return *this *= r.inv(); }

    constexpr bool operator==(const mint& r) const { return x == r.x; }

    constexpr mint operator+() const { return *this; }
    constexpr mint operator-() const { return mint(-x); }

    constexpr friend mint operator+(const mint& l, const mint& r) {
        return mint(l) += r;
    }
    constexpr friend mint operator-(const mint& l, const mint& r) {
        return mint(l) -= r;
    }
    constexpr friend mint operator*(const mint& l, const mint& r) {
        return mint(l) *= r;
    }
    constexpr friend mint operator/(const mint& l, const mint& r) {
        return mint(l) /= r;
    }

    constexpr mint inv() const {
        int a = x, b = m, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return mint(u);
    }

    constexpr mint pow(long long n) const {
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