#include <bits/stdc++.h>
#include "mod_pow.cpp"
using namespace std;

long long comb(int n, int k, int mod) {
    long long num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = num * (n-i) % mod;
        den = den * (i+1) % mod;
    }
    return num * mod_inv(den, mod) % mod;
}

void comb(int n, int mod) {
    vector<long long> fact(n+1, 1), fact_inv(n+1, 1);
    for (long long i = 1; i <= n; i++) {
        fact[i] = i * fact[i-1] % mod;
    }
    fact_inv[n] = mod_inv(fact[n], mod);
    for (long long i = n; i > 0; i--) {
        fact_inv[i-1] = i * fact_inv[i] % mod;
    }
}