#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include "../../math/modint.cpp"
#include "../../math/stirling_first.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
Polynomial<T> stirling_first_table(int n) {
    if (n == 0) return {1};
    Polynomial<T> ret = stirling_first_table<T>(n / 2);
    ret *= ret.taylor_shift(-(n / 2));
    if (n % 2) ret = (ret << 1) + ret * (-(n - 1));  // ret *= (x - (n - 1))
    return ret;
}

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    auto ans = stirling_first_table<mint>(N);
    for (int i = 0; i <= N; ++i) {
        cout << ans[i] << (i < N ? " " : "\n");
    }
}