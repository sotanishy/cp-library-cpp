#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../../dp/lis.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& x : A) cin >> x;
    auto [K, idx] = longest_increasing_subsequence_with_index(A, true);
    cout << K << endl;
    for (int i = 0; i < K; ++i) cout << idx[i] << (i < K-1 ? " " : "\n");
}
