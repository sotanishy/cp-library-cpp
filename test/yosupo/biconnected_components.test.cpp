#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "../../graph/biconnected_components.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    map<pair<int, int>, vector<int>> id;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (!id.count(minmax(a, b))) {
            G[a].push_back(b);
            G[b].push_back(a);
        }
        id[minmax(a, b)].push_back(i);
    }
    BiconnectedComponents bc(G);
    auto comps = bc.get_biconnected_components();
    cout << comps.size() << endl;
    for (auto& comp : comps) {
        vector<int> c;
        for (auto [u, v] : comp) {
            for (int i : id[minmax(u, v)]) c.push_back(i);
        }
        cout << c.size();
        for (int i : c) cout << " " << i;
        cout << "\n";
    }
}
