#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>

/**
 * @brief Arbitrary Mod int
 */
class ArbitraryModint {
    using mint = ArbitraryModint;

   public:
    static int& mod() {
        static int mod_ = 1;
        return mod_;
    }

    static void set_mod(int mod_) {
        assert(mod_ > 0);
        mod() = mod_;
    }

    ArbitraryModint(long long y = 0)
        : x(y >= 0 ? y % mod() : (y % mod() + mod()) % mod()) {}

    int val() const { return x; }

    mint& operator+=(const mint& r) {
        if ((x += r.x) >= mod()) x -= mod();
        return *this;
    }
    mint& operator-=(const mint& r) {
        if ((x += mod() - r.x) >= mod()) x -= mod();
        return *this;
    }
    mint& operator*=(const mint& r) {
        x = static_cast<int>(1LL * x * r.x % mod());
        return *this;
    }
    mint& operator/=(const mint& r) { return *this *= r.inv(); }

    bool operator==(const mint& r) const { return x == r.x; }

    mint operator+() const { return *this; }
    mint operator-() const { return mint(-x); }

    friend mint operator+(const mint& l, const mint& r) { return mint(l) += r; }
    friend mint operator-(const mint& l, const mint& r) { return mint(l) -= r; }
    friend mint operator*(const mint& l, const mint& r) { return mint(l) *= r; }
    friend mint operator/(const mint& l, const mint& r) { return mint(l) /= r; }

    mint inv() const {
        int a = x, b = mod(), u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return mint(u);
    }

    mint pow(long long n) const {
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