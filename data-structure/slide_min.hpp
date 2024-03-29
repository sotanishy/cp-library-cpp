#pragma once
#include <deque>
#include <functional>
#include <utility>

template <typename T, typename Compare = std::less<>>
class SlideMin {
   public:
    void push(T x) {
        while (!dq.empty() && !cmp(dq.back().first, x)) dq.pop_back();
        dq.emplace_back(x, r++);
    }

    void pop() {
        if (dq.front().second == l) dq.pop_front();
        ++l;
    }

    T get() const { return dq.front().first; }

   private:
    int l = 0, r = 0;
    std::deque<std::pair<T, int>> dq;
    Compare cmp;
};