#pragma once
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

/*
 * @brief Fast Fourier Transform
 * @docs docs/math/fft.md
 */
class FFT {
    using C = std::complex<double>;

public:
    FFT() = delete;

    template <typename T>
    static std::vector<double> convolve(const std::vector<T>& a, const std::vector<T>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        std::vector<C> na(a.begin(), a.end()), nb(b.begin(), b.end());
        na.resize(n);
        nb.resize(n);
        fft(na, false);
        fft(nb, false);
        for (int i = 0; i < n; ++i) na[i] = na[i] * nb[i];
        ifft(na, false);
        std::vector<double> ret(size);
        for (int i = 0; i < size; ++i) ret[i] = na[i].real() / n;
        return ret;
    }

    static void fft(std::vector<C>& a, bool ordered = true) {
        int n = a.size();
        for (int m = n; m > 1; m >>= 1) {
            double ang = 2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; ++s) {
                C w(1, 0);
                for (int i = 0; i < m / 2; ++i) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2];
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = (l - r) * w;
                    w *= omega;
                }
            }
        }
        if (ordered) bit_reverse(a);
    }

    static void ifft(std::vector<C>& a, bool ordered = true) {
        if (ordered) bit_reverse(a);
        int n = a.size();
        for (int m = 2; m <= n; m <<= 1) {
            double ang = -2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; ++s) {
                C w(1, 0);
                for (int i = 0; i < m / 2; ++i) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2] * w;
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = l - r;
                    w *= omega;
                }
            }
        }
    }

private:
    static constexpr double PI = 3.14159265358979323846;

    static void bit_reverse(std::vector<C>& a) {
        int n = a.size();
        for (int i = 0, j = 1; j < n - 1; ++j) {
            for (int k = n >> 1; k > (i ^= k); k >>= 1);
            if (i < j) std::swap(a[i], a[j]);
        }
    }
};