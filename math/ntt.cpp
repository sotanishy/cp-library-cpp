#include <bits/stdc++.h>
using namespace std;

template <long long mod, long long primitive_root>
struct NTT {
private:
    static long long mod_pow(long long n, long long p, long long m) {
        long long ret = 1;
        while (p > 0) {
            if (p & 1) ret = ret * n % m;
            n = n * n % m;
            p >>= 1;
        }
        return ret;
    }

    static pair<long long, long long> extgcd(long long a, long long b) {
        long long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;
        while (t) {
            long long q = s / t;
            s -= t * q;
            swap(s, t);
            sx -= tx * q;
            swap(sx, tx);
            sy -= ty * q;
            swap(sy, ty);
        }
        return {sx, sy};
    }

    static long long mod_inv(long long a, long long m) {
        long long inv = extgcd(a, m).first;
        return (inv % m + m) % m;
    }

    static void ntt(vector<long long>& f, int sign) {
        int n = f.size();
        if (n == 1) return;
        vector<long long> a, b;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(f[2 * i]);
            b.push_back(f[2 * i + 1]);
        }
        ntt(a, sign);
        ntt(b, sign);
        long long cur = 1;
        long long omega = mod_pow(primitive_root, (mod - 1) / n, mod);
        if (sign == -1) omega = mod_inv(omega, mod);
        for (int i = 0; i < n; i++) {
            f[i] = (a[i % (n / 2)] + cur * b[i % (n / 2)]) % mod;
            cur = cur * omega % mod;
        }
    }

public:
    static vector<long long> convolution(const vector<long long>& a, const vector<long long>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;

        vector<long long> na = a, nb = b;
        na.resize(n);
        nb.resize(n);
        ntt(na, 1);
        ntt(nb, 1);
        for (int i = 0; i < n; i++) na[i] = na[i] * nb[i] % mod;
        ntt(na, -1);
        na.resize(size);
        long long n_inv = mod_inv(n, mod);
        for (int i = 0; i < size; i++) na[i] = na[i] * n_inv % mod;
        return na;
    }
};