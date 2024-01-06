#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include <bits/stdc++.h>

#include "../../math/bernoulli.hpp"
#include "../../math/modint.cpp"

using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T>
bool chmax(T& a, const T& b) {
    return a < b ? (a = b, 1) : 0;
}
template <typename T>
bool chmin(T& a, const T& b) {
    return a > b ? (a = b, 1) : 0;
}

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    auto ans = bernoulli_number_table<mint>(N);
    for (int i = 0; i <= N; ++i) cout << ans[i] << (i < N ? " " : "\n");
}
