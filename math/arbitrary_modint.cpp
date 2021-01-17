#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

/*
 * @brief Arbitrary Mod int
 */
class ArbitraryModint {
    using mint = ArbitraryModint;

public:
    static int& get_mod() noexcept {
        static int mod = 1;
        return mod;
    }

    static void set_mod(int mod) {
        assert(mod > 0);
        get_mod() = mod;
    }

    ArbitraryModint(long long y = 0) noexcept : x(y >= 0 ? y % get_mod() : (y % get_mod() + get_mod()) % get_mod()) {}

    int value() const noexcept { return x; }

    mint& operator+=(const mint& r) noexcept { if ((x += r.x) >= get_mod()) x -= get_mod(); return *this; }
    mint& operator-=(const mint& r) noexcept { if ((x += get_mod() - r.x) >= get_mod()) x -= get_mod(); return *this; }
    mint& operator*=(const mint& r) noexcept { x = static_cast<int>(1LL * x * r.x % get_mod()); return *this; }
    mint& operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }

    mint operator-() const noexcept { return mint(-x); }

    mint operator+(const mint& r) const noexcept { return mint(*this) += r; }
    mint operator-(const mint& r) const noexcept { return mint(*this) -= r; }
    mint operator*(const mint& r) const noexcept { return mint(*this) *= r; }
    mint operator/(const mint& r) const noexcept { return mint(*this) /= r; }

    bool operator==(const mint& r) const noexcept { return x == r.x; }
    bool operator!=(const mint& r) const noexcept { return x != r.x; }

    mint inv() const noexcept {
        int a = x, b = get_mod(), u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return mint(u);
    }

    mint pow(long long n) const noexcept {
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