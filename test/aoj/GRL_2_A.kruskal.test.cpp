#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../graph/kruskal.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<Edge<int>> edges;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.emplace_back(s, t, w);
    }
    cout << kruskal(edges, V) << endl;
}