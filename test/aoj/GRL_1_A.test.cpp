#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../graph/dijkstra.cpp"

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<Edge<int>>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }
    auto dist = dijkstra(G, r);
    for (int i = 0; i < V; i++) {
        if (dist[i] < INF) cout << dist[i] << "\n";
        else cout << "INF\n";
    }
}