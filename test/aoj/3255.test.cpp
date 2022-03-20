#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3255"

#include "../../data-structure/cht/dynamic_convex_hull_trick.cpp"
#include "../../data-structure/cht/undoable_li_chao_tree.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using CHT = unique_ptr<DynamicConvexHullTrick<ll>>;

CHT merge(CHT a, CHT b) {
    if (a->lines.size() < b->lines.size()) swap(a, b);
    for (auto& line : b->lines) {
        a->add(-line.a, -line.b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto& a : A) cin >> a;
    vector<vector<ll>> dp(K+1, vector<ll>(N+1, 1e18));
    dp[0][0] = 0;

    vector<ll> idx(N+1);
    iota(idx.begin(), idx.end(), 0);
    UndoableLiChaoTree<ll> lct(idx);

    for (int i = 1; i <= K; ++i) {
        vector<int> mx;
        vector<CHT> chts;
        for (int j = 0; j < N; ++j) {
            CHT cht_new = make_unique<DynamicConvexHullTrick<ll>>();
            cht_new->add(-j, dp[i-1][j]);
            while (!mx.empty() && mx.back() <= A[j]) {
                mx.pop_back();
                lct.undo();
                cht_new = merge(move(chts.back()), move(cht_new));
                chts.pop_back();
            }
            mx.push_back(A[j]);
            lct.add(A[j], cht_new->get(A[j]));
            chts.push_back(move(cht_new));
            dp[i][j+1] = lct.get(j+1);
        }
        while (!mx.empty()) mx.pop_back(), lct.undo();
    }

    cout << dp[K][N] << endl;
}