#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../math/ntt.cpp"

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(N), b(M);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];
    vector<ll> c = NTT<998244353, 3>::convolution(a, b);
    for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i < N + M - 2 ? " " : "\n");
}
