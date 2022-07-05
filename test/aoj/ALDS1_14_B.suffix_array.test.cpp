#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "../../string/suffix_array.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string T;
    cin >> T;
    string P;
    cin >> P;
    auto sa = suffix_array(T);

    auto cmp = [&](int si, const string& t) {
        int sn = T.size(), tn = t.size();
        int ti = 0;
        for (; si < sn && ti < tn; ++si, ++ti) {
            if (T[si] < t[ti]) return true;
            if (T[si] > t[ti]) return false;
        }
        return si == sn && ti < tn;
    };

    int lb = lower_bound(sa.begin(), sa.end(), P, cmp) - sa.begin();
    int ub = lower_bound(sa.begin(), sa.end(), P + '~', cmp) - sa.begin();
    vector<int> ans;
    for (int i = lb; i < ub; i++) ans.push_back(sa[i]);
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << "\n";
}