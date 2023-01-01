#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"

#include "../../flow/min_cost_b_flow.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ostream& operator<<(ostream& os, __int128_t n) {
    if (n < 0) {
        os << "-" << (-n);
        return os;
    }
    if (n == 0) {
        os << "0";
        return os;
    }
    string s;
    while (n) {
        s.push_back('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    os << s;
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    MinCostFlow<ll, __int128_t> flow(n);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (b > 0) {
            flow.add_supply(i, b);
        }
        if (b < 0) {
            flow.add_demand(i, -b);
        }
    }
    for (int i = 0; i < m; ++i) {
        int s, t, l, u, c;
        cin >> s >> t >> l >> u >> c;
        flow.add_edge(s, t, l, u, c);
    }
    auto [feasible, z] = flow.min_cost_flow();
    if (!feasible) {
        cout << "infeasible" << endl;
        return 0;
    }

    auto p = flow.get_potential();
    auto f = flow.get_flow();

    cout << z << endl;
    for (int i = 0; i < n; ++i) cout << p[i] << "\n";
    for (int i = 0; i < m; ++i) cout << f[i] << "\n";
}
