#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include "../../string/enumerate_runs.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    auto runs = enumerate_runs(S);
    vector<tuple<int, int, int>> ans;
    set<pair<int, int>> used;
    for (int p = 1; p <= S.size(); ++p) {
        for (auto [l, r] : runs[p]) {
            if (!used.count({l, r})) {
                used.insert({l, r});
                ans.push_back({p, l, r});
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto [t, l, r] : ans) {
        cout << t << " " << l << " " << r << "\n";
    }
}