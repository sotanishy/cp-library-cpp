#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <bits/stdc++.h>

#include "../../string/lcp_array.hpp"
#include "../../string/suffix_array.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    int N = S.size();
    auto sa = suffix_array(S);
    auto lcp = lcp_array(S, sa);
    long long ans = 1LL * N * (N + 1) / 2;
    for (int i = 0; i < lcp.size(); ++i) ans -= lcp[i];
    cout << ans << endl;
}