#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "../../math/number-theory/primitive_root.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        long long p;
        cin >> p;
        cout << primitive_root(p) << "\n";
    }
}
