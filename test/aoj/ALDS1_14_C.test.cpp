#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include "../../string/pattern_search_2d.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    vector<string> txt(H);
    for (auto& x : txt) cin >> x;
    int R, C;
    cin >> R >> C;
    vector<string> pat(R);
    for (auto& x : pat) cin >> x;

    auto ans = pattern_search_2d(txt, pat);
    sort(ans.begin(), ans.end());
    for (auto [i, j] : ans) {
        cout << i << " " << j << "\n";
    }
}