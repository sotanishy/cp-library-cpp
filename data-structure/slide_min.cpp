#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Slide Min
 * @docs docs/data-structure/slide_min.md
 */
template <typename T, typename Compare = less<>>
struct SlideMin {
    int l = 0, r = 0;
    deque<pair<T, int>> dq;
    Compare cmp;

    void push(T x) {
        while (!dq.empty() && !cmp(dq.back().first, x)) dq.pop_back();
        dq.emplace_back(x, r++);
    }

    void pop() {
        if (dq.front().second == l) dq.pop_front();
        l++;
    }

    T get() {
        return dq.front().first;
    }
};