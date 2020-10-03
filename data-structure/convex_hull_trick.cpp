#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct ConvexHullTrick {
    vector<pair<T, T>> lines;

    bool check(const pair<T, T>& l1, const pair<T, T>& l2, const pair<T, T>& l3) {
        if (l1 > l3) swap(l1, l3);
        return (l3.first - l1.first) * (l2.second - l1.second) >= (l2.first - l1.first) * (l3.second - l1.second);

    }

    void add(T a, T b) {
        pair<T, T> line(a, b);
        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line)) {
            lines.pop_back();
        }
        lines.push_back(line);
    }

    inline T f(int i, T x) {
        return lines[i].first * x + lines[i].second;
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
};