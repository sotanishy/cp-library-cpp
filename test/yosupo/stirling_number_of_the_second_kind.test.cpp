#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"


#include "../../math/modint.cpp"
#include "../../math/stirling_second.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    auto ans = stirling_second_table<mint>(N);
    for (int i = 0; i <= N; ++i) {
        cout << ans[i] << (i < N ? " " : "\n");
    }
}
