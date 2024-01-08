#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include <bits/stdc++.h>

#include "../../graph/manhattan_mst.hpp"

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<long long, long long>> pts(N);
    for (auto& x : pts) cin >> x.first >> x.second;
    auto [weight, edges] = manhattan_mst(pts);
    cout << weight << endl;
    for (auto [u, v] : edges) {
        cout << u << " " << v << "\n";
    }
}