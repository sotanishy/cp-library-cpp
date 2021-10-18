#pragma once
#include <algorithm>
#include <utility>
#include <vector>

template <typename T>
class ConvexHullTrick {
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
            while (lines.size() - head >= 2 && lines[head](x) > lines[head + 1](x)) {
                ++head;
            }
            return lines[head](x);
        } else {
            int lb = -1, ub = lines.size() - 1;
            while (ub - lb > 1) {
                int m = (lb + ub) / 2;
                if (lines[m](x) > lines[m + 1](x)) {
                    lb = m;
                } else {
                    ub = m;
                }
            }
            return lines[ub](x);
        }
    }

private:
    struct Line {
        T a, b;
        Line(T a, T b) : a(a), b(b) {}
        T operator()(T x) const { return a * x + b; }
    };

    std::vector<Line> lines;
    bool monotone_query;
    int head = 0;

    static bool check(Line l1, Line l2, Line l3) {
        if (l2.a == l3.a) return l2.b >= l3.b;
        return 1.0 * (l2.b - l1.b) / (l2.a - l1.a) <= 1.0 * (l3.b - l2.b) / (l3.a - l2.a);
    }
};