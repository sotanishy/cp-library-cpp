#define PROBLEM \
    "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include <bits/stdc++.h>

#include "../../convolution/convex_min_plus_convolution.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> a(N), b(M);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    auto c = convex_min_plus_convolution(b, a);
    for (int i = 0; i < N + M - 1; ++i)
        cout << c[i] << (i < N + M - 2 ? " " : "\n");
}
