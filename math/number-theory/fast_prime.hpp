#pragma once
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

namespace fast_prime {

class LargeModint {
    using mint = LargeModint;

   public:
    static long long& get_mod() {
        static long long mod = 1;
        return mod;
    }

    static void set_mod(long long mod) { get_mod() = mod; }

    LargeModint(long long y = 0)
        : x(y >= 0 ? y % get_mod() : (y % get_mod() + get_mod()) % get_mod()) {}

    long long val() const { return x; }

    mint& operator+=(const mint& r) {
        if ((x += r.x) >= get_mod()) x -= get_mod();
        return *this;
    }
    mint& operator-=(const mint& r) {
        if ((x += get_mod() - r.x) >= get_mod()) x -= get_mod();
        return *this;
    }
    mint& operator*=(const mint& r) {
        x = static_cast<long long>((__int128_t)x * r.x % get_mod());
        return *this;
    }

    mint operator-() const { return mint(-x); }

    mint operator+(const mint& r) const { return mint(*this) += r; }
    mint operator-(const mint& r) const { return mint(*this) -= r; }
    mint operator*(const mint& r) const { return mint(*this) *= r; }

    bool operator==(const mint& r) const { return x == r.x; }

    mint pow(long long n) const {
        mint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

   private:
    long long x;
};

using mint = LargeModint;

bool is_prime(long long n) {
    if (n == 2) return true;
    if (n == 1 || n % 2 == 0) return false;

    mint::set_mod(n);
    int s = 0;
    long long d = n - 1;
    while (!(d & 1)) d >>= 1, ++s;
    // https://miller-rabin.appspot.com/
    for (mint a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a == 0) break;
        mint y = a.pow(d);
        if (y == 1) continue;
        bool probably_prime = false;
        for (int r = 0; r < s; ++r) {
            if (y == n - 1) {
                probably_prime = true;
                break;
            }
            y *= y;
        }
        if (!probably_prime) return false;
    }
    return true;
}

unsigned long long randll(long long lb, long long ub) {
    static std::random_device rd;
    static std::mt19937_64 rng(rd());
    std::uniform_int_distribution<long long> rand(lb, ub - 1);
    return rand(rng);
}

long long pollards_rho(long long n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;

    mint::set_mod(n);
    while (true) {
        mint x = randll(2, n);
        mint y = x;
        mint c = randll(1, n);
        long long d = 1;
        while (d == 1) {
            x = x * x + c;
            y = y * y + c;
            y = y * y + c;
            d = std::gcd((x - y).val(), n);
        }
        if (d < n) return d;
    }
}

std::vector<long long> prime_factor(long long n) {
    if (n <= 1) return {};
    long long p = pollards_rho(n);
    if (p == n) return {p};
    auto l = prime_factor(p);
    auto r = prime_factor(n / p);
    std::ranges::copy(r, std::back_inserter(l));
    return l;
}

}  // namespace fast_prime