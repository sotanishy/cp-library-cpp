#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "../../math/mod_arithmetic.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int X, Y, M;
        cin >> X >> Y >> M;
        cout << mod_log(X, Y, M) << "\n";
    }
}