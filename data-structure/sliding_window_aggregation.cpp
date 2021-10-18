#pragma once
#include <cassert>
#include <stack>
#include <utility>

template <typename S>
class SlidingWindowAggregation {
    using T = typename S::T;

public:
    void push(const T& x) {
        if (back.empty()) back.emplace(x, x);
        else back.emplace(x, S::op(back.top().second, x));
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
                front.emplace(x, S::op(x, front.top().second));
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
        return S::op(front.top().second, back.top().second);
    }

private:
    std::stack<std::pair<T, T>> front, back;
};