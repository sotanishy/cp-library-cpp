#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../string/manacher.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    auto ans = manacher(S);
    for (int i = 0; i < ans.size(); ++i) {
        if (i % 2 == 0) cout << 2 * ans[i] - 1;
        else cout << 2 * ans[i];
        if (i < ans.size() - 1) cout << " ";
        else cout << endl;
    }
}
