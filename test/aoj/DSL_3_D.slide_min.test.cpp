#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../../data-structure/slide_min.cpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    SlideMin<int> sm;
    for (int i = 0; i < L; i++) sm.push(a[i]);
    for (int i = L; i < N; i++) {
        cout << sm.get() << " ";
        sm.pop();
        sm.push(a[i]);
    }
    cout << sm.get() << endl;
}