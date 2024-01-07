#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <bits/stdc++.h>

#include "../../math/modint.cpp"
#include "../../set/xor_convolution.hpp"
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    vector<mint> a(1 << N), b(1 << N);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    auto c = xor_convolution(a, b);
    for (int i = 0; i < (1 << N); ++i)
        cout << c[i] << (i < (1 << N) - 1 ? " " : "\n");
}
