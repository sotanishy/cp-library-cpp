#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2292"

#include "../../string/palindromic_tree.hpp"
#include "../../string/rolling_hash.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    string s, t;
    cin >> s >> t;
    PalindromicTree pts(s), ptt(t);
    ll base = RollingHash::generate_base();
    RollingHash rhs(s, base), rht(t, base);
    map<ll, ll> mp;
    for (auto [len, idx, cnt] : pts.get_palindrome_frequencies()) {
        mp[rhs.query(idx, idx+len)] += cnt;
    }
    ll ans = 0;
    for (auto [len, idx, cnt] : ptt.get_palindrome_frequencies()) {
        ans += mp[rht.query(idx, idx+len)] * cnt;
    }
    cout << ans << endl;
}
