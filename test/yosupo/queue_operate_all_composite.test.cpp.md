---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sliding_window_aggregation.cpp
    title: Sliding Window Aggregation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/queue_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n\n\
    #line 1 \"data-structure/sliding_window_aggregation.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/*\n * @brief Sliding Window Aggregation\n * @docs docs/data-structure/sliding_window_aggregation.md\n\
    \ */\ntemplate <typename M>\nclass SlidingWindowAggregation {\n    using T = typename\
    \ M::T;\n\npublic:\n    void push(T x) {\n        if (back.empty()) back.emplace(x,\
    \ x);\n        else back.emplace(x, M::op(back.top().second, x));\n    }\n\n \
    \   void pop() {\n        if (front.empty()) {\n            if (back.empty())\
    \ return;\n            T x = back.top().first;\n            back.pop();\n    \
    \        front.emplace(x, x);\n            while (!back.empty()) {\n         \
    \       x = back.top().first;\n                back.pop();\n                front.emplace(x,\
    \ M::op(x, front.top().second));\n            }\n        }\n        front.pop();\n\
    \    }\n\n    T fold() const {\n        T ret = M::id;\n        if (!front.empty())\
    \ ret = M::op(ret, front.top().second);\n        if (!back.empty()) ret = M::op(ret,\
    \ back.top().second);\n        return ret;\n    }\n\nprivate:\n    stack<pair<T,\
    \ T>> front, back;\n};\n#line 4 \"test/yosupo/queue_operate_all_composite.test.cpp\"\
    \n\nusing ll = long long;\n\nconst ll mod = 998244353;\n\nstruct M {\n    using\
    \ T = pair<ll, ll>;\n    inline static const T id = {1, 0};\n    static T op(T\
    \ a, T b) {\n        return {a.first * b.first % mod, (a.second * b.first + b.second)\
    \ % mod};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int Q;\n    cin >> Q;\n    SlidingWindowAggregation<M>\
    \ que;\n    for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int a, b;\n            cin >> a >> b;\n  \
    \          que.push({a, b});\n        } else if (t == 1) {\n            que.pop();\n\
    \        } else {\n            int x;\n            cin >> x;\n            auto\
    \ p = que.fold();\n            cout << (p.first * x + p.second) % mod << \"\\\
    n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../data-structure/sliding_window_aggregation.cpp\"\n\nusing\
    \ ll = long long;\n\nconst ll mod = 998244353;\n\nstruct M {\n    using T = pair<ll,\
    \ ll>;\n    inline static const T id = {1, 0};\n    static T op(T a, T b) {\n\
    \        return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};\n\
    \    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int Q;\n    cin >> Q;\n    SlidingWindowAggregation<M> que;\n    for (int\
    \ i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            int a, b;\n            cin >> a >> b;\n            que.push({a,\
    \ b});\n        } else if (t == 1) {\n            que.pop();\n        } else {\n\
    \            int x;\n            cin >> x;\n            auto p = que.fold();\n\
    \            cout << (p.first * x + p.second) % mod << \"\\n\";\n        }\n \
    \   }\n}"
  dependsOn:
  - data-structure/sliding_window_aggregation.cpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 01:15:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---
