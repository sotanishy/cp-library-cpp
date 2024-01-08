#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include "../../math/number-theory/mod_arithmetic.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int A, B, M;
        cin >> A >> B >> M;
        cout << mod_tetration(A, B, M) << "\n";
    }
}
