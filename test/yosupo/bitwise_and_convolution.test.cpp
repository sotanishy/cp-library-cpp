#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../math/modint.cpp"
#include "../../convolution/and_or_convolution.hpp"

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
    auto c = and_convolution(a, b);
    for (int i = 0; i < (1 << N); ++i) cout << c[i] << (i < (1 << N) - 1 ? " " : "\n");
}
