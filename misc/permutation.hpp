#pragma once
#include <vector>

#include "../data-structure/fenwick_tree.cpp"

/**
 * @brief Lexicographic Index of Permutations (in Factorial Number System)
 */

struct AddMonoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

std::vector<int> perm_to_num(const std::vector<int>& P) {
    int N = P.size();
    std::vector<int> num(N);
    FenwickTree<AddMonoid> ft(N);
    for (int i = N - 1; i >= 0; --i) {
        ft.update(P[i], 1);
        num[N - i - 1] = ft.prefix_fold(P[i]);
    }
    return num;
}

std::vector<int> num_to_perm(const std::vector<int>& num) {
    int N = num.size();
    std::vector<int> P(N);
    FenwickTree<AddMonoid> ft(N);
    for (int i = 0; i < N; ++i) ft.update(i, 1);
    for (int i = 0; i < N; ++i) {
        P[i] = ft.lower_bound(num[N - i - 1] + 1);
        ft.update(P[i], -1);
    }
    return P;
}