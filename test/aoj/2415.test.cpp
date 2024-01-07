#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415"

#include <bits/stdc++.h>

#include "../../dp/hu_tucker.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> w(N);
    for (auto& x : w) cin >> x;
    cout << hu_tucker(w) << endl;
}