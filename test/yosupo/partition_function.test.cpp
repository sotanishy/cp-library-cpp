#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include "../../math/partition_function.hpp"
#include "../../math/modint.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    auto ans = partition_function_table<mint>(N);
    for (int i = 0; i <= N; ++i) cout << ans[i] << (i < N ? " " : "\n");
}