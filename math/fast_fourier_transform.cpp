#include <bits/stdc++.h>
using namespace std;

struct FastFourierTransform {
private:
    static void dft(vector<complex<double>>& f, int inv) {
        int n = f.size();
        if (n == 1) return;
        vector<complex<double>> a, b;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(f[2 * i]);
            b.push_back(f[2 * i + 1]);
        }
        dft(a, inv);
        dft(b, inv);
        complex<double> cur = 1, zeta = polar(1.0, inv * 2.0 * acos(-1) / n);
        for (int i = 0; i < n; i++) {
            f[i] = a[i % (n / 2)] + cur * b[i % (n / 2)];
            cur *= zeta;
        }
    }

public:
    template <typename T>
    static vector<double> multiply(vector<T> f, vector<T> g) {
        int n = 1;
        while (n < f.size() + g.size()) n *= 2;
        vector<complex<double>> nf(n), ng(n);
        for (int i = 0; i < f.size(); i++) {
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf, 1);
        dft(ng, 1);
        for (int i = 0; i < n; i++) nf[i] *= ng[i];
        dft(nf, -1);
        vector<double> ret(n);
        for (int i = 0; i < n; i++) ret[i] = nf[i].real() / n;
        return ret;
    }
};