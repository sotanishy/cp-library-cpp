#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../string/suffix_array.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    auto sa = suffix_array(S);
    for (int i = 0; i < S.size(); ++i) {
        cout << sa[i] << (i < S.size() - 1 ? " " : "\n");
    }
}