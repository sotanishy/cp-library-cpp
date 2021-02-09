#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"

#include "../../graph/edge.cpp"
#include "../../graph/minimum_spanning_arborescence.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S;
    cin >> N >> M >> S;
    vector<Edge<ll>> G(M);
    for (auto& e : G) cin >> e.from >> e.to >> e.weight;
    auto ans = minimum_spanning_arborescence(G, N, S);
    cout << ans.first << endl;
    for (int i = 0; i < N; ++i) cout << ans.second[i] << (i < N - 1 ? " " : "\n");
}