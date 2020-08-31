#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long n, long long p, long long mod) {
    long long ret = 1;
    while (p > 0) {
        if (p & 1) ret = ret * n % mod;
        n = n * n % mod;
        p >>= 1;
    }
    return ret;
}

long long mod_inv(long long n, long long mod) {
    return mod_pow(n, mod - 2, mod);
}