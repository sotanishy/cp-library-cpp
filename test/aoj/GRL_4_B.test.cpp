#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include "../../graph/topological_sort.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    auto order = topological_sort(G);
    for (int i = 0; i < V; i++) cout << order[i] << "\n";
}