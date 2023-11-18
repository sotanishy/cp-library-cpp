#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <bits/stdc++.h>

#include "../../math/prime.cpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B;
    cin >> N >> A >> B;
    auto is_prime = prime_table(N);
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    vector<int> ans;
    for (int i = B; i < (int)primes.size(); i += A) {
        ans.push_back(primes[i]);
    }
    int X = ans.size();
    cout << primes.size() << " " << X << endl;
    for (int i = 0; i < X; ++i) cout << ans[i] << (i < X - 1 ? " " : "\n");
}