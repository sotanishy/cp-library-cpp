#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "../../flow/min_cost_flow.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, F;
    cin >> V >> E >> F;
    MinCostFlow<int, int> mcf(V);
    for (int i = 0; i < E; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        mcf.add_edge(u, v, c, d);
    }
    cout << mcf.min_cost_flow(0, V - 1, F) << endl;
}