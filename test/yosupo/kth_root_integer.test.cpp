#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../../math/kth_root.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        unsigned long long A;
        int K;
        cin >> A >> K;
        cout << kth_root(A, K) << "\n";
    }
}