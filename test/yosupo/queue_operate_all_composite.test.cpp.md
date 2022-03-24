---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sliding_window_aggregation.cpp
    title: Sliding Window Aggregation
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/queue_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n\n\
    #line 2 \"data-structure/sliding_window_aggregation.cpp\"\n#include <cassert>\n\
    #include <stack>\n#include <utility>\n\ntemplate <typename S>\nclass SlidingWindowAggregation\
    \ {\n    using T = typename S::T;\n\npublic:\n    void push(const T& x) {\n  \
    \      if (back.empty()) back.emplace(x, x);\n        else back.emplace(x, S::op(back.top().second,\
    \ x));\n    }\n\n    void pop() {\n        if (front.empty()) {\n            if\
    \ (back.empty()) return;\n            T x = back.top().first;\n            back.pop();\n\
    \            front.emplace(x, x);\n            while (!back.empty()) {\n     \
    \           x = back.top().first;\n                back.pop();\n             \
    \   front.emplace(x, S::op(x, front.top().second));\n            }\n        }\n\
    \        front.pop();\n    }\n\n    bool empty() const {\n        return front.empty()\
    \ && back.empty();\n    }\n\n    T fold() const {\n        assert(!empty());\n\
    \        if (front.empty()) return back.top().second;\n        if (back.empty())\
    \ return front.top().second;\n        return S::op(front.top().second, back.top().second);\n\
    \    }\n\nprivate:\n    std::stack<std::pair<T, T>> front, back;\n};\n#line 2\
    \ \"math/modint.cpp\"\n#include <iostream>\n#include <algorithm>\n\n/*\n * @brief\
    \ Mod int\n */\ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n\
    \    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n    static\
    \ constexpr int get_mod() noexcept { return mod; }\n\n    constexpr Modint(long\
    \ long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n  \
    \  constexpr int value() const noexcept { return x; }\n\n    constexpr mint& operator+=(const\
    \ mint& r) noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr\
    \ mint& operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -=\
    \ mod; return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept\
    \ { x = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr\
    \ mint& operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\
    \n    constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
    \ mint operator+(const mint& r) const noexcept { return mint(*this) += r; }\n\
    \    constexpr mint operator-(const mint& r) const noexcept { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    constexpr mint operator/(const mint& r) const noexcept\
    \ { return mint(*this) /= r; }\n\n    constexpr bool operator==(const mint& r)\
    \ const noexcept { return x == r.x; }\n    constexpr bool operator!=(const mint&\
    \ r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const noexcept\
    \ {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n    \
    \        int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\nprivate:\n    int x;\n};\n#line 5 \"test/yosupo/queue_operate_all_composite.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct M {\n    using T = pair<mint, mint>;\n    static T op(T a, T b) {\n \
    \       return {a.first * b.first, a.second * b.first + b.second};\n    }\n};\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int Q;\n    cin >> Q;\n    SlidingWindowAggregation<M> que;\n    for (int i\
    \ = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int a, b;\n            cin >> a >> b;\n            que.push({a, b});\n\
    \        } else if (t == 1) {\n            que.pop();\n        } else {\n    \
    \        int x;\n            cin >> x;\n            pair<mint, mint> p = que.empty()\
    \ ? make_pair(1, 0) : que.fold();\n            cout << p.first * x + p.second\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../data-structure/sliding_window_aggregation.cpp\"\n#include\
    \ \"../../math/modint.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing mint = Modint<998244353>;\n\nstruct M {\n    using T = pair<mint, mint>;\n\
    \    static T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first\
    \ + b.second};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int Q;\n    cin >> Q;\n    SlidingWindowAggregation<M>\
    \ que;\n    for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int a, b;\n            cin >> a >> b;\n  \
    \          que.push({a, b});\n        } else if (t == 1) {\n            que.pop();\n\
    \        } else {\n            int x;\n            cin >> x;\n            pair<mint,\
    \ mint> p = que.empty() ? make_pair(1, 0) : que.fold();\n            cout << p.first\
    \ * x + p.second << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/sliding_window_aggregation.cpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2021-10-18 17:48:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---
