#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"

#include "../../math/modint.cpp"
#include "../../data-structure/fenwick_tree.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

struct AddMonoid {
    using T = mint;
    static T id() { return 0; }
    static T op(T a, T b) {
        return a + b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& x : A) cin >> x;
    map<int, int> last;
    FenwickTree<AddMonoid> ft(N+1);
    ft.update(0, 1);
    for (int i = 0; i < N; ++i) {
        int l = last[A[i]];
        ft.update(i+1, ft.prefix_fold(i+1) - ft.prefix_fold(l));
        last[A[i]] = i + 1;
    }
    cout << ft.prefix_fold(N + 1) - 1 << endl;
}