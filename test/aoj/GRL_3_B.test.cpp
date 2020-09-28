#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../graph/lowlink.cpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    Lowlink lowlink(G);
    vector<pair<int, int>> bridges = lowlink.get_bridges();
    sort(bridges.begin(), bridges.end());
    for (auto& p : bridges) {
        cout << p.first << " " << p.second << "\n";
    }
}