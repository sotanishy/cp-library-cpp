#pragma once
#include <random>
#include <string>
#include <vector>

class RollingHash {
   public:
    static long long generate_base() {
        std::random_device rd;
        std::mt19937_64 rng(rd());
        std::uniform_int_distribution<long long> rand(1, mod - 1);
        return rand(rng);
    }

    RollingHash() = default;
    RollingHash(const std::string& s, long long base)
        : RollingHash(std::vector<char>(s.begin(), s.end()), base) {}
    template <typename T>
    RollingHash(const std::vector<T>& s, long long base)
        : base(base), hashed(s.size() + 1), power(s.size() + 1) {
        power[0] = 1;
        for (int i = 0; i < (int)s.size(); ++i) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = add(mul(hashed[i], base), s[i]);
        }
    }

    long long query(int l, int r) const {
        return add(hashed[r], mod - mul(hashed[l], power[r - l]));
    }

    long long combine(long long h1, long long h2, int len2) const {
        return add(mul(h1, power[len2]), h2);
    }

    void push_back(char c) {
        power.push_back(mul(power.back(), base));
        hashed.push_back(add(mul(hashed.back(), base), c));
    }

   private:
    static constexpr long long mod = (1LL << 61) - 1;

    static inline long long add(long long a, long long b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline long long mul(long long a, long long b) {
        __int128_t c = (__int128_t)a * b;
        return add(c >> 61, c & mod);
    }

    const long long base;
    std::vector<long long> hashed, power;
};