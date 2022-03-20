#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../../tree/cartesian_tree.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& x : a) cin >> x;
    auto p = cartesian_tree(a);
    for (int i = 0; i < N; ++i) cout << (p[i] == -1 ? i : p[i]) << (i < N-1 ? " " : "\n");
}
