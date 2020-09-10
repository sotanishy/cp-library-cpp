#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> extgcd(long long a, long long b) {
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

long long mod_inv(long long a, long long mod) {
    long long inv = extgcd(a, mod).first;
    return (inv % mod + mod) % mod;
}