#pragma once
#include <stack>
#include <vector>

template <typename T>
std::vector<int> cartesian_tree(const std::vector<T>& a) {
    int n = a.size();
    std::vector<int> par(n, -1);
    std::stack<int> st;
    for (int i = 0; i < n; ++i) {
        int j = -1;
        while (!st.empty() && a[st.top()] >= a[i]) {
            j = st.top();
            st.pop();
        }
        if (!st.empty()) {
            par[i] = st.top();
        }
        if (j != -1) {
            par[j] = i;
        }
        st.push(i);
    }
    return par;
}