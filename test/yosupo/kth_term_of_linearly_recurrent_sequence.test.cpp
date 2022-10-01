#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../../math/modint.cpp"
#include "../../math/bostan_mori.hpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    long long k;
    cin >> d >> k;
    vector<mint> a(d), c(d);
    for (auto& x : a) cin >> x;
    for (auto& x : c) cin >> x;
    cout << bostan_mori_recurrence(a, c, k) << endl;
}
