#define PROBLEM "https://judge.yosupo.jp/problem/gcd_of_gaussian_integers"

#include <bits/stdc++.h>

#include "../../math/gaussian_integer.hpp"
using namespace std;

using G = GaussianInteger<long long>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        G x(a1, b1), y(a2, b2);
        auto g = G::gcd(x, y);
        cout << g.x << " " << g.y << "\n";
    }
}