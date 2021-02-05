#pragma once
#include <vector>

std::vector<int> convert_base(int n, int base) {
    int q = n / base, r = n % base;
    if (q == 0) return {r};
    auto ret = convert_base(q, base);
    ret.push_back(r);
    return ret;
}