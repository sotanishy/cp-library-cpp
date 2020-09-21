#include <bits/stdc++.h>
using namespace std;

template <int mod>
struct Modint {
    int x;

    Modint() : x(0) {}
    Modint(long long y) : x(y >= 0 ? y % mod : y % mod + mod) {}

    Modint& operator+=(const Modint& p) { if ((x += p.x) >= mod) x -= mod; return *this; }
    Modint& operator-=(const Modint& p) { if ((x += mod - p.x) >= mod) x -= mod; return *this; }
    Modint& operator*=(const Modint& p) { x = (int) (1LL * x * p.x % mod); return *this; }
    Modint& operator/=(const Modint& p) { *this *= p.inv(); return *this; }

    Modint operator-() const { return Modint(-x); }

    Modint operator+(const Modint& p) const { return Modint(*this) += p; }
    Modint operator-(const Modint& p) const { return Modint(*this) -= p; }
    Modint operator*(const Modint& p) const { return Modint(*this) *= p; }
    Modint operator/(const Modint& p) const { return Modint(*this) /= p; }

    bool operator==(const Modint& p) const { return x == p.x; }
    bool operator!=(const Modint& p) const { return x != p.x; }

    Modint inv() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return Modint(u);
    }

    Modint pow(long long n) const {
        Modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream& os, const Modint& p) {
        return os << p.x;
    }

    friend istream &operator>>(istream& is, Modint& a) {
        long long t;
        is >> t;
        a = Modint<mod>(t);
        return is;
    }
};