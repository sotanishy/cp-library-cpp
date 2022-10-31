#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include "../../graph/bipartite_matching.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X, Y, E;
    cin >> X >> Y >> E;
    BipartiteMatchingFF bm(X + Y);
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        bm.add_edge(x, X + y);
    }
    cout << bm.max_matching().size() << endl;
}