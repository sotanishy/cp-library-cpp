#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include "../../math/prime.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << n << ":";
    auto prime = prime_factor(n);
    for (auto& p : prime) {
        for (int i = 0; i < p.second; i++) cout << " " << p.first;
    }
    cout << endl;
}