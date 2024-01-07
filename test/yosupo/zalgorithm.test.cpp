#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>

#include "../../string/z_array.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    vector<int> z = z_array(S);
    for (int i = 0; i < S.size(); ++i)
        cout << z[i] << (i < S.size() - 1 ? " " : "\n");
}