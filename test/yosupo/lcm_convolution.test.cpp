#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include "../../math/modint.hpp"
#include "../../convolution/gcd_lcm_convolution.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    vector<mint> a(N+1), b(N+1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];
    auto c = lcm_convolution(a, b);
    for (int i = 1; i <= N; ++i) cout << c[i] << (i < N ? " " : "\n");
}
