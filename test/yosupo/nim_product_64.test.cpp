#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include "../../math/nimber.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1) : 0; }
template <typename T> bool chmin(T& a, const T& b) { return a > b ? (a = b, 1) : 0; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    while (T--) {
        Nimber A, B;
        cin >> A >> B;
        cout << A*B << "\n";
    }
}