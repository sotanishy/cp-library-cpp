#pragma once

template <typename T>
T isqrt(T n) {
    T x0 = n / 2;
    if (x0 == 0) return n;
    T x1 = (x0 + n / x0) / 2;
    while (x1 < x0) {
        x0 = x1;
        x1 = (x0 + n / x0) / 2;
    }
    return x0;
}