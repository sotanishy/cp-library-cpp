#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include "../../math/product_of_polynomial_sequence.hpp"

#include <bits/stdc++.h>

#include "../../math/modint.cpp"
#include "../../math/polynomial.cpp"

using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<Polynomial<mint>> ps(N);
    for (int i = 0; i < N; ++i) {
        int d;
        cin >> d;
        ps[i].resize(d + 1);
        for (auto& x : ps[i]) cin >> x;
    }
    auto ans = product_of_polynomial_sequence(ps);
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << (i < (int)ans.size() - 1 ? " " : "\n");
}