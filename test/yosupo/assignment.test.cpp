#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "../../graph/assignment.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<ll>> a(N, vector<ll>(N));
    for (auto& row : a) for (auto& x : row) cin >> x, x *= -1;
    auto perm = assignment(a);
    ll X = 0;
    for (int i = 0; i < N; ++i) X += a[i][perm[i]];
    cout << -X << endl;
    for (int i = 0; i < N; ++i) cout << perm[i] << (i < N-1 ? " " : "\n");
}
