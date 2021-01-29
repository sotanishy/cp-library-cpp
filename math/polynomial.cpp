#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "ntt.cpp"

template <typename mint>
class Polynomial : public std::vector<mint> {
    using Poly = Polynomial;

public:
    using std::vector<mint>::vector;
    using std::vector<mint>::operator=;

    Poly& operator+=(const Poly& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];
        return *this;
    }

    Poly& operator+=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] += rhs;
        return *this;
    }

    Poly& operator-=(const Poly& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] -= rhs[i];
        return *this;
    }

    Poly& operator-=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= rhs;
        return *this;
    }

    Poly& operator*=(const Poly& rhs) {
        *this = NTT<mint>::convolve(*this, rhs);
        return *this;
    }

    Poly& operator*=(const mint& rhs) {
        for (int i = 0; i < (int) this->size(); ++i) (*this)[i] *= rhs;
        return *this;
    }

    Poly& operator/=(const Poly& rhs) {
        if(this->size() < rhs.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - rhs.size() + 1;
        return *this = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);
    }

    Poly& operator%=(const Poly& rhs) {
        return *this -= *this / rhs * rhs;
    }

    Poly& operator-() const {
        Poly ret(this->size());
        for (int i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];
        return ret;
    }

    Poly operator+(const Poly& rhs) const { return Poly(*this) += rhs; }
    Poly operator+(const mint& rhs) const { return Poly(*this) += rhs; }
    Poly operator-(const Poly& rhs) const { return Poly(*this) -= rhs; }
    Poly operator-(const mint& rhs) const { return Poly(*this) -= rhs; }
    Poly operator*(const Poly& rhs) const { return Poly(*this) *= rhs; }
    Poly operator*(const mint& rhs) const { return Poly(*this) *= rhs; }
    Poly operator/(const Poly& rhs) const { return Poly(*this) /= rhs; }
    Poly operator%(const Poly& rhs) const { return Poly(*this) %= rhs; }

    mint operator()(const mint& x) {
        mint y = 0, powx = 1;
        for (int i = 0; i < (int) this->size(); ++i) {
            y += (*this)[i] * powx;
            powx *= x;
        }
        return y;
    }

    Poly inv(int deg = -1) const {
        assert((*this)[0] != mint(0));
        if (deg == -1) deg = this->size();
        Poly ret({mint(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * mint(2) - ret * ret * this->pre(i << 1)).pre(i << 1);
        }
        return ret;
    }

    Poly exp(int deg = -1) const {
        assert((*this)[0] == mint(0));
        if (deg == -1) deg = this->size();
        Poly ret({mint(1)});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (this->pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret;
    }

    Poly log(int deg = -1) const {
        assert((*this)[0] == mint(1));
        if (deg == -1) deg = this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }

    Poly pow(long long k, int deg = -1) const {
        if (deg == -1) deg = this->size();
        Poly ret(*this);
        int cnt = 0;
        while (cnt < (int) ret.size() && ret[cnt] == mint(0)) ++cnt;
        if (cnt * k >= deg) return Poly(deg, mint(0));
        ret.erase(ret.begin(), ret.begin() + cnt);
        deg -= cnt * k;
        ret = ((ret * mint(ret[0]).inv()).log(deg) * mint(k)).pre(deg).exp(deg) * mint(ret[0]).pow(k);
        ret.insert(ret.begin(), cnt * k, mint(0));
        return ret;
    }

    Poly diff() const {
        Poly ret(std::max(0, (int) this->size() - 1));
        for (int i = 1; i <= (int) ret.size(); ++i) ret[i - 1] = (*this)[i] * mint(i);
        return ret;
    }

    Poly integral() const {
        Poly ret(this->size() + 1);
        ret[0] = mint(0);
        for (int i = 0; i < (int) ret.size() - 1; ++i) ret[i + 1] = (*this)[i] / mint(i + 1);
        return ret;
    }

private:
    Poly pre(int size) const { return Poly(this->begin(), this->begin() + std::min((int) this->size(), size)); }
    Poly rev() const { return Poly(this->rbegin(), this->rend()); }
};