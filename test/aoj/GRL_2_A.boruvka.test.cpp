#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <bits/stdc++.h>

#include "../../graph/mst.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<tuple<int, int, int>> G;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G.emplace_back(s, t, w);
    }
    cout << boruvka(G, V).first << endl;
}