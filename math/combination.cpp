#include <bits/stdc++.h>
using namespace std;

struct Combination {
    long long mod;
    vector<long long> fact, fact_inv;

private:
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

    static long long mod_inv(long long a, long long mod) {
        long long inv = extgcd(a, mod).first;
        return (inv % mod + mod) % mod;
    }

public:
    static long long C(int n, int r, long long mod) {
        long long num = 1, den = 1;
        for (int i = 1; i <= r; i++) {
            num = num * (n - i + 1) % mod;
            den = den * i % mod;
        }
        return num * mod_inv(den, mod) % mod;
    }

    Combination(int n, long long mod) : mod(mod), fact(n+1), fact_inv(n+1) {
        fact[0] = fact_inv[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % mod;
        fact_inv[n] = mod_inv(n, mod);
        for (int i = n; i > 0; i--) fact_inv[i-1] = fact_inv[i] * i % mod;
    }

    long long P(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * fact_inv[n - r] % mod;
    }

    long long C(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod;
    }
}