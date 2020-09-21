#include <bits/stdc++.h>

/*
 * @brief Sliding Window Aggregation
 * @docs docs/data-structure/sliding_window_aggregation.md
 */
template <typename M>
class SlidingWindowAggregation {
    using T = typename M::T;

public:
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
                front.emplace(x, M::op(x, front.top().second));
            }
        }
        front.pop();
    }

    T fold() const {
        T ret = M::id;
        if (!front.empty()) ret = M::op(ret, front.top().second);
        if (!back.empty()) ret = M::op(ret, back.top().second);
        return ret;
    }

private:
    std::stack<std::pair<T, T>> front, back;
};