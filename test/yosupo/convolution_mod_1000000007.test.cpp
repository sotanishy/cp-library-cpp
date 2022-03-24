#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../../convolution/arbitrary_mod_convolution.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    auto c = convolution(a, b, 1e9+7);
    for (int i = 0; i < (int) c.size(); ++i) cout << c[i] << (i < (int)c.size()-1 ? " " : "\n");
}

