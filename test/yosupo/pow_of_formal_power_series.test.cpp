#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../math/modint.hpp"
#include "../../math/polynomial.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    Polynomial<mint> f(N);
    for (int i = 0; i < N; ++i) cin >> f[i];
    auto g = f.pow(M);
    g.resize(N);
    for (int i = 0; i < N; ++i) cout << g[i] << (i < N - 1 ? " " : "\n");
}
