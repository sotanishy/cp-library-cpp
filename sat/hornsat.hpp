#pragma once
#include <stack>
#include <utility>
#include <vector>

std::vector<bool> horn_sat(
    int n_literals,
    const std::vector<std::pair<int, std::vector<int>>>& clauses) {
    const int n_clauses = clauses.size();
    std::vector<bool> val(n_literals, false);
    std::vector<std::vector<int>> neg(n_clauses), idx(n_literals);
    std::vector<int> pos(n_clauses), n_neg(n_clauses);

    int k = 0;
    for (auto& [p, n] : clauses) {
        pos[k] = p;
        neg[k] = n;
        n_neg[k] = n.size();
        for (int i : n) idx[i].push_back(k);
        ++k;
    }

    // if there is a clause with no negative literals and a positive literal,
    // make it positive and remove it from other clauses.
    // if there is no such clause, make all remaining literals negative.
    std::stack<int> st;
    for (int i = 0; i < n_clauses; ++i) {
        if (n_neg[i] == 0 && pos[i] != -1) {
            st.push(i);
        }
    }
    while (!st.empty()) {
        int i = st.top();
        st.pop();
        if (val[pos[i]]) continue;
        val[pos[i]] = true;
        for (int j : idx[pos[i]]) {
            --n_neg[j];
            if (n_neg[j] == 0 && pos[j] != -1) {
                st.push(j);
            }
        }
    }
    // check
    for (int i = 0; i < n_clauses; ++i) {
        bool v = false;
        if (pos[i] != -1) v |= val[pos[i]];
        for (int j : neg[i]) v |= !val[j];
        if (!v) {
            // not satisfiable
            return {};
        }
    }
    return val;
}