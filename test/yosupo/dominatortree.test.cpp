#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"

#include "../../graph/dominator_tree.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S;
    cin >> N >> M >> S;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    auto dom = dominator_tree(G, S);
    for (int i = 0; i < N; ++i) cout << dom[i] << (i < N-1 ? " " : "\n");
}