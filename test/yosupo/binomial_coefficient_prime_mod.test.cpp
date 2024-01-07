#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <bits/stdc++.h>

#include "../../math/arbitrary_modint.hpp"
#include "../../math/combination.cpp"
using namespace std;
using ll = long long;

using mint = ArbitraryModint;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, m;
    cin >> T >> m;
    mint::set_mod(m);
    Combination<mint> comb(min(m, (int)1e7) - 1);

    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << comb.comb(n, k) << "\n";
    }
}