#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../../data-structure/sparse_table.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    SparseTable<int> st(a);

    for (int i = 0; i < N - L + 1; i++) {
        cout << st.query(i, i + L);
        if (i < N - L) cout << " ";
        else cout << "\n";
    }
}