#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../../math/modint.hpp"
#include "../../math/polynomial.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Polynomial<mint> f(N), g(M);
    for (int i = 0; i < N; ++i) cin >> f[i];
    for (int i = 0; i < M; ++i) cin >> g[i];
    auto [q, r] = f.divmod(g);
    cout << q.size() << " " << r.size() << endl;
    for (int i = 0; i < (int)q.size(); ++i) {
        if (i > 0) cout << " ";
        cout << q[i];
    }
    cout << endl;
    for (int i = 0; i < (int)r.size(); ++i) {
        if (i > 0) cout << " ";
        cout << r[i];
    }
    cout << endl;
}
