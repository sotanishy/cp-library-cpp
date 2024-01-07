#pragma once
#include <utility>
#include <vector>

#include "aho_corasick.hpp"
#include "kmp.hpp"

std::vector<std::pair<int, int>> pattern_search_2d(
    const std::vector<std::string>& txt, const std::vector<std::string>& pat) {
    AhoCorasick aho;
    for (int i = 0; i < (int)pat.size(); ++i) {
        aho.insert(pat[i], i);
    }
    aho.build();

    std::vector<int> pat_state(pat.size());
    for (int i = 0; i < (int)pat.size(); ++i) {
        pat_state[i] = aho.accept_state[i];
    }

    std::vector txt_state(txt[0].size(), std::vector<int>(txt.size()));
    for (int i = 0; i < (int)txt.size(); ++i) {
        int k = 0;
        for (int j = 0; j < (int)txt[0].size(); ++j) {
            k = aho.get_next(k, txt[i][j]);
            txt_state[j][i] = k;
        }
    }

    auto pf = prefix_function(pat_state);
    std::vector<std::pair<int, int>> res;
    for (int j = 0; j < (int)txt_state.size(); ++j) {
        auto match = kmp(txt_state[j], pat_state, pf);
        for (int i : match) {
            res.emplace_back(i, j - (int)pat[0].size() + 1);
        }
    }

    return res;
}