#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_convolution"

#include "../../math/modint.cpp"
#include "../../math/transform.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    vector<mint> a(1 << N), b(1 << N), c(1 << N);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    fzt(a, false);
    fzt(b, false);
    for (int i = 0; i < (1 << N); ++i) c[i] = a[i] * b[i];
    fmt(c, false);
    for (int i = 0; i < (1 << N); ++i) cout << c[i] << (i < (1 << N) - 1 ? " " : "\n");
}
