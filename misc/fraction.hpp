#pragma once
#include <cmath>
#include <iostream>
#include <numeric>

/**
 * @brief Fraction
 */
template <typename T>
struct Fraction {
    T num, den;
    Fraction(T num = 0, T den = 1) : num(num), den(den) { reduce(); }
    void reduce() {
        T g = std::gcd(num, den);
        num /= g, den /= g;
        if (den < 0) num = -num, den = -den;
    }
    constexpr Fraction& operator+=(const Fraction& r) {
        num = num * r.den + r.num * den;
        den *= r.den;
        reduce();
        return *this;
    }
    constexpr Fraction& operator-=(const Fraction& r) {
        num = num * r.den - r.num * den;
        den *= r.den;
        reduce();
        return *this;
    }
    constexpr Fraction& operator*=(const Fraction& r) {
        num *= r.num;
        den *= r.den;
        reduce();
        return *this;
    }
    constexpr Fraction& operator/=(const Fraction& r) {
        num *= r.den;
        den *= r.num;
        reduce();
        return *this;
    }

    constexpr bool operator==(const Fraction& r) const {
        return num * r.den == r.num * den;
    }
    constexpr auto operator<=>(const Fraction& r) const {
        return num * r.den <=> r.num * den;
    }

    constexpr Fraction operator+() const { return *this; }
    constexpr Fraction operator-() const { return Fraction(-num, den); }

    constexpr friend Fraction operator+(const Fraction& l, const Fraction& r) {
        return Fraction(l) += r;
    }
    constexpr friend Fraction operator-(const Fraction& l, const Fraction& r) {
        return Fraction(l) -= r;
    }
    constexpr friend Fraction operator*(const Fraction& l, const Fraction& r) {
        return Fraction(l) *= r;
    }
    constexpr friend Fraction operator/(const Fraction& l, const Fraction& r) {
        return Fraction(l) /= r;
    }

    friend ostream& operator<<(ostream& os, const Fraction& p) {
        return os << p.num << "/" << p.den;
    }
};