#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include <bits/stdc++.h>

#include "../../misc/rectangle_union.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<tuple<ll, ll, ll, ll>> rects(N);
    for (int i = 0; i < N; ++i) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        rects[i] = {l, d, r, u};
    }
    cout << area_of_union_of_rectangles(rects) << endl;
}