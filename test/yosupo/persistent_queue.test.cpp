#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include "../../data-structure/persistent_queue.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    PersistentQueue<int> init;
    vector<PersistentQueue<int>> ver(Q);
    for (int i = 0; i < Q; ++i) {
        int q, t;
        cin >> q >> t;
        if (q == 0) {
            int x;
            cin >> x;
            if (t == -1)
                ver[i] = init.push(x);
            else
                ver[i] = ver[t].push(x);
        } else {
            cout << ver[t].front() << "\n";
            ver[i] = ver[t].pop();
        }
    }
}