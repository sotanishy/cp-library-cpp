#pragma once
#include <bits/stdc++.h>

template <int mod>
class Modint {
    static_assert(mod > 0, "Modulus must be positive");

public:
    static constexpr int get_mod() noexcept { return mod; }

    constexpr Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}

    constexpr int value() const noexcept { return x; }

    constexpr Modint& operator+=(const Modint& p) noexcept { if ((x += p.x) >= mod) x -= mod; return *this; }
    constexpr Modint& operator-=(const Modint& p) noexcept { if ((x += mod - p.x) >= mod) x -= mod; return *this; }
    constexpr Modint& operator*=(const Modint& p) noexcept { x = static_cast<int>(1LL * x * p.x % mod); return *this; }
    constexpr Modint& operator/=(const Modint& p) noexcept { *this *= p.inv(); return *this; }

    constexpr Modint operator-() const noexcept { return Modint(-x); }

    constexpr Modint operator+(const Modint& p) const noexcept { return Modint(*this) += p; }
    constexpr Modint operator-(const Modint& p) const noexcept { return Modint(*this) -= p; }
    constexpr Modint operator*(const Modint& p) const noexcept { return Modint(*this) *= p; }
    constexpr Modint operator/(const Modint& p) const noexcept { return Modint(*this) /= p; }

    constexpr bool operator==(const Modint& p) const noexcept { return x == p.x; }
    constexpr bool operator!=(const Modint& p) const noexcept { return x != p.x; }

    constexpr Modint inv() const noexcept {
        int a = x, b = mod, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return Modint(u);
    }

    constexpr Modint pow(long long n) const noexcept {
        Modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream& os, const Modint& p) {
        return os << p.x;
    }

    friend std::istream &operator>>(std::istream& is, Modint& a) {
        long long t;
        is >> t;
        a = Modint<mod>(t);
        return is;
    }

private:
    int x;
};