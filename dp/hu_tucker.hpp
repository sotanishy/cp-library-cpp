#pragma once
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

#include "../data-structure/leftist_heap.hpp"

template <typename T>
T hu_tucker(std::vector<T> w) {
    const int n = w.size();
    const T INF = std::numeric_limits<T>::max() / 2;
    std::vector<LeftistHeap<T>> heaps(n - 1);  // interior nodes in each group
    std::vector<int> left(n), right(n);
    std::vector<T> cs(n - 1);
    using P = std::pair<T, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    for (int i = 0; i < n - 1; ++i) {
        left[i] = i - 1;
        right[i] = i + 1;
        cs[i] = w[i] + w[i + 1];
        pq.emplace(cs[i], i);
    }
    T ret = 0;
    for (int k = 0; k < n - 1; ++k) {
        T c;
        int i;
        // find the optimal nodes to merge
        do {
            std::tie(c, i) = pq.top();
            pq.pop();
        } while (right[i] == -1 || cs[i] != c);

        bool merge_l = false, merge_r = false;
        if (w[i] + w[right[i]] == c) {  // lr
            merge_l = merge_r = true;
        } else {
            T top = heaps[i].top().second;
            heaps[i].pop();
            if (w[i] + top == c) {  // lm
                merge_l = true;
            } else if (top + w[right[i]] == c) {  // mr
                merge_r = true;
            } else {  // mm
                heaps[i].pop();
            }
        }
        ret += c;
        heaps[i].push(-1, c);
        if (merge_l) {
            w[i] = INF;
        }
        if (merge_r) {
            w[right[i]] = INF;
        }

        // merge left
        if (merge_l && i > 0) {
            int j = left[i];
            heaps[j] =
                LeftistHeap<T>::meld(std::move(heaps[j]), std::move(heaps[i]));
            right[j] = right[i];
            right[i] = -1;
            left[right[j]] = j;
            i = j;
        }
        // merge right
        if (merge_r && right[i] < n - 1) {
            int j = right[i];
            heaps[i] =
                LeftistHeap<T>::meld(std::move(heaps[i]), std::move(heaps[j]));
            right[i] = right[j];
            right[j] = -1;
            left[right[i]] = i;
        }

        cs[i] = w[i] + w[right[i]];  // lr
        if (!heaps[i].empty()) {
            T top = heaps[i].top().second;
            heaps[i].pop();
            cs[i] =
                std::min(cs[i], std::min(w[i], w[right[i]]) + top);  // lm or mr
            if (!heaps[i].empty()) {
                cs[i] = std::min(cs[i], top + heaps[i].top().second);  // mm
            }
            heaps[i].push(-1, top);
        }
        pq.emplace(cs[i], i);
    }
    return ret;
}