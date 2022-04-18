#pragma once
#include <iostream>
#include <array>

class Nimber {
    using ull = unsigned long long;

public:
    Nimber(ull x = 0) noexcept : x(x) {}
    ull value() const noexcept { return x; }

    Nimber operator+(const Nimber& r) const noexcept { return x ^ r.x; }
    Nimber operator*(const Nimber& r) const noexcept {
        ull res = 0;
        for (int i = 0; i < 8; ++i) {
            ull a = (x >> (8 * i)) & 255;
            for (int j = 0; j < 8; ++j) {
                ull b = (r.x >> (8 * j)) & 255;
                res ^= precalc[i][j][small[a][b]];
            }
        }
        return res;
    }

    Nimber& operator+=(const Nimber& r) noexcept { return *this = *this + r; }
    Nimber& operator*=(const Nimber& r) noexcept { return *this = *this * r; }
    bool operator==(const Nimber& r) const noexcept { return x == r.x; }
    bool operator!=(const Nimber& r) const noexcept { return x != r.x; }
    bool operator<(const Nimber& r) const { return x < r.x; };
    bool operator>(const Nimber& r) const { return x > r.x; };
    bool operator<=(const Nimber& r) const { return x <= r.x; };
    bool operator>=(const Nimber& r) const { return x >= r.x; };
    friend std::ostream& operator<<(std::ostream& os, const Nimber& r) { return os << r.x; }
    friend std::istream& operator>>(std::istream& is, Nimber& r) {
        ull t;
        is >> t;
        r = Nimber(t);
        return is;
    }

private:
    const static std::array<std::array<ull, 256>, 256> small;
    const static std::array<std::array<std::array<ull, 256>, 8>, 8> precalc;

    static ull mul_naive(ull x, ull y) {
        if (x <= 1 || y <= 1) return x * y;
        for (int k = 5; ; --k) {
            int shift = 1 << k;
            ull mask = (1ULL << shift) - 1;
            if (std::max(x, y) > mask) {
                ull v00 = mul_naive(x & mask, y & mask);
                ull v01 = mul_naive(x & mask, y >> shift);
                ull v10 = mul_naive(x >> shift, y & mask);
                ull v11 = mul_naive(x >> shift, y >> shift);
                return v00 ^ ((v01 ^ v10 ^ v11) << shift) ^ mul_naive(v11, 1ULL << (shift - 1));
            }
        }
    }

    ull x;
};

const std::array<std::array<Nimber::ull, 256>, 256> Nimber::small = []() {
    std::array<std::array<ull, 256>, 256> ret;
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            ret[i][j] = mul_naive(i, j);
        }
    }
    return ret;
}();

const std::array<std::array<std::array<Nimber::ull, 256>, 8>, 8> Nimber::precalc = []() {
    std::array<std::array<std::array<ull, 256>, 8>, 8> ret;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            ull p = mul_naive(1ULL << (8 * i), 1ULL << (8 * j));
            for (int k = 0; k < 256; ++k) {
                ret[i][j][k] = mul_naive(p, k);
            }
        }
    }
    return ret;
}();
