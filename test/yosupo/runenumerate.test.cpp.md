---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/enumerate_runs.hpp
    title: Enumerate Runs
  - icon: ':x:'
    path: string/z_array.hpp
    title: Z Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "#line 1 \"test/yosupo/runenumerate.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/runenumerate\"\n\n#line 2 \"string/enumerate_runs.hpp\"\
    \n#include <algorithm>\n#include <utility>\n#include <vector>\n\n#line 2 \"string/z_array.hpp\"\
    \n#include <string>\n#line 4 \"string/z_array.hpp\"\n\nstd::vector<int> z_array(const\
    \ std::string& s) {\n    const int n = s.size();\n    std::vector<int> z(n);\n\
    \    z[0] = n;\n    int l = 0, r = 0;\n    for (int i = 1; i < n; ++i) {\n   \
    \     int k = i - l;\n        if (i <= r && z[k] < r - i + 1) {\n            z[i]\
    \ = z[k];\n        } else {\n            l = i;\n            if (i > r) r = i;\n\
    \            while (r < n && s[r - l] == s[r]) ++r;\n            --r;\n      \
    \      z[i] = r - l + 1;\n        }\n    }\n    return z;\n}\n#line 7 \"string/enumerate_runs.hpp\"\
    \n\nstd::vector<std::vector<std::pair<int, int>>> enumerate_runs(\n    const std::string&\
    \ s) {\n    std::vector<std::vector<std::pair<int, int>>> runs(s.size() + 1);\n\
    \n    auto calc = [&](const std::string& u, const std::string& v) {\n        const\
    \ int nu = u.size(), nv = v.size();\n        std::string ru(u.rbegin(), u.rend());\n\
    \        auto z1 = z_array(ru);\n        auto z2 = z_array(v + '$' + u + v);\n\
    \        std::vector<std::tuple<int, int, int>> res;\n        for (int i = 0;\
    \ i < nu; ++i) {\n            int period = nu - i;\n            int left = period\
    \ + (i > 0 ? z1[nu - i] : 0);\n            int right = z2[nv + 1 + i];\n     \
    \       if (2 * period <= left + right) {\n                res.emplace_back(nu\
    \ - left, nv - right, period);\n            }\n        }\n        return res;\n\
    \    };\n\n    auto rec = [&](auto& rec, int l, int r) {\n        if (r - l ==\
    \ 1) return;\n        int m = std::midpoint(l, r);\n        rec(rec, l, m);\n\
    \        rec(rec, m, r);\n\n        std::string u(s.begin() + l, s.begin() + m);\n\
    \        std::string v(s.begin() + m, s.begin() + r);\n        for (auto [a, b,\
    \ p] : calc(u, v)) {\n            runs[p].emplace_back(l + a, r - b);\n      \
    \  }\n\n        std::string ru(u.rbegin(), u.rend());\n        std::string rv(v.rbegin(),\
    \ v.rend());\n        for (auto [a, b, p] : calc(rv, ru)) {\n            runs[p].emplace_back(l\
    \ + b, r - a);\n        }\n    };\n\n    rec(rec, 0, s.size());\n\n    // remove\
    \ duplicates\n    for (int p = 1; p <= (int)s.size(); ++p) {\n        std::ranges::sort(runs[p],\
    \ [&](auto& p, auto& q) {\n            return std::make_pair(p.first, -p.second)\
    \ <\n                   std::make_pair(q.first, -q.second);\n        });\n   \
    \     std::vector<std::pair<int, int>> res;\n        int mx = -1;\n        for\
    \ (auto [l, r] : runs[p]) {\n            if (r <= mx) continue;\n            mx\
    \ = r;\n            res.emplace_back(l, r);\n        }\n        runs[p].swap(res);\n\
    \    }\n    return runs;\n}\n#line 4 \"test/yosupo/runenumerate.test.cpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string S;\n    cin >> S;\n    auto runs = enumerate_runs(S);\n\
    \    vector<tuple<int, int, int>> ans;\n    set<pair<int, int>> used;\n    for\
    \ (int p = 1; p <= S.size(); ++p) {\n        for (auto [l, r] : runs[p]) {\n \
    \           if (!used.count({l, r})) {\n                used.insert({l, r});\n\
    \                ans.push_back({p, l, r});\n            }\n        }\n    }\n\
    \    sort(ans.begin(), ans.end());\n    cout << ans.size() << endl;\n    for (auto\
    \ [t, l, r] : ans) {\n        cout << t << \" \" << l << \" \" << r << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n\n#include\
    \ \"../../string/enumerate_runs.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string S;\n    cin >> S;\n    auto runs = enumerate_runs(S);\n    vector<tuple<int,\
    \ int, int>> ans;\n    set<pair<int, int>> used;\n    for (int p = 1; p <= S.size();\
    \ ++p) {\n        for (auto [l, r] : runs[p]) {\n            if (!used.count({l,\
    \ r})) {\n                used.insert({l, r});\n                ans.push_back({p,\
    \ l, r});\n            }\n        }\n    }\n    sort(ans.begin(), ans.end());\n\
    \    cout << ans.size() << endl;\n    for (auto [t, l, r] : ans) {\n        cout\
    \ << t << \" \" << l << \" \" << r << \"\\n\";\n    }\n}"
  dependsOn:
  - string/enumerate_runs.hpp
  - string/z_array.hpp
  isVerificationFile: true
  path: test/yosupo/runenumerate.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/runenumerate.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/runenumerate.test.cpp
- /verify/test/yosupo/runenumerate.test.cpp.html
title: test/yosupo/runenumerate.test.cpp
---
