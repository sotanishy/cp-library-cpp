#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../math/prime_count.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    cout << prime_count(N) << endl;
}