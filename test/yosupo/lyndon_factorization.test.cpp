#define PROBLEM "https://judge.yosupo.jp/problem/lyndon_factorization"

#include "../../string/lyndon_factorization.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    auto res = lyndon_factorization(S);
    for (int i = 0; i < (int)res.size(); ++i)
        cout << res[i] << (i < (int)res.size() ? " " : "\n");
}
