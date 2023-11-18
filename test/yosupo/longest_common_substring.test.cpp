#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include "../../string/longest_common_substring.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;
    auto [a, b, c, d] = longest_common_substring(S, T);
    cout << a << " " << b << " " << c << " " << d << endl;
}
