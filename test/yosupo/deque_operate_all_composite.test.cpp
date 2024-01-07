#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "../../data-structure/foldable_deque.hpp"
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
    FoldableDeque<M> que;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            que.push_front({a, b});
        } else if (t == 1) {
            int a, b;
            cin >> a >> b;
            que.push_back({a, b});
        } else if (t == 2) {
            que.pop_front();
        } else if (t == 3) {
            que.pop_back();
        } else {
            int x;
            cin >> x;
            pair<mint, mint> p = que.empty() ? make_pair(1, 0) : que.fold();
            cout << p.first * x + p.second << "\n";
        }
    }
}