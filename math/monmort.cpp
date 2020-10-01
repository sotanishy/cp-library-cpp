#include <bits/stdc++.h>

/*
 * @brief Monmort Number
 */
template <typename T>
T monmort(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    T a = 1, b = 2, c;
    for (int i = 3; i <= n; ++i) {
        c = (i - 1) * (a + b);
        a = b;
        b = c;
    }
    return b;
}