#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fast Fourier Transform
 * @docs docs/math/fft.md
 */
struct FFT {
private:
    inline static const double PI = acos(-1);

    struct C {
        double real, imag;
        C() : real(0), imag(0) {}
        C(double real, double imag) : real(real), imag(imag) {}
        C operator+(const C& c) { return C(real + c.real, imag + c.imag); }
        C operator-(const C& c) { return C(real - c.real, imag - c.imag); }
        C operator*(const C& c) { return C(real * c.real - imag * c.imag, real * c.imag + imag * c.real); }
    };

    static void ufft(vector<C>& a) {
        int n = a.size();
        for (int m = n; m > 1; m >>= 1) {
            double ang = 2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; s++) {
                C w(1, 0);
                for (int i = 0; i < m / 2; i++) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2];
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = (l - r) * w;
                    w = w * omega;
                }
            }
        }
    }

    static void iufft(vector<C>& a) {
        int n = a.size();
        for (int m = 2; m <= n; m <<= 1) {
            double ang = -2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; s++) {
                C w(1, 0);
                for (int i = 0; i < m / 2; i++) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2] * w;
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = l - r;
                    w = w * omega;
                }
            }
        }
    }

public:
    template <typename T>
    static vector<double> convolution(const vector<T>& a, const vector<T>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        vector<C> na(n), nb(n);
        for (int i = 0; i < a.size(); i++) na[i].real = a[i];
        for (int i = 0; i < b.size(); i++) nb[i].real = b[i];
        ufft(na);
        ufft(nb);
        for (int i = 0; i < n; i++) na[i] = na[i] * nb[i];
        iufft(na);
        vector<double> ret(size);
        for (int i = 0; i < size; i++) ret[i] = na[i].real / n;
        return ret;
    }
};