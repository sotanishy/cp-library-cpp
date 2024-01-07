#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>

#include "../../string/rolling_hash.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string T;
    cin >> T;
    string P;
    cin >> P;
    long long base = RollingHash::generate_base();
    RollingHash rht(T, base);
    RollingHash rhp(P, base);
    for (int i = 0; i + P.size() <= T.size(); ++i) {
        if (rht.query(i, i + P.size()) == rhp.query(0, P.size())) {
            cout << i << "\n";
        }
    }
}