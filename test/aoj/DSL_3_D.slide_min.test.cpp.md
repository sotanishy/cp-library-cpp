---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/slide_min.cpp
    title: Sliding Window Minimum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.slide_min.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\n\n#line 1\
    \ \"data-structure/slide_min.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Sliding Window Minimum\n * @docs docs/data-structure/slide_min.md\n */\ntemplate\
    \ <typename T, typename Compare = std::less<>>\nclass SlideMin {\npublic:\n  \
    \  void push(T x) {\n        while (!dq.empty() && !cmp(dq.back().first, x)) dq.pop_back();\n\
    \        dq.emplace_back(x, r++);\n    }\n\n    void pop() {\n        if (dq.front().second\
    \ == l) dq.pop_front();\n        ++l;\n    }\n\n    T get() {\n        return\
    \ dq.front().first;\n    }\n\nprivate:\n    int l = 0, r = 0;\n    std::deque<std::pair<T,\
    \ int>> dq;\n    Compare cmp;\n};\n#line 4 \"test/aoj/DSL_3_D.slide_min.test.cpp\"\
    \n\n#line 6 \"test/aoj/DSL_3_D.slide_min.test.cpp\"\nusing namespace std;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ N, L;\n    cin >> N >> L;\n    vector<int> a(N);\n    for (int i = 0; i < N;\
    \ i++) cin >> a[i];\n    SlideMin<int> sm;\n    for (int i = 0; i < L; i++) sm.push(a[i]);\n\
    \    for (int i = L; i < N; i++) {\n        cout << sm.get() << \" \";\n     \
    \   sm.pop();\n        sm.push(a[i]);\n    }\n    cout << sm.get() << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include \"../../data-structure/slide_min.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, L;\n    cin >> N >> L;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    SlideMin<int> sm;\n    for\
    \ (int i = 0; i < L; i++) sm.push(a[i]);\n    for (int i = L; i < N; i++) {\n\
    \        cout << sm.get() << \" \";\n        sm.pop();\n        sm.push(a[i]);\n\
    \    }\n    cout << sm.get() << endl;\n}"
  dependsOn:
  - data-structure/slide_min.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.slide_min.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:56:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.slide_min.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.slide_min.test.cpp
- /verify/test/aoj/DSL_3_D.slide_min.test.cpp.html
title: test/aoj/DSL_3_D.slide_min.test.cpp
---
