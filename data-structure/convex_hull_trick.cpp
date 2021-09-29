#pragma once
#include <algorithm>
#include <utility>
#include <vector>

template <typename T>
class ConvexHullTrick {
    using Line = std::pair<T, T>;

public:
    explicit ConvexHullTrick(bool monotone_query = false) : monotone_query(monotone_query) {}

    void add(T a, T b) {
        Line line(a, b);
        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line)) {
            lines.pop_back();
        }
        lines.push_back(line);
    }

    T get(T x) {
        if (monotone_query) {
            while (lines.size() - head >= 2 && f(head, x) > f(head + 1, x)) {
                ++head;
            }
            return f(head, x);
        } else {
            int lb = -1, ub = lines.size() - 1;
            while (ub - lb > 1) {
                int m = (lb + ub) / 2;
                if (f(m, x) > f(m + 1, x)) {
                    lb = m;
                } else {
                    ub = m;
                }
            }
            return f(ub, x);
        }
    }

private:
    std::vector<Line> lines;
    bool monotone_query;
    int head = 0;

    bool check(Line l1, Line l2, Line l3) {
        if (l1 > l3) std::swap(l1, l3);
        return (l3.first - l1.first) * (l2.second - l1.second) >=
               (l2.first - l1.first) * (l3.second - l1.second);
    }

    inline T f(int i, T x) {
        return lines[i].first * x + lines[i].second;
    }
};