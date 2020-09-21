#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../graph/scc.cpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    SCC scc(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        scc.add_edge(s, t);
    }
    scc.build();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (scc[u] == scc[v]) << "\n";
    }
}