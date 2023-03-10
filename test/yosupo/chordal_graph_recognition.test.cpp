#define PROBLEM \
    "https://judge.yosupo.jp/problem/chordal_graph_recognition.test.cpp"

#include "../../graph/chordal_graph_recognition.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T>
bool chmax(T& a, const T& b) {
    return a < b ? (a = b, 1) : 0;
}
template <typename T>
bool chmin(T& a, const T& b) {
    return a > b ? (a = b, 1) : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto [ans, vec] = recognize_chordal_graph(G);
    cout << (ans ? "YES" : "NO") << "\n";
    if (!ans) cout << vec.size() << "\n";
    for (int i = 0; i < (int)vec.size(); ++i) {
        cout << vec[i] << (i < (int)vec.size() - 1 ? " " : "\n");
    }
}