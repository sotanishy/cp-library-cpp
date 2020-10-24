#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../../graph/shortest_path.cpp"

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, r;
    cin >> V >> E >> r;
    vector<Edge<int>> G;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G.push_back({s, t, d});
    }
    auto dist = bellman_ford(G, V, r);
    if (dist.size() == 0) cout << "NEGATIVE CYCLE\n";
    else {
        for (int i = 0; i < V; i++) {
            if (dist[i] < INF) cout << dist[i] << "\n";
            else cout << "INF\n";
        }
    }
}