#define PROBLEM \
    "https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum"

#include <bits/stdc++.h>

#include "../../tree/euler_tour_tree.hpp"
using namespace std;

using ll = long long;

struct AddRangeMonoid {
    using T = pair<ll, int>;
    static T id() { return {0, 0}; }
    static T op(T a, T b) { return {a.first + b.first, a.second + b.second}; }
};

struct AddMonoid {
    using T = ll;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

pair<ll, int> act(pair<ll, int> a, ll b) {
    return {a.first + a.second * b, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    EulerTourTree<AddRangeMonoid, AddMonoid, act> ett(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ett.update(i, {a, 1});
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        ett.link(u, v);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            ett.cut(u, v);
            ett.link(w, x);
        } else if (t == 1) {
            int v, p, x;
            cin >> v >> p >> x;
            ett.update(v, p, x);
        } else {
            int v, p;
            cin >> v >> p;
            cout << ett.fold(v, p).first << "\n";
        }
    }
}