#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../../math/number-theory/floor_sum.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M, A, B;
        cin >> N >> M >> A >> B;
        cout << floor_sum(N, M, A, B) << "\n";
    }
}