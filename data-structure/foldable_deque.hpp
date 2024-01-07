#pragma once
#include <cassert>
#include <stack>
#include <utility>
#include <vector>

template <typename S>
class FoldableDeque {
    using T = typename S::T;

   public:
    void push_front(const T& x) {
        if (front.empty())
            front.emplace(x, x);
        else
            front.emplace(x, S::op(x, front.top().second));
    }

    void push_back(const T& x) {
        if (back.empty())
            back.emplace(x, x);
        else
            back.emplace(x, S::op(back.top().second, x));
    }

    void pop_front() {
        assert(!empty());
        if (front.empty()) {
            std::vector<T> xs;
            while (!back.empty()) {
                xs.push_back(back.top().first);
                back.pop();
            }
            int n = xs.size();
            for (int i = n / 2; i < n; ++i) push_front(xs[i]);
            for (int i = n / 2 - 1; i >= 0; --i) push_back(xs[i]);
        }
        front.pop();
    }

    void pop_back() {
        assert(!empty());
        if (back.empty()) {
            std::vector<T> xs;
            while (!front.empty()) {
                xs.push_back(front.top().first);
                front.pop();
            }
            int n = xs.size();
            for (int i = n / 2 - 1; i >= 0; --i) push_front(xs[i]);
            for (int i = n / 2; i < n; ++i) push_back(xs[i]);
        }
        back.pop();
    }

    bool empty() const { return front.empty() && back.empty(); }

    T fold() const {
        assert(!empty());
        if (front.empty()) return back.top().second;
        if (back.empty()) return front.top().second;
        return S::op(front.top().second, back.top().second);
    }

   private:
    std::stack<std::pair<T, T>> front, back;
};
