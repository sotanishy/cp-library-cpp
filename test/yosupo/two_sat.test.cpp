#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../sat/twosat.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string _p, _cnf;
    int N, M;
    cin >> _p >> _cnf >> N >> M;
    vector<tuple<int, bool, int, bool>> clauses;
    for (int i = 0; i < M; i++) {
        int a, b, _c;
        cin >> a >> b >> _c;
        clauses.push_back({abs(a) - 1, (a > 0), abs(b) - 1, (b > 0)});
    }
    auto ans = two_sat(N, clauses);
    if (!ans.empty()) {
        cout << "s SATISFIABLE\nv";
        for (int i = 0; i < N; i++) {
            cout << " " << (ans[i] ? 1 : -1) * (i + 1);
        }
        cout << " 0\n";
    } else {
        cout << "s UNSATISFIABLE\n";
    }
}
