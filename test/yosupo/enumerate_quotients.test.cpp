#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include <bits/stdc++.h>

#include "../../math/number-theory/quotients.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    cin >> N;
    auto qr = quotient_ranges(N);
    vector<long long> ans;
    for (auto [l, r] : qr) ans.push_back(N / l);
    reverse(ans.begin(), ans.end());
    int k = ans.size();
    cout << k << endl;
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << (i < k - 1 ? " " : "\n");
    }
}