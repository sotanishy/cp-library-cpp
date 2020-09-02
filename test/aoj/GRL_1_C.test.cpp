#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include "../../graph/floyd_warshall.cpp"

using ll = long long;

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<ll>> dist(V, vector<ll>(V, INF));
    for (int i = 0; i < V; i++) dist[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    floyd_warshall(dist);
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] < 1e9) cout << dist[i][j];
            else cout << "INF";
            if (j < V - 1) cout << " ";
            else cout << "\n";
        }
    }
}