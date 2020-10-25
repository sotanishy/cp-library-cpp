#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../math/fast_prime.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        ll a;
        cin >> a;
        auto ans = fast_prime::prime_factor(a);
        sort(ans.begin(), ans.end());
        cout << ans.size();
        for (ll x : ans) cout << " " << x;
        cout << endl;
    }
}