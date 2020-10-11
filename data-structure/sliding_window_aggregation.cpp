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

    bool empty() const {
        return front.empty() && back.empty();
    }

    T fold() const {
        assert(!empty());
        if (front.empty()) return back.top().second;
        if (back.empty()) return front.top().second;
        return M::op(front.top().second, back.top().second);
    }

private:
    std::stack<std::pair<T, T>> front, back;
};