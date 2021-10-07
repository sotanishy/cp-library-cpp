#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../graph/scc.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    auto comp = scc(G);
    int n = *max_element(comp.begin(), comp.end()) + 1;
    vector<vector<int>> comps(n);
    for (int i = 0; i < N; ++i) comps[comp[i]].push_back(i);
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        cout << comps[i].size();
        for (int v : comps[i]) cout << " " << v;
        cout << "\n";
    }
}
