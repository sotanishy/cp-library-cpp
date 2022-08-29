#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

// #include "../../data-structure/sliding_window_aggregation.cpp"
// #include "../../math/modint.cpp"

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

using mint = Modint<998244353>;

struct M {
    using T = pair<mint, mint>;
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    FoldableDeque<M> que;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            que.push_front({a, b});
        } else if (t == 1) {
            int a, b;
            cin >> a >> b;
            que.push_back({a, b});
        } else if (t == 2) {
            que.pop_front();
        } else if (t == 3) {
            que.pop_back();
        } else {
            int x;
            cin >> x;
            pair<mint, mint> p = que.empty() ? make_pair(1, 0) : que.fold();
            cout << p.first * x + p.second << "\n";
        }
    }
}