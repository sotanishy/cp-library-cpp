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
    set<pair<int, int>> st;
    vector<bool> alone(N, true);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (!st.count(minmax(a, b))) {
            G[a].push_back(b);
            G[b].push_back(a);
            alone[a] = alone[b] = false;
        }
        st.insert(minmax(a, b));
    }
    Lowlink low(G);
    auto comps = biconnected_components(G, low);
    for (int i = 0; i < N; ++i) {
        if (alone[i]) {
            comps.push_back({{i, i}});
        }
    }
    cout << comps.size() << endl;
    for (auto& comp : comps) {
        set<int> st;
        for (auto [u, v] : comp) {
            st.insert(u);
            st.insert(v);
        }
        cout << st.size();
        for (int i : st) cout << " " << i;
        cout << "\n";
    }
}
