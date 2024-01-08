#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include <bits/stdc++.h>

#include "../../math/modint.hpp"
#include "../../math/number-theory/euler_totient.hpp"
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    auto [small, large] = totient_summatory_table<mint>(N);
    mint ans = large[1];
    cout << ans << endl;
}