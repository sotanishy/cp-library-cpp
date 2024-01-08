#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

#include "subset_convolution.hpp"

/**
 * @brief Set Power Series
 */

template <typename mint, int N>
class SetPowerSeries : public std::vector<mint> {
    using SPS = SetPowerSeries<mint, N>;
    using Poly = std::array<mint, N + 1>;

   public:
    using std::vector<mint>::vector;
    using std::vector<mint>::operator=;

    // -- binary operation with scalar ---

    SPS& operator+=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] += rhs;
        return *this;
    }

    SPS& operator-=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= rhs;
        return *this;
    }

    SPS& operator*=(const mint& rhs) {
        for (auto& x : *this) x *= rhs;
        return *this;
    }

    SPS& operator/=(const mint& rhs) { return *this *= rhs.inv(); }

    SPS operator+(const mint& rhs) const { return SPS(*this) += rhs; }
    SPS operator-(const mint& rhs) const { return SPS(*this) -= rhs; }
    SPS operator*(const mint& rhs) const { return SPS(*this) *= rhs; }
    SPS operator/(const mint& rhs) const { return SPS(*this) /= rhs; }

    // --- binary operation with SPS ---

    SPS& operator+=(const SPS& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] += rhs[i];
        return *this;
    }

    SPS& operator-=(const SPS& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] -= rhs[i];
        return *this;
    }

    SPS& operator*=(const SPS& rhs) {
        *this = subset_convolution<mint, N>(*this, rhs);
        return *this;
    }

    SPS operator+(const SPS& rhs) const { return SPS(*this) += rhs; }
    SPS operator-(const SPS& rhs) const { return SPS(*this) -= rhs; }
    SPS operator*(const SPS& rhs) const { return SPS(*this) *= rhs; }

    // --- compositions ---

    SPS exp() const {
        assert((*this)[0] == mint(0));
        const int n = std::bit_width(std::bit_ceil(this->size())) - 1;
        SPS res(1 << n);
        res[0] = 1;
        for (int i = 0; i < n; ++i) {
            SPS a(this->begin() + (1 << i), this->begin() + (1 << (i + 1)));
            SPS b(res.begin(), res.begin() + (1 << i));
            a *= b;
            std::copy(a.begin(), a.end(), res.begin() + (1 << i));
        }
        return res;
    }
};