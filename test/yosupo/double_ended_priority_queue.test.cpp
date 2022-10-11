#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

// #include "../../data-structure/unionfind/union_find.cpp"

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MinMaxHeap {
public:
    MinMaxHeap() = default;
    explicit MinMaxHeap(const std::vector<T>& v) : heap(v) {
        for (int i = (int) heap.size() / 2 - 1; i >= 0; --i) {
            pushdown(i);
        }
    }

    void insert(T x) {
        heap.push_back(x);
        pushup(heap.size() - 1);
    }

    T min_element() const {
        assert(!heap.empty());
        return heap[0];
    }

    T max_element() const {
        assert(!heap.empty());
        if (heap.size() <= 2) return heap.back();
        return std::max(heap[1], heap[2]);
    }

    void erase_min() {
        assert(!heap.empty());
        heap[0] = heap.back();
        heap.pop_back();
        pushdown(0);
    }

    void erase_max() {
        assert(!heap.empty());
        if (heap.size() <= 2) {
            heap.pop_back();
            return;
        }
        if (heap.size() == 3) {
            heap[1] = std::min(heap[1], heap[2]);
            heap.pop_back();
            return;
        }
        int i = heap[1] > heap[2] ? 1 : 2;
        heap[i] = heap.back();
        heap.pop_back();
        pushdown(i);
    }

private:
    std::vector<T> heap;

    void pushdown(int i) {
        int d = 31 - __builtin_clz(i + 1);
        int n = heap.size();

        while (true) {
            int l = 2*i + 1, r = l + 1;
            if (l >= n) return;

            int m = i;  // idx of smallest child or grandchild
            vector<int> check = {l, r, 2*l + 1, 2*l + 2, 2*r + 1, 2*r + 2};
            for (int j : check) {
                if (j < n && ((d % 2) ^ (heap[j] < heap[m]))) m = j;
            }

            if (m >= 2*l + 1) {  // grandchild
                if ((d % 2) ^ (heap[m] < heap[i])) {
                    std::swap(heap[m], heap[i]);
                    int p = (m - 1) / 2;  // parent of m
                    if ((d % 2) ^ (heap[m] > heap[p])) std::swap(heap[m], heap[p]);
                    i = m;
                } else {
                    break;
                }
            } else {
                std::swap(heap[m], heap[i]);
                break;
            }
        }
    }

    void pushup(int i) {
        if (i == 0) return;
        int p = (i - 1) / 2;
        int d = 31 - __builtin_clz(i + 1);
        if ((d % 2) ^ (heap[i] > heap[p])) {
            std::swap(heap[i], heap[p]);
            i = p;
            --d;
        }
        while (i >= 3) {  // while i has a grandparent
            int g = ((i - 1) / 2 - 1) / 2;
            if ((d % 2) ^ (heap[i] > heap[g])) break;
            std::swap(heap[i], heap[g]);
            i = g;
        }
    }
};

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