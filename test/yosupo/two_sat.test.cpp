#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../graph/twosat.cpp"

using ll = long long;

int main() {
    string _p, _cnf;
    int N, M;
    cin >> _p >> _cnf >> N >> M;
    TwoSat sat(N);
    for (int i = 0; i < M; i++) {
        int a, b, _c;
        cin >> a >> b >> _c;
        sat.add_clause(abs(a) - 1, (a > 0), abs(b) - 1, (b > 0));
    }
    sat.solve();
    if (sat.satisfiable) {
        cout << "s SATISFIABLE\nv";
        for (int i = 0; i < N; i++) {
            cout << " " << (sat[i] ? 1 : -1) * (i + 1);
        }
        cout << " 0\n";
    } else {
        cout << "s UNSATISFIABLE\n";
    }
}
