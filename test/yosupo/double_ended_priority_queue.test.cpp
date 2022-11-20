#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../data-structure/min_max_heap.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> S(N);
    for (auto& x : S) cin >> x;
    MinMaxHeap<int> heap(S);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int x;
            cin >> x;
            heap.insert(x);
        } else if (t == 1) {
            cout << heap.min_element() << "\n";
            heap.erase_min();
        } else {
            cout << heap.max_element() << "\n";
            heap.erase_max();
        }
    }
}