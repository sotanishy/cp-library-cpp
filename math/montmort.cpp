#pragma once
#include <vector>

/*
 * @brief Monmort Number
 */
template <typename T>
std::vector<T> montmort(int n) {
    std::vector<T> ret(n + 1);
    if (n == 1) return ret;
    ret[2] = 1;
    for (int i = 3; i <= n; ++i) {
        ret[i] = (ret[i - 1] + ret[i - 2]) * (i - 1);
    }
    return ret;
}