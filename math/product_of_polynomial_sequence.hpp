#include <vector>

#include "polynomial.cpp"

/**
 * @brief Product of Polynomial Sequence
 * O(n (log n)^2)
 */
template <typename T>
Polynomial<T> product_of_polynomial_sequence(
    const std::vector<Polynomial<T>> polys) {
    if (polys.empty()) return {1};
    auto dfs = [&](auto& dfs, int l, int r) -> Polynomial<T> {
        if (l + 1 == r) return polys[l];
        int m = (l + r) / 2;
        return dfs(dfs, l, m) * dfs(dfs, m, r);
    };
    return dfs(dfs, 0, polys.size());
}