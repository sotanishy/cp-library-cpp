#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../../math/number-theory/mod_arithmetic.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int Y, P;
        cin >> Y >> P;
        cout << mod_sqrt(Y, P) << "\n";
    }
}