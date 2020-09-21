---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/range_fenwick_tree.cpp
    title: Fenwick Tree with Range Update
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL_2_G.range_fenwick_tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#line 1 \"data-structure/range_fenwick_tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/*\n * @brief Fenwick Tree with Range Update\n * @docs\
    \ docs/data-structure/range_fenwick_tree.md\n */\ntemplate <typename T>\nclass\
    \ RangeFenwickTree {\npublic:\n    explicit RangeFenwickTree(int n) : n(n), data0(n\
    \ + 1), data1(n + 1) {}\n\n    T sum(int i) const {\n        return sum(data0,\
    \ i) * (i - 1) + sum(data1, i);\n    }\n\n    void add(int l, int r, T x) {\n\
    \        add(data0, l, x);\n        add(data0, r + 1, -x);\n        add(data1,\
    \ l, -x * (l - 1));\n        add(data1, r + 1, x * r);\n    }\n\nprivate:\n  \
    \  int n;\n    std::vector<T> data0, data1;\n\n    T sum(const std::vector<T>&\
    \ data, int i) const {\n        T ret = 0;\n        for (; i > 0; i -= i & -i)\
    \ ret += data[i];\n        return ret;\n    }\n\n    void add(std::vector<T>&\
    \ data, int i, T x) {\n        for (i++; i <= n; i += i & -i) data[i] += x;\n\
    \    }\n};\n#line 4 \"test/aoj/DSL_2_G.range_fenwick_tree.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n, q;\n    cin >> n >> q;\n    RangeFenwickTree<long long> ft(n+1);\n\
    \    for (int i = 0; i < q; i++) {\n        int type;\n        cin >> type;\n\
    \        if (type == 0) {\n            int s, t, x;\n            cin >> s >> t\
    \ >> x;\n            ft.add(s - 1, t - 1, x);\n        } else {\n            int\
    \ s, t;\n            cin >> s >> t;\n            cout << ft.sum(t) - ft.sum(s\
    \ - 1) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include \"../../data-structure/range_fenwick_tree.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n, q;\n    cin >> n >> q;\n    RangeFenwickTree<long long> ft(n+1);\n\
    \    for (int i = 0; i < q; i++) {\n        int type;\n        cin >> type;\n\
    \        if (type == 0) {\n            int s, t, x;\n            cin >> s >> t\
    \ >> x;\n            ft.add(s - 1, t - 1, x);\n        } else {\n            int\
    \ s, t;\n            cin >> s >> t;\n            cout << ft.sum(t) - ft.sum(s\
    \ - 1) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/range_fenwick_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
- /verify/test/aoj/DSL_2_G.range_fenwick_tree.test.cpp.html
title: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
---
