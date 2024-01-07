#pragma once
#include <vector>

#include "../data-structure/fenwick_tree.hpp"

/**
 * @brief Lexicographic Index of Permutations (in Factorial Number System)
 */

struct AddMonoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

std::vector<int> perm_to_num(const std::vector<int>& p) {
    const int n = p.size();
    std::vector<int> num(n);
    FenwickTree<AddMonoid> ft(n);
    for (int i = n - 1; i >= 0; --i) {
        ft.update(p[i], 1);
        num[n - i - 1] = ft.prefix_fold(p[i]);
    }
    return num;
}

std::vector<int> num_to_perm(const std::vector<int>& num) {
    const int n = num.size();
    std::vector<int> p(n);
    FenwickTree<AddMonoid> ft(n);
    for (int i = 0; i < n; ++i) ft.update(i, 1);
    for (int i = 0; i < n; ++i) {
        p[i] = ft.lower_bound(num[n - i - 1] + 1);
        ft.update(p[i], -1);
    }
    return p;
}