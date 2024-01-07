#pragma once
#include <optional>
#include <vector>

template <typename T>
std::optional<T> majority(const std::vector<T>& v) {
    T m;
    int cnt = 0;
    for (auto x : v) {
        if (cnt == 0) {
            m = x;
            ++cnt;
        } else if (m == x) {
            ++cnt;
        } else {
            --cnt;
        }
    }
    cnt = 0;
    for (auto x : v) {
        if (m == x) {
            ++cnt;
        }
    }
    return cnt > (int)v.size() / 2 ? std::optional<T>(m) : std::nullopt;
}