#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../../math/modint.cpp"
#include "../../convolution/subset_convolution.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    vector<mint> a(1<<N), b(1<<N);
    for (int i = 0; i < 1 << N; ++i) cin >> a[i];
    for (int i = 0; i < 1 << N; ++i) cin >> b[i];
    auto c = subset_convolution<mint, 20>(a, b);
    for (int i = 0; i < 1 << N; ++i) cout << c[i] << (i < (1<<N)-1 ? " " : "\n");
}
