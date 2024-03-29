#pragma once
#include <bit>
#include <complex>
#include <numbers>
#include <vector>

void fft(std::vector<std::complex<double>>& a) {
    const int n = a.size();
    for (int m = n; m > 1; m >>= 1) {
        double ang = 2.0 * std::numbers::pi / m;
        std::complex<double> omega(cos(ang), sin(ang));
        for (int s = 0; s < n / m; ++s) {
            std::complex<double> w(1, 0);
            for (int i = 0; i < m / 2; ++i) {
                auto l = a[s * m + i];
                auto r = a[s * m + i + m / 2];
                a[s * m + i] = l + r;
                a[s * m + i + m / 2] = (l - r) * w;
                w *= omega;
            }
        }
    }
}

void ifft(std::vector<std::complex<double>>& a) {
    const int n = a.size();
    for (int m = 2; m <= n; m <<= 1) {
        double ang = -2.0 * std::numbers::pi / m;
        std::complex<double> omega(cos(ang), sin(ang));
        for (int s = 0; s < n / m; ++s) {
            std::complex<double> w(1, 0);
            for (int i = 0; i < m / 2; ++i) {
                auto l = a[s * m + i];
                auto r = a[s * m + i + m / 2] * w;
                a[s * m + i] = l + r;
                a[s * m + i + m / 2] = l - r;
                w *= omega;
            }
        }
    }
}

template <typename T>
std::vector<double> convolution(const std::vector<T>& a,
                                const std::vector<T>& b) {
    const int size = a.size() + b.size() - 1;
    const int n = std::bit_ceil((unsigned int)size);
    std::vector<std::complex<double>> na(a.begin(), a.end()),
        nb(b.begin(), b.end());
    na.resize(n);
    nb.resize(n);
    fft(na);
    fft(nb);
    for (int i = 0; i < n; ++i) na[i] *= nb[i];
    ifft(na);
    std::vector<double> ret(size);
    for (int i = 0; i < size; ++i) ret[i] = na[i].real() / n;
    return ret;
}