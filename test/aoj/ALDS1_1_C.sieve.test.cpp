#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include "../../math/sieve.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<bool> prime = sieve(1e8);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (prime[a]) ans++;
    }
    cout << ans << endl;
}