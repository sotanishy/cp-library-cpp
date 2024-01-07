#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>

#include "../../string/kmp.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string T;
    cin >> T;
    string P;
    cin >> P;
    auto ans = kmp(T, P, prefix_function(P));
    for (int i : ans) cout << i << "\n";
}
