#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation.test.cpp"

#include "../../math/multipoint_evaluation.cpp"
#include "../../math/modint.cpp"
#include "../../math/polynomial.cpp"

#include <bits/stdc++.h>

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

    int N, M;
    cin >> N >> M;
    Polynomial<mint> c(N);
    vector<mint> p(M);
    for (auto& x : c) cin >> x;
    for (auto& x : p) cin >> x;

    auto ans = multipoint_evaluation(c, p);
    rep(i, 0, M) cout << ans[i] << (i < M - 1 ? " " : "\n");
}
