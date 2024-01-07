#pragma once
#include <utility>

/**
 * @brief Minimize Periodic Function
 * @see https://twitter.com/maspy_stars/status/1502589106039123970
 * @see https://twitter.com/noshi91/status/1477671298998616065
 */
template <typename T, typename F>
T minimize_periodic_function(int n, F f) {
    int a = 0, b = n, c = 2 * n;
    while (c - a > 2) {
        int l = (a + b) / 2, r = (b + c + 1) / 2;
        if (f(l) < f(b))
            std::tie(c, b) = std::make_pair(b, l);
        else if (f(b) > f(r))
            std::tie(a, b) = std::make_pair(b, r);
        else
            std::tie(a, c) = std::make_pair(l, r);
    }
    return f(b);
}