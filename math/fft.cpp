#include <bits/stdc++.h>
using namespace std;

struct FFT {
private:
    inline static const double PI = acos(-1);

    static void dft(vector<complex<double>>& f, int sign) {
        int n = f.size();
        if (n == 1) return;
        vector<complex<double>> a, b;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(f[2 * i]);
            b.push_back(f[2 * i + 1]);
        }
        dft(a, sign);
        dft(b, sign);
        complex<double> cur = 1, zeta = polar(1.0, sign * 2.0 * PI / n);
        for (int i = 0; i < n; i++) {
            f[i] = a[i % (n / 2)] + cur * b[i % (n / 2)];
            cur *= zeta;
        }
    }

public:
    template <typename T>
    static vector<double> convolution(const vector<T>& a, const vector<T>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        vector<complex<double>> na(n), nb(n);
        for (int i = 0; i < a.size(); i++) {
            na[i] = a[i];
            nb[i] = b[i];
        }
        dft(na, 1);
        dft(nb, 1);
        for (int i = 0; i < n; i++) na[i] *= nb[i];
        dft(na, -1);
        vector<double> ret(size);
        for (int i = 0; i < size; i++) ret[i] = na[i].real() / n;
        return ret;
    }
};