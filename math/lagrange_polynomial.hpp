#pragma once
#include <utility>
#include <vector>

#include "multipoint_evaluation.cpp"
#include "polynomial.cpp"

template <typename T>
Polynomial<T> lagrange_polynomial(const std::vector<T>& x,
                                  const std::vector<T>& y) {
    int n = x.size();
    int sz = 1;
    while (sz < n) sz <<= 1;

    auto rec = [&](auto& rec, int l, int r) -> Polynomial<T> {
        if (r - l == 1) {
            return {-x[l], 1};
        }
        int m = (l + r) / 2;
        return rec(rec, l, m) * rec(rec, m, r);
    };

    auto g = rec(rec, 0, n);
    auto dg = multipoint_evaluation(g.diff(), x);

    auto rec2 = [&](auto& rec2, int l,
                    int r) -> std::pair<Polynomial<T>, Polynomial<T>> {
        if (r - l == 1) {
            return {{y[l] / dg[l]}, {-x[l], 1}};
        }
        int m = (l + r) / 2;
        auto [pl, ql] = rec2(rec2, l, m);
        auto [pr, qr] = rec2(rec2, m, r);
        return {pl * qr + pr * ql, ql * qr};
    };

    return rec2(rec2, 0, n).first;
}
