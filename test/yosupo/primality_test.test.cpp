#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <bits/stdc++.h>

#include "../../math/number-theory/fast_prime.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        long long N;
        cin >> N;
        cout << (fast_prime::is_prime(N) ? "Yes" : "No") << "\n";
    }
}