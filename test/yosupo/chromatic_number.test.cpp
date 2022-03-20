#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "../../graph/chromatic_number.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N, vector<bool>(N));
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = true;
    }
    cout << chromatic_number(G) << endl;
}

