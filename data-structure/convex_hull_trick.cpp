#pragma once
#include <algorithm>
#include <utility>
#include <vector>

/*
 * @brief Convex Hull Trick
 */
template <typename T>
class ConvexHullTrick {
    using Line = std::pair<T, T>;

public:
    void add(T a, T b) {
        Line line(a, b);
        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line)) {
            lines.pop_back();
        }
        lines.push_back(line);
    }

    T get(T x) {
        int lb = 0, ub = lines.size() - 1;
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (f(m, x) > f(m + 1, x))) lb = m;
            else ub = m;
        }
        return f(ub, x);
    }

private:
    std::vector<Line> lines;

    bool check(const Line& l1, const Line& l2, const Line& l3) {
        if (l1 > l3) std::swap(l1, l3);
        return (l3.first - l1.first) * (l2.second - l1.second) >= (l2.first - l1.first) * (l3.second - l1.second);

    }

    inline T f(int i, T x) {
        return lines[i].first * x + lines[i].second;
    }
};