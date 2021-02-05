#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../graph/edge.cpp"
#include "../../tree/tree_diameter.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int) v.size(); ++i) cout << v[i] << " ";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<Edge<ll>>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    auto ans = tree_diameter(G);
    cout << ans.first << " " << ans.second.size() << endl;
    cout << ans.second << endl;
}