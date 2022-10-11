#define PROBLEM "https://judge.yosupo.jp/problem/common_interval_decomposition_tree"

#include "../../tree/permutation_tree.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> p(N);
    for (auto& x : p) cin >> x;
    PermutationTree pt(p);
    vector<int> par(pt.nodes.size(), -1);
    for (int i = 0; i < (int) pt.nodes.size(); ++i) {
        for (int j : pt.nodes[i].ch) {
            par[j] = i;
        }
    }
    cout << pt.nodes.size() << endl;
    for (int i = 0; i < (int) pt.nodes.size(); ++i) {
        cout << par[i] << " " << pt.nodes[i].l << " " << pt.nodes[i].r-1 << " " << (pt.nodes[i].tp == PermutationTree::Cut ? "prime" : "linear") << "\n";
    }
}

