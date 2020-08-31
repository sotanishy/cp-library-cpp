#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../graph/scc_decomposition.cpp"

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
    SCC scc(G);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (scc[u] == scc[v]) << "\n";
    }
}