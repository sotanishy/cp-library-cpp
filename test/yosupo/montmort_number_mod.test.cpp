#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include "../../math/arbitrary_modint.cpp"
#include "../../math/montmort.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    using mint = ArbitraryModint;
    mint::set_mod(M);
    vector<mint> ans = montmort<mint>(N);
    for (int i = 1; i <= N; ++i) cout << ans[i] << (i < N ? " " : "\n");
}