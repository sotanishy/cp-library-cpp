#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

#include "../convolution/ntt.hpp"

template <typename mint>
class Polynomial : public std::vector<mint> {
    using Poly = Polynomial;

   public:
    using std::vector<mint>::vector;
    using std::vector<mint>::operator=;

    Poly pre(int size) const {
        return Poly(this->begin(),
                    this->begin() + std::min((int)this->size(), size));
    }

    Poly rev(int deg = -1) const {
        auto ret = *this;
        if (deg != -1) ret.resize(deg, 0);
        return Poly(ret.rbegin(), ret.rend());
    }

    void trim() {
        while (!this->empty() && this->back() == 0) this->pop_back();
    }

    // --- unary operation ---

    Poly& operator-() const {
        auto ret = *this;
        for (auto& x : ret) x = -x;
        return ret;
    }

    // -- binary operation with scalar ---

    Poly& operator+=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] += rhs;
        return *this;
    }

    Poly& operator-=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= rhs;
        return *this;
    }

    Poly& operator*=(const mint& rhs) {
        for (auto& x : *this) x *= rhs;
        return *this;
    }

    Poly& operator/=(const mint& rhs) { return *this *= rhs.inv(); }

    Poly operator+(const mint& rhs) const { return Poly(*this) += rhs; }
    Poly operator-(const mint& rhs) const { return Poly(*this) -= rhs; }
    Poly operator*(const mint& rhs) const { return Poly(*this) *= rhs; }
    Poly operator/(const mint& rhs) const { return Poly(*this) /= rhs; }

    // --- binary operation with polynomial ---

    Poly& operator+=(const Poly& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] += rhs[i];
        return *this;
    }

    Poly& operator-=(const Poly& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] -= rhs[i];
        return *this;
    }

    Poly& operator*=(const Poly& rhs) {
        *this = convolution(*this, rhs);
        return *this;
        // // naive convolution O(N^2)
        // std::vector<mint> res(this->size() + rhs.size() - 1);
        // for (int i = 0; i < (int)this->size(); ++i) {
        //     for (int j = 0; j < (int)rhs.size(); ++j) {
        //         res[i + j] += (*this)[i] * rhs[j];
        //     }
        // }
        // return *this = res;
    }

    Poly& operator/=(const Poly& rhs) {
        if (this->size() < rhs.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - rhs.size() + 1;
        return *this = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);
    }

    Poly& operator%=(const Poly& rhs) {
        *this -= *this / rhs * rhs;
        trim();
        return *this;
    }

    std::pair<Poly, Poly> divmod(const Poly& rhs) {
        auto q = *this / rhs;
        auto r = *this - q * rhs;
        r.trim();
        return {q, r};
    }

    Poly operator+(const Poly& rhs) const { return Poly(*this) += rhs; }
    Poly operator-(const Poly& rhs) const { return Poly(*this) -= rhs; }
    Poly operator*(const Poly& rhs) const { return Poly(*this) *= rhs; }
    Poly operator/(const Poly& rhs) const { return Poly(*this) /= rhs; }
    Poly operator%(const Poly& rhs) const { return Poly(*this) %= rhs; }

    // --- shift operation ---

    Poly operator<<(int n) const {
        auto ret = *this;
        ret.insert(ret.begin(), n, 0);
        return ret;
    }

    Poly operator>>(int n) const {
        if ((int)this->size() <= n) return {};
        auto ret = *this;
        ret.erase(ret.begin(), ret.begin() + n);
        return ret;
    }

    // --- evaluation ---

    mint operator()(const mint& x) {
        mint y = 0, powx = 1;
        for (int i = 0; i < (int)this->size(); ++i) {
            for (auto c : *this) {
                y += c * powx;
                powx *= x;
            }
            return y;
        }
    }

    // --- other operations ---

    Poly inv(int deg = -1) const {
        assert((*this)[0] != mint(0));
        if (deg == -1) deg = this->size();
        Poly res = {(*this)[0].inv()};
        for (int d = 1; d < deg; d <<= 1) {
            auto f = pre(2 * d);
            auto g = res;
            f.resize(2 * d);
            g.resize(2 * d);

            // g_{n+1} = g_n * (2 - g_n * f) mod x^{2^{n+1}}

            ntt(f);
            ntt(g);
            for (int i = 0; i < 2 * d; ++i) f[i] *= g[i];
            intt(f);

            for (int i = 0; i < d; ++i) f[i] = 0;

            ntt(f);
            for (int i = 0; i < 2 * d; ++i) f[i] *= g[i];
            intt(f);

            res.resize(2 * d);
            auto coef = mint(2 * d).inv().pow(2);
            for (int i = d; i < 2 * d; ++i) res[i] = -f[i] * coef;
        }
        return res.pre(deg);
    }

    Poly exp(int deg = -1) const {
        assert((*this)[0] == mint(0));
        if (deg == -1) deg = this->size();
        Poly ret = {mint(1)};
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (this->pre(i << 1) + mint(1) - ret.log(i << 1)))
                      .pre(i << 1);
        }
        return ret;
    }

    Poly log(int deg = -1) const {
        assert((*this)[0] == mint(1));
        if (deg == -1) deg = this->size();
        return (diff() * inv(deg)).pre(deg - 1).integral();
    }

    Poly pow(long long k, int deg = -1) const {
        if (k == 0) return {1};
        if (deg == -1) deg = this->size();
        auto ret = *this;
        int cnt0 = 0;
        while (cnt0 < (int)ret.size() && ret[cnt0] == 0) ++cnt0;
        if (cnt0 > (deg - 1) / k) return {};
        ret = ret >> cnt0;
        deg -= cnt0 * k;
        ret = ((ret / ret[0]).log(deg) * k).exp(deg) * ret[0].pow(k);
        ret = ret << (cnt0 * k);
        return ret;
    }

    Poly diff() const {
        Poly ret(std::max(0, (int)this->size() - 1));
        for (int i = 1; i <= (int)ret.size(); ++i)
            ret[i - 1] = (*this)[i] * mint(i);
        return ret;
    }

    Poly integral() const {
        Poly ret(this->size() + 1);
        ret[0] = mint(0);
        for (int i = 0; i < (int)ret.size() - 1; ++i)
            ret[i + 1] = (*this)[i] / mint(i + 1);
        return ret;
    }

    Poly taylor_shift(long long c) const {
        const int n = this->size();
        std::vector<mint> fact(n, 1), fact_inv(n, 1);
        for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;
        fact_inv[n - 1] = mint(1) / fact[n - 1];
        for (int i = n - 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;

        auto ret = *this;
        Poly e(n + 1);
        e[0] = 1;
        mint p = c;
        for (int i = 1; i < n; ++i) {
            ret[i] *= fact[i];
            e[i] = p * fact_inv[i];
            p *= c;
        }
        ret = (ret.rev() * e).pre(n).rev();
        for (int i = n - 1; i >= 0; --i) {
            ret[i] *= fact_inv[i];
        }
        return ret;
    }
};
