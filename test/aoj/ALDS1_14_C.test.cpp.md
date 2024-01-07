---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/aho_corasick.hpp
    title: Aho-Corasick Algorithm
  - icon: ':heavy_check_mark:'
    path: string/kmp.hpp
    title: Knuth-Morris-Pratt Algorithm
  - icon: ':heavy_check_mark:'
    path: string/pattern_search_2d.hpp
    title: 2D Pattern Search (Baker-Bird Algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_C.test.cpp\"\n#define PROBLEM \\\n   \
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\n\n\
    #include <bits/stdc++.h>\n\n#line 4 \"string/pattern_search_2d.hpp\"\n\n#line\
    \ 8 \"string/aho_corasick.hpp\"\n\nclass AhoCorasick {\n   public:\n    struct\
    \ Node {\n        std::map<char, int> ch;\n        std::vector<int> accept;\n\
    \        int link = -1;\n        int cnt = 0;\n\n        Node() = default;\n \
    \   };\n\n    std::vector<Node> states;\n    std::map<int, int> accept_state;\n\
    \n    explicit AhoCorasick() : states(1) {}\n\n    void insert(const std::string&\
    \ s, int id = -1) {\n        int i = 0;\n        for (char c : s) {\n        \
    \    if (!states[i].ch.count(c)) {\n                states[i].ch[c] = states.size();\n\
    \                states.emplace_back();\n            }\n            i = states[i].ch[c];\n\
    \        }\n        ++states[i].cnt;\n        states[i].accept.push_back(id);\n\
    \        accept_state[id] = i;\n    }\n\n    void clear() {\n        states.clear();\n\
    \        states.emplace_back();\n    }\n\n    int get_next(int i, char c) const\
    \ {\n        while (i != -1 && !states[i].ch.count(c)) i = states[i].link;\n \
    \       return i != -1 ? states[i].ch.at(c) : 0;\n    }\n\n    void build() {\n\
    \        std::queue<int> que;\n        que.push(0);\n        while (!que.empty())\
    \ {\n            int i = que.front();\n            que.pop();\n\n            for\
    \ (auto [c, j] : states[i].ch) {\n                states[j].link = get_next(states[i].link,\
    \ c);\n                states[j].cnt += states[states[j].link].cnt;\n\n      \
    \          auto& a = states[j].accept;\n                auto& b = states[states[j].link].accept;\n\
    \                std::vector<int> accept;\n                std::ranges::set_union(a,\
    \ b, std::back_inserter(accept));\n                a = accept;\n\n           \
    \     que.push(j);\n            }\n        }\n    }\n\n    long long count(const\
    \ std::string& str) const {\n        long long ret = 0;\n        int i = 0;\n\
    \        for (auto c : str) {\n            i = get_next(i, c);\n            ret\
    \ += states[i].cnt;\n        }\n        return ret;\n    }\n\n    // list of (id,\
    \ index)\n    std::vector<std::pair<int, int>> match(const std::string& str) const\
    \ {\n        std::vector<std::pair<int, int>> ret;\n        int i = 0;\n     \
    \   for (int k = 0; k < (int)str.size(); ++k) {\n            char c = str[k];\n\
    \            i = get_next(i, c);\n            for (auto id : states[i].accept)\
    \ {\n                ret.emplace_back(id, k);\n            }\n        }\n    \
    \    return ret;\n    }\n};\n\nclass DynamicAhoCorasick {\n    std::vector<std::vector<std::string>>\
    \ dict;\n    std::vector<AhoCorasick> ac;\n\n   public:\n    void insert(const\
    \ std::string& s) {\n        int k = 0;\n        while (k < (int)dict.size() &&\
    \ !dict[k].empty()) ++k;\n        if (k == (int)dict.size()) {\n            dict.emplace_back();\n\
    \            ac.emplace_back();\n        }\n\n        dict[k].push_back(s);\n\
    \        ac[k].insert(s);\n\n        for (int i = 0; i < k; ++i) {\n         \
    \   for (auto& t : dict[i]) {\n                ac[k].insert(t);\n            }\n\
    \            dict[k].insert(dict[k].end(), dict[i].begin(), dict[i].end());\n\
    \            ac[i].clear();\n            dict[i].clear();\n        }\n\n     \
    \   ac[k].build();\n    }\n\n    long long count(const std::string& str) const\
    \ {\n        return std::accumulate(\n            ac.begin(), ac.end(), 0LL,\n\
    \            [&](auto res, auto& a) { return res + a.count(str); });\n    }\n\
    };\n#line 4 \"string/kmp.hpp\"\n\ntemplate <typename T>\nstd::vector<int> prefix_function(const\
    \ std::vector<T>& s) {\n    const int n = s.size();\n    std::vector<int> ret(n);\n\
    \    for (int len = 0, i = 1; i < n; ++i) {\n        if (s[i] == s[len]) {\n \
    \           ++len;\n            ret[i] = len;\n        } else {\n            if\
    \ (len != 0) {\n                len = ret[len - 1];\n                --i;\n  \
    \          } else {\n                ret[i] = 0;\n            }\n        }\n \
    \   }\n    return ret;\n}\n\ntemplate <typename T>\nstd::vector<int> kmp(const\
    \ std::vector<T>& txt, const std::vector<T>& pat,\n                     const\
    \ std::vector<int>& pf) {\n    const int n = txt.size(), m = pat.size();\n   \
    \ std::vector<int> match;\n    for (int i = 0, j = 0; i < n;) {\n        if (pat[j]\
    \ == txt[i]) {\n            ++i;\n            ++j;\n        }\n        if (j ==\
    \ m) {\n            match.push_back(i - j);\n            j = pf[j - 1];\n    \
    \    } else if (i < n && pat[j] != txt[i]) {\n            if (j != 0) {\n    \
    \            j = pf[j - 1];\n            } else {\n                ++i;\n    \
    \        }\n        }\n    }\n    return match;\n}\n\nstd::vector<int> prefix_function(const\
    \ std::string& s) {\n    return prefix_function(std::vector<char>(s.begin(), s.end()));\n\
    }\n\nstd::vector<int> kmp(const std::string& txt, const std::string& pat,\n  \
    \                   const std::vector<int>& pf) {\n    return kmp(std::vector<char>(txt.begin(),\
    \ txt.end()),\n               std::vector<char>(pat.begin(), pat.end()), pf);\n\
    }\n\ntemplate <int AlphabetSize, int Offset>\nstd::vector<std::vector<std::pair<int,\
    \ bool>>> matching_automaton(\n    const std::string& s) {\n    const int n =\
    \ s.size();\n    auto lps = prefix_function(s);\n    std::vector aut(n, std::vector<std::pair<int,\
    \ bool>>(AlphabetSize));\n    for (int i = 0; i < n; ++i) {\n        for (int\
    \ c = 0; c < AlphabetSize; ++c) {\n            if (Offset + c == s[i]) {\n   \
    \             if (i == n - 1) {\n                    aut[i][c] = {lps[i], true};\n\
    \                } else {\n                    aut[i][c] = {i + 1, false};\n \
    \               }\n            } else {\n                aut[i][c] = {i > 0 ?\
    \ aut[lps[i - 1]][c].first : 0, 0};\n            }\n        }\n    }\n    return\
    \ aut;\n}\n#line 7 \"string/pattern_search_2d.hpp\"\n\nstd::vector<std::pair<int,\
    \ int>> pattern_search_2d(\n    const std::vector<std::string>& txt, const std::vector<std::string>&\
    \ pat) {\n    AhoCorasick aho;\n    for (int i = 0; i < (int)pat.size(); ++i)\
    \ {\n        aho.insert(pat[i], i);\n    }\n    aho.build();\n\n    std::vector<int>\
    \ pat_state(pat.size());\n    for (int i = 0; i < (int)pat.size(); ++i) {\n  \
    \      pat_state[i] = aho.accept_state[i];\n    }\n\n    std::vector txt_state(txt[0].size(),\
    \ std::vector<int>(txt.size()));\n    for (int i = 0; i < (int)txt.size(); ++i)\
    \ {\n        int k = 0;\n        for (int j = 0; j < (int)txt[0].size(); ++j)\
    \ {\n            k = aho.get_next(k, txt[i][j]);\n            txt_state[j][i]\
    \ = k;\n        }\n    }\n\n    auto pf = prefix_function(pat_state);\n    std::vector<std::pair<int,\
    \ int>> res;\n    for (int j = 0; j < (int)txt_state.size(); ++j) {\n        auto\
    \ match = kmp(txt_state[j], pat_state, pf);\n        for (int i : match) {\n \
    \           res.emplace_back(i, j - (int)pat[0].size() + 1);\n        }\n    }\n\
    \n    return res;\n}\n#line 7 \"test/aoj/ALDS1_14_C.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int H, W;\n    cin >> H >> W;\n    vector<string> txt(H);\n    for (auto&\
    \ x : txt) cin >> x;\n    int R, C;\n    cin >> R >> C;\n    vector<string> pat(R);\n\
    \    for (auto& x : pat) cin >> x;\n\n    auto ans = pattern_search_2d(txt, pat);\n\
    \    sort(ans.begin(), ans.end());\n    for (auto [i, j] : ans) {\n        cout\
    \ << i << \" \" << j << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../string/pattern_search_2d.hpp\"\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int H, W;\n    cin >> H >> W;\n    vector<string> txt(H);\n\
    \    for (auto& x : txt) cin >> x;\n    int R, C;\n    cin >> R >> C;\n    vector<string>\
    \ pat(R);\n    for (auto& x : pat) cin >> x;\n\n    auto ans = pattern_search_2d(txt,\
    \ pat);\n    sort(ans.begin(), ans.end());\n    for (auto [i, j] : ans) {\n  \
    \      cout << i << \" \" << j << \"\\n\";\n    }\n}"
  dependsOn:
  - string/pattern_search_2d.hpp
  - string/aho_corasick.hpp
  - string/kmp.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_C.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_C.test.cpp
- /verify/test/aoj/ALDS1_14_C.test.cpp.html
title: test/aoj/ALDS1_14_C.test.cpp
---
