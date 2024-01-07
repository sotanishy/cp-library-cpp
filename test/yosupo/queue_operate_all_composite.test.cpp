#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../data-structure/sliding_window_aggregation.cpp"
#include "../../math/modint.hpp"


#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

struct M {
    using T = pair<mint, mint>;
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    SlidingWindowAggregation<M> que;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            que.push({a, b});
        } else if (t == 1) {
            que.pop();
        } else {
            int x;
            cin >> x;
            pair<mint, mint> p = que.empty() ? make_pair(1, 0) : que.fold();
            cout << p.first * x + p.second << "\n";
        }
    }
}