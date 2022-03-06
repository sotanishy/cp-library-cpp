#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../math/modint.cpp"
#include "../../math/transform.cpp"

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
    divisor_fzt(a, false);
    divisor_fzt(b, false);
    for (int i = 1; i <= N; ++i) a[i] *= b[i];
    divisor_fmt(a, false);
    for (int i = 1; i <= N; ++i) cout << a[i] << (i < N ? " " : "\n");
}
