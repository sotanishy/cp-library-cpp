#include <algorithm>
#include <cassert>
#include <iostream>

/**
 * @brief Gaussian Integer
 */

template <typename T>
struct GaussianInteger {
    using G = GaussianInteger<T>;

    T x, y;

    GaussianInteger() = default;
    explicit GaussianInteger(T x) : x(x), y(0) {}
    constexpr GaussianInteger(T x, T y) : x(x), y(y) {}

    constexpr G& operator+=(const G& r) noexcept {
        x += r.x, y += r.y;
        return *this;
    }
    constexpr G& operator-=(const G& r) noexcept {
        x -= r.x, y -= r.y;
        return *this;
    }
    constexpr G& operator*=(const G& r) noexcept {
        T nx = x * r.x - y * r.y;
        T ny = x * r.y + y * r.x;
        x = nx, y = ny;
        return *this;
    }

    constexpr G operator-() const noexcept { return G(-x, -y); }

    constexpr G operator+(const G& r) const noexcept { return G(*this) += r; }
    constexpr G operator-(const G& r) const noexcept { return G(*this) -= r; }
    constexpr G operator*(const G& r) const noexcept { return G(*this) *= r; }

    constexpr bool operator==(const G& r) const noexcept {
        return x == r.x && y == r.y;
    }
    constexpr bool operator!=(const G& r) const noexcept {
        return x != r.x || y != r.y;
    }

    constexpr G conj() const { return G(x, -y); }

    constexpr T norm() const { return x * x + y * y; }

    static constexpr std::pair<G, G> divmod(const G& a, const G& b) {
        assert(b.norm() > 0);
        if (a.norm() < b.norm()) return {G(0), G(a)};

        G num = a * b.conj();
        T den = b.norm();

        auto [qx, rx] = divmod(num.x, den);
        if (rx > den / 2) ++qx;
        auto [qy, ry] = divmod(num.y, den);
        if (ry > den / 2) ++qy;

        G q(qx, qy);
        return {q, a - q * b};
    }

    static constexpr G gcd(G a, G b) {
        while (b.norm() > 0) {
            auto [q, r] = divmod(a, b);
            a = b;
            b = r;
        }
        return a;
    }

    friend std::ostream& operator<<(std::ostream& os, const G& r) {
        return os << r.x << "+" << r.y << "i";
    }

   private:
    static constexpr std::pair<T, T> divmod(T a, T b) {
        assert(b > 0);
        T q = a / b;
        if (a == b * q) return {q, 0};
        if (a < 0) --q;
        return {q, a - b * q};
    }
};