#pragma once
#include <complex>
#include <vector>

constexpr double PI = 3.14159265358979323846;

template <typename T>
void bit_reverse(std::vector<T>& a) {
    int n = a.size();
    for (int i = 0, j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (i < j) std::swap(a[i], a[j]);
    }
}

void fft(std::vector<std::complex<double>>& a, bool ordered = true) {
    int n = a.size();
    for (int m = n; m > 1; m >>= 1) {
        double ang = 2.0 * PI / m;
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
    if (ordered) bit_reverse(a);
}

void ifft(std::vector<std::complex<double>>& a, bool ordered = true) {
    if (ordered) bit_reverse(a);
    int n = a.size();
    for (int m = 2; m <= n; m <<= 1) {
        double ang = -2.0 * PI / m;
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
std::vector<double> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int size = a.size() + b.size() - 1;
    int n = 1;
    while (n < size) n <<= 1;
    std::vector<std::complex<double>> na(a.begin(), a.end()), nb(b.begin(), b.end());
    na.resize(n);
    nb.resize(n);
    fft(na, false);
    fft(nb, false);
    for (int i = 0; i < n; ++i) na[i] *= nb[i];
    ifft(na, false);
    std::vector<double> ret(size);
    for (int i = 0; i < size; ++i) ret[i] = na[i].real() / n;
    return ret;
}