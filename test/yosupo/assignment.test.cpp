#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
std::pair<T, std::vector<int>> hungarian(const std::vector<std::vector<T>>& A) {
    const T INF = std::numeric_limits<T>::max();
    const int n = A.size();
    std::vector<int> P(n), way(n);
    std::vector<T> U(n), V(n), minV;  // value substracted from row, col
    std::vector<bool> used;

    for (int i = 1; i < n; ++i) {
        P[0] = i;
        minV.assign(n, INF);
        used.assign(n, false);
        int j0 = 0;
        while (P[j0] != 0) {
            int i0 = P[j0], j1 = 0;  // col with the minimum value
            used[j0] = true;
            T delta = INF;
            for (int j = 1; j < n; ++j) {
                if (used[j]) continue;
                T curr = A[i0][j] - U[i0] - V[j];
                if (curr < minV[j]) {
                    minV[j] = curr;
                    way[j] = j0;
                }
                if (minV[j] < delta) {
                    delta = minV[j];
                    j1 = j;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (used[j]) {
                    U[P[j]] += delta;
                    V[j] -= delta;
                } else {
                    minV[j] -= delta;
                }
            }
            j0 = j1;
        }
        do {
            P[j0] = P[way[j0]];
            j0 = way[j0];
        } while (j0 != 0);
    }
    return -V[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<ll>> a(N, vector<ll>(N));
    for (auto& row : a) for (auto& x : row) cin >> x;
    ll X;
    vector<int> p;
    tie(X, p) = hungarian(a);
    cout << X << endl;
    for (int i = 0; i < N; ++i) cout << p[i] < (i < N-1 ? " " : "\n");
}
