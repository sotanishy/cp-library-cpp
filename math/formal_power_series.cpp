#include <bits/stdc++.h>
#include "ntt.cpp"

/*
 * @brief Formal Power Series
 */
template <typename mint>
class FormalPowerSeries : public std::vector<mint> {
    using FPS = FormalPowerSeries;

public:
    using std::vector<mint>::vector;

    FPS& operator+=(const FPS& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];
        return *this;
    }

    FPS& operator+=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] += rhs;
        return *this;
    }

    FPS& operator-=(const FPS& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] -= rhs[i];
        return *this;
    }

    FPS& operator-=(const mint& rhs) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= rhs;
        return *this;
    }

    FPS& operator*=(const FPS& rhs) {
        *this = NTT<mint>::convolution(*this, rhs);
        return *this;
    }

    FPS& operator*=(const mint& rhs) {
        for (int i = 0; i < (int) this->size(); ++i) (*this)[i] *= rhs;
        return *this;
    }

    FPS& operator-() const {
        FPS ret(this->size());
        for (int i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];
        return ret;
    }

    FPS operator+(const FPS& rhs) const { return FPS(*this) += rhs; }
    FPS operator+(const mint& rhs) const { return FPS(*this) += rhs; }
    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs; }
    FPS operator-(const mint& rhs) const { return FPS(*this) -= rhs; }
    FPS operator*(const FPS& rhs) const { return FPS(*this) *= rhs; }
    FPS operator*(const mint& rhs) const { return FPS(*this) *= rhs; }

    FPS inv(int deg = -1) const {
        assert((*this)[0] != mint(0));
        if (deg == -1) deg = this->size();
        FPS ret({mint(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * mint(2) - ret * ret * this->pre(i << 1)).pre(i << 1);
        }
        return ret;
    }

    FPS exp(int deg = -1) const {
        assert((*this)[0] == mint(0));
        if (deg == -1) deg = this->size();
        FPS ret({mint(1)});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (this->pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret;
    }

    FPS log(int deg = -1) const {
        assert((*this)[0] == mint(1));
        if (deg == -1) deg = this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }

    FPS pow(long long k, int deg = -1) const {
        if (deg == -1) deg = this->size();
        FPS ret(*this);
        int cnt = 0;
        while (cnt < (int) ret.size() && ret[cnt] == mint(0)) ++cnt;
        if (cnt * k >= deg) return FPS(deg, mint(0));
        ret.erase(ret.begin(), ret.begin() + cnt);
        deg -= cnt * k;
        ret = ((ret * mint(ret[0]).inv()).log(deg) * mint(k)).pre(deg).exp(deg) * mint(ret[0]).pow(k);
        ret.insert(ret.begin(), cnt * k, mint(0));
        return ret;
    }

    FPS diff() const {
        FPS ret(max(0, (int) this->size() - 1));
        for (int i = 1; i <= (int) ret.size(); ++i) ret[i - 1] = (*this)[i] * mint(i);
        return ret;
    }

    FPS integral() const {
        FPS ret(this->size() + 1);
        ret[0] = mint(0);
        for (int i = 0; i < (int) ret.size() - 1; ++i) ret[i + 1] = (*this)[i] / mint(i + 1);
        return ret;
    }

private:
    FPS pre(int size) const { return FPS(this->begin(), this->begin() + min((int) this->size(), size)); }
};