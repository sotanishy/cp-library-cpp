#include <bits/stdc++.h>
using namespace std;

struct TreeDiameter {

    static pair<int, int> dfs(vector<vector<int>>& G, int v, int p) {
        pair<int, int> ret(0, v);
        for (int c : G[v]) {
            if (c == p) continue;
            auto cost = dfs(G, c, v);
            cost.first++;
            ret = max(ret, cost);
        }
        return ret;
    }

    static int tree_diameter(vector<vector<int>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }
};