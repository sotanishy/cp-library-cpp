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
    SuffixArray sa(T);
    int lb = sa.lower_bound(P);
    int ub = sa.upper_bound(P);
    vector<int> ans;
    for (int i = lb; i < ub; i++) ans.push_back(sa[i]);
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << "\n";
}