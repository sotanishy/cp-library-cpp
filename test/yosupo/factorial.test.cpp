#define PROBLEM "https://judge.yosupo.jp/problem/factorial"

#include "../../math/factorial.hpp"

#include <bits/stdc++.h>

#include "../../math/modint.cpp"
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    Factorial<mint> fact;
    while (T--) {
        int N;
        cin >> N;
        cout << fact.query(N) << "\n";
    }
}
