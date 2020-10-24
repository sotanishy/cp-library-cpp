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
    SCC scc(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        scc.add_edge(a, b);
    }
    scc.build();
    vector<vector<int>> comps(scc.count());
    for (int i = 0; i < N; ++i) comps[scc[i]].push_back(i);
    cout << comps.size() << "\n";
    for (int i = 0; i < comps.size(); ++i) {
        cout << comps[i].size();
        for (int v : comps[i]) cout << " " << v;
        cout << "\n";
    }
}
