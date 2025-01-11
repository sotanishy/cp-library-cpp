#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "../../graph/biconnected_components.hpp"

#include <bits/stdc++.h>

#include "../../graph/lowlink.hpp"
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
        G[b].push_back(a);
    }
    Lowlink low(G);
    auto blocks = biconnected_components(G, low);
    cout << blocks.size() << endl;
    for (auto& block : blocks) {
        cout << block.size();
        for (int i : block) cout << " " << i;
        cout << "\n";
    }
}
