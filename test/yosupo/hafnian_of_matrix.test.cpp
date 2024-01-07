#define PROBLEM "https://judge.yosupo.jp/problem/hafnian_of_matrix"

#include <bits/stdc++.h>

#include "../../math/linalg/hafnian.hpp"
#include "../../math/modint.hpp"
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector a(N, vector<mint>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> a[i][j];
    }
    cout << hafnian<mint, 19>(a) << endl;
}
