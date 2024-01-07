#pragma once
#include <stack>
#include <vector>

std::vector<int> stable_matching(const std::vector<std::vector<int>>& man,
                                 const std::vector<std::vector<int>>& woman) {
    const int n = man.size();
    // the smaller the better
    std::vector preference(n, std::vector<int>(n));
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            preference[j][woman[j][k]] = k;
        }
    }
    std::vector<int> idx(n);
    std::vector<int> engaged(n, -1);
    std::stack<int> st;
    for (int i = 0; i < n; ++i) st.push(i);
    while (!st.empty()) {
        int i = st.top(), j = man[i][idx[i]++];
        if (engaged[j] == -1 || preference[j][i] < preference[j][engaged[j]]) {
            st.pop();
            if (engaged[j] != -1) st.push(engaged[j]);
            engaged[j] = i;
        }
    }
    return engaged;
}