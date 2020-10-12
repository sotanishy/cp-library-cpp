#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../math/modint.cpp"
#include "../../math/ntt.cpp"

using namespace std;
using ll = long long;

using mint = Modint<998244353>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<mint> a(N), b(M);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];
    vector<mint> c = NTT<mint>::convolution(a, b);
    for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i < N + M - 2 ? " " : "\n");
}
