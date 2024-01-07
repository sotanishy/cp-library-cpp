#pragma once
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

/**
 * @brief Largest Rectangle
 */
template <typename T>
T largest_rectangle(const std::vector<T>& h) {
    int n = h.size();
    std::vector<int> left(n), right(n);
    std::stack<std::pair<T, int>> st;
    st.emplace(-1, -1);
    for (int i = 0; i < n; ++i) {
        while (st.top().first >= h[i]) st.pop();
        left[i] = st.top().second + 1;
        st.emplace(h[i], i);
    }
    while (!st.empty()) st.pop();
    st.emplace(-1, n);
    for (int i = n - 1; i >= 0; --i) {
        while (st.top().first >= h[i]) st.pop();
        right[i] = st.top().second;
        st.emplace(h[i], i);
    }
    T ret = 0;
    for (int i = 0; i < n; ++i)
        ret = std::max(ret, h[i] * (right[i] - left[i]));
    return ret;
}