#include <bits/stdc++.h>
using namespace std;

template <long long mod, long long primitive_root>
struct NTT {
private:
    static long long mod_pow(long long n, long long p) {
        long long ret = 1;
        while (p > 0) {
            if (p & 1) ret = ret * n % mod;
            n = n * n % mod;
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

    static long long mod_inv(long long a) {
        long long inv = extgcd(a, mod).first;
        return (inv % mod + mod) % mod;
    }

    static void untt(vector<long long>& a) {
        int n = a.size();
        for (int m = n; m > 1; m >>= 1) {
            long long omega = mod_pow(primitive_root, (mod - 1) / m);
            for (int s = 0; s < n / m; s++) {
                long long w = 1;
                for (int i = 0; i < m / 2; i++) {
                    long long l = a[s * m + i];
                    long long r = a[s * m + i + m / 2];
                    a[s * m + i] = (l + r) % mod;
                    a[s * m + i + m / 2] = (l - r + mod) * w % mod;
                    w = w * omega % mod;
                }
            }
        }
    }

    static void iuntt(vector<long long>& a) {
        int n = a.size();
        for (int m = 2; m <= n; m <<= 1) {
            long long omega = mod_inv(mod_pow(primitive_root, (mod - 1) / m));
            for (int s = 0; s < n / m; s++) {
                long long w = 1;
                for (int i = 0; i < m / 2; i++) {
                    long long l = a[s * m + i];
                    long long r = a[s * m + i + m / 2] * w % mod;
                    a[s * m + i] = (l + r) % mod;
                    a[s * m + i + m / 2] = (l - r + mod) % mod;
                    w = w * omega % mod;
                }
            }
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
        untt(na);
        untt(nb);
        for (int i = 0; i < n; i++) na[i] = na[i] * nb[i] % mod;
        iuntt(na);
        na.resize(size);
        long long n_inv = mod_inv(n);
        for (int i = 0; i < size; i++) na[i] = na[i] * n_inv % mod;
        return na;
    }
};

// <167772161, 3>
// <469762049, 3>
// <754974721, 11>
// <998244353, 3>
// <1224736769, 3>