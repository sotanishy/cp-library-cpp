#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../tree/tree_diameter.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<Edge<int>>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    cout << TreeDiameter::diameter(G) << endl;
}