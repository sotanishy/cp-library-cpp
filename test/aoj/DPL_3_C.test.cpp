#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include <bits/stdc++.h>

#include "../../dp/largest_rectangle.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> h(N);
    for (auto& x : h) cin >> x;
    cout << largest_rectangle(h) << endl;
}
