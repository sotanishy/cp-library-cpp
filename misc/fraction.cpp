#pragma once
#include <numeric>

template <typename T>
struct Fraction {
    T num, den;
    Fraction(T num = 0, T den = 1) : num(num), den(den) { reduce(); }
    void reduce() {
        T g = std::gcd(num, den);
        num /= g, den /= g;
        if (den < 0) num = -num, den = -den;
    }
    Fraction& operator+=(const Fraction& rhs) {
        num = num*rhs.den + rhs.num*den;
        den *= rhs.den;
        reduce();
        return *this;
    }
    Fraction& operator-=(const Fraction& rhs) {
        num = num*rhs.den - rhs.num*den;
        den *= rhs.den;
        reduce();
        return *this;
    }
    Fraction& operator*=(const Fraction& rhs) {
        num *= rhs.num;
        den *= rhs.den;
        reduce();
        return *this;
    }
    Fraction& operator/=(const Fraction& rhs) {
        num *= rhs.den;
        den *= rhs.num;
        reduce();
        return *this;
    }
    Fraction operator-() const { return Fraction(-num, den); }
    Fraction operator+(const Fraction& rhs) const { return Fraction(*this) += rhs; }
    Fraction operator-(const Fraction& rhs) const { return Fraction(*this) -= rhs; }
    Fraction operator*(const Fraction& rhs) const { return Fraction(*this) *= rhs; }
    Fraction operator/(const Fraction& rhs) const { return Fraction(*this) /= rhs; }
    bool operator==(const Fraction& rhs) const { return num*rhs.den == rhs.num*den; }
    bool operator!=(const Fraction& rhs) const { return !(*this == rhs); }
    bool operator<(const Fraction& rhs) const { return num*rhs.den < rhs.num*den; };
    bool operator>(const Fraction& rhs) const { return num*rhs.den > rhs.num*den; };
    bool operator<=(const Fraction& rhs) const { return !(*this > rhs); };
    bool operator>=(const Fraction& rhs) const { return !(*this < rhs); };
    friend ostream &operator<<(ostream& os, const Fraction& p) { return os << p.num << "/" << p.den; }
};
