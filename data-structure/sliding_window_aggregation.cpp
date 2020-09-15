#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Sliding Window Aggregation
 * @docs docs/data-structure/sliding_window_aggregation.md
 */
template <typename M>
struct SlidingWindowAggregation {
    using T = typename M::T;

    stack<pair<T, T>> front, back;

    void push(T x) {
        if (back.empty()) back.emplace(x, x);
        else back.emplace(x, M::op(back.top().second, x));
    }

    void pop() {
        if (front.empty()) {
            if (back.empty()) return;
            T x = back.top().first;
            back.pop();
            front.emplace(x, x);
            while (!back.empty()) {
                x = back.top().first;
                back.pop();
                front.emplace(x, M::op(front.top().second, x));
            }
        }
        front.pop();
    }

    T fold() {
        T ret = M::id;
        if (!front.empty()) ret = M::op(ret, front.top().second);
        if (!back.empty()) ret = M::op(ret, back.top().second);
        return ret;
    }
};