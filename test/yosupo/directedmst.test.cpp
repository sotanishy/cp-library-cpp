#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"

#include <bits/stdc++.h>

#include "../../graph/minimum_spanning_arborescence.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S;
    cin >> N >> M >> S;
    vector<tuple<int, int, ll>> G(M);
    for (int i = 0; i < M; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        G[i] = {s, t, w};
    }
    auto ans = minimum_spanning_arborescence(G, N, S);
    cout << ans.first << endl;
    for (int i = 0; i < N; ++i)
        cout << ans.second[i] << (i < N - 1 ? " " : "\n");
}