#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../../math/modint.cpp"
#include "../../math/berlekamp_massey.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<mint> a(N);
    for (auto& x : a) cin >> x;
    auto ans = berlekamp_massey(a);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i < (int) ans.size() - 1) cout << " ";
    }
    cout << endl;
}