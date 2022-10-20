#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../misc/compress.cpp"
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
    TreeHasher hash;
    auto val = hash.hash_subtrees(G, 0);
    Compress<long long> comp(val);
    auto val2 = comp.compress(val);
    cout << comp.size() << endl;
    for (int i = 0; i < N; ++i) cout << val2[i] << (i < N - 1 ? " " : "\n");
}