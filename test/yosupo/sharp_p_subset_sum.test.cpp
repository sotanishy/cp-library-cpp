#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include <bits/stdc++.h>

#include "../../math/count_subset_sum.hpp"
#include "../../math/modint.cpp"

using mint = Modint<998244353>;

using namespace std;
using ll = long long;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> s(N);
    for (auto& x : s) cin >> x;
    auto ans = count_subset_sum<mint>(s, T);

    for (int i = 1; i <= T; ++i) {
        cout << ans[i] << (i < T ? " " : "\n");
    }
}
