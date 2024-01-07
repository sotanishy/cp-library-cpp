#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"

#include <bits/stdc++.h>

#include "../../math/modint.cpp"
#include "../../set/set_power_series.hpp"
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    SetPowerSeries<mint, 20> b(1 << N);
    for (int i = 0; i < 1 << N; ++i) cin >> b[i];
    auto c = b.exp();
    for (int i = 0; i < 1 << N; ++i)
        cout << c[i] << (i < (1 << N) - 1 ? " " : "\n");
}
