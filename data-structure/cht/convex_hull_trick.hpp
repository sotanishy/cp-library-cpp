#pragma once
#include <algorithm>
#include <deque>
#include <utility>
#include <vector>

template <typename T>
class ConvexHullTrick {
   public:
    void add(T a, T b) {
        Line line(a, b);
        while (lines.size() >= 2 &&
               check(lines[lines.size() - 2], lines.back(), line)) {
            lines.pop_back();
        }
        lines.push_back(line);
    }

    T get(T x) {
        while (lines.size() >= 2 && lines.front()(x) > lines[1](x)) {
            lines.pop_front();
        }
        return lines.front()(x);
    }

   private:
    struct Line {
        T a, b;
        Line(T a, T b) : a(a), b(b) {}
        T operator()(T x) const { return a * x + b; }
    };

    std::deque<Line> lines;

    static bool check(Line l1, Line l2, Line l3) {
        if (l1.a == l2.a) return l2.b >= l1.b;
        if (l2.a == l3.a) return l2.b >= l3.b;
        return 1.0 * (l2.b - l1.b) / (l2.a - l1.a) <=
               1.0 * (l3.b - l2.b) / (l3.a - l2.a);
    }
};