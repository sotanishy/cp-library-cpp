#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../tree/tree_isomorphism.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 1; i < N; ++i) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    TreeEncoder enc;
    auto val = enc.encode(G, 0);
    cout << *max_element(val.begin(), val.end()) + 1 << endl;
    for (int i = 0; i < N; ++i) cout << val[i] << (i < N - 1 ? " " : "\n");
}