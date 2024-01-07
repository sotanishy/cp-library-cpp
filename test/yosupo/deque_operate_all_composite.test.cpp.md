---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/foldable_deque.hpp
    title: Foldable Deque
  - icon: ':question:'
    path: math/modint.hpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/deque_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\n\n\
    #line 2 \"data-structure/foldable_deque.hpp\"\n#include <cassert>\n#include <stack>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename S>\nclass FoldableDeque\
    \ {\n    using T = typename S::T;\n\npublic:\n    void push_front(const T& x)\
    \ {\n        if (front.empty()) front.emplace(x, x);\n        else front.emplace(x,\
    \ S::op(x, front.top().second));\n    }\n\n    void push_back(const T& x) {\n\
    \        if (back.empty()) back.emplace(x, x);\n        else back.emplace(x, S::op(back.top().second,\
    \ x));\n    }\n\n    void pop_front() {\n        assert(!empty());\n        if\
    \ (front.empty()) {\n            std::vector<T> xs;\n            while (!back.empty())\
    \ {\n                xs.push_back(back.top().first);\n                back.pop();\n\
    \            }\n            int n = xs.size();\n            for (int i = n / 2;\
    \ i < n; ++i) push_front(xs[i]);\n            for (int i = n / 2 - 1; i >= 0;\
    \ --i) push_back(xs[i]);\n        }\n        front.pop();\n    }\n\n    void pop_back()\
    \ {\n        assert(!empty());\n        if (back.empty()) {\n            std::vector<T>\
    \ xs;\n            while (!front.empty()) {\n                xs.push_back(front.top().first);\n\
    \                front.pop();\n            }\n            int n = xs.size();\n\
    \            for (int i = n / 2 - 1; i >= 0; --i) push_front(xs[i]);\n       \
    \     for (int i = n / 2; i < n; ++i) push_back(xs[i]);\n        }\n        back.pop();\n\
    \    }\n\n    bool empty() const {\n        return front.empty() && back.empty();\n\
    \    }\n\n    T fold() const {\n        assert(!empty());\n        if (front.empty())\
    \ return back.top().second;\n        if (back.empty()) return front.top().second;\n\
    \        return S::op(front.top().second, back.top().second);\n    }\n\nprivate:\n\
    \    std::stack<std::pair<T, T>> front, back;\n};\n\n#line 2 \"math/modint.hpp\"\
    \n#include <algorithm>\n#include <iostream>\n\n/**\n * @brief Mod int\n */\ntemplate\
    \ <int m>\nclass Modint {\n    using mint = Modint;\n    static_assert(m > 0,\
    \ \"Modulus must be positive\");\n\n   public:\n    static constexpr int mod()\
    \ { return m; }\n\n    constexpr Modint(long long y = 0) : x(y >= 0 ? y % m :\
    \ (y % m + m) % m) {}\n\n    constexpr int val() const { return x; }\n\n    constexpr\
    \ mint& operator+=(const mint& r) {\n        if ((x += r.x) >= m) x -= m;\n  \
    \      return *this;\n    }\n    constexpr mint& operator-=(const mint& r) {\n\
    \        if ((x += m - r.x) >= m) x -= m;\n        return *this;\n    }\n    constexpr\
    \ mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL * x * r.x\
    \ % m);\n        return *this;\n    }\n    constexpr mint& operator/=(const mint&\
    \ r) { return *this *= r.inv(); }\n\n    constexpr bool operator==(const mint&\
    \ r) const { return x == r.x; }\n\n    constexpr mint operator+() const { return\
    \ *this; }\n    constexpr mint operator-() const { return mint(-x); }\n\n    constexpr\
    \ friend mint operator+(const mint& l, const mint& r) {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(const mint& l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(const\
    \ mint& l, const mint& r) {\n        return mint(l) *= r;\n    }\n    constexpr\
    \ friend mint operator/(const mint& l, const mint& r) {\n        return mint(l)\
    \ /= r;\n    }\n\n    constexpr mint inv() const {\n        int a = x, b = m,\
    \ u = 1, v = 0;\n        while (b > 0) {\n            int t = a / b;\n       \
    \     std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n     \
    \   }\n        return mint(u);\n    }\n\n    constexpr mint pow(long long n) const\
    \ {\n        mint ret(1), mul(x);\n        while (n > 0) {\n            if (n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& r) {\n        return os << r.x;\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& r) {\n        long long t;\n        is >>\
    \ t;\n        r = mint(t);\n        return is;\n    }\n\n   private:\n    int\
    \ x;\n};\n#line 5 \"test/yosupo/deque_operate_all_composite.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\n\
    struct M {\n    using T = pair<mint, mint>;\n    static T op(T a, T b) {\n   \
    \     return {a.first * b.first, a.second * b.first + b.second};\n    }\n};\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ Q;\n    cin >> Q;\n    FoldableDeque<M> que;\n    for (int i = 0; i < Q; i++)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            int\
    \ a, b;\n            cin >> a >> b;\n            que.push_front({a, b});\n   \
    \     } else if (t == 1) {\n            int a, b;\n            cin >> a >> b;\n\
    \            que.push_back({a, b});\n        } else if (t == 2) {\n          \
    \  que.pop_front();\n        } else if (t == 3) {\n            que.pop_back();\n\
    \        } else {\n            int x;\n            cin >> x;\n            pair<mint,\
    \ mint> p = que.empty() ? make_pair(1, 0) : que.fold();\n            cout << p.first\
    \ * x + p.second << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include \"../../data-structure/foldable_deque.hpp\"\n#include \"../../math/modint.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct M {\n    using T = pair<mint, mint>;\n    static T op(T a, T b) {\n \
    \       return {a.first * b.first, a.second * b.first + b.second};\n    }\n};\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int Q;\n    cin >> Q;\n    FoldableDeque<M> que;\n    for (int i = 0; i < Q;\
    \ i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n         \
    \   int a, b;\n            cin >> a >> b;\n            que.push_front({a, b});\n\
    \        } else if (t == 1) {\n            int a, b;\n            cin >> a >>\
    \ b;\n            que.push_back({a, b});\n        } else if (t == 2) {\n     \
    \       que.pop_front();\n        } else if (t == 3) {\n            que.pop_back();\n\
    \        } else {\n            int x;\n            cin >> x;\n            pair<mint,\
    \ mint> p = que.empty() ? make_pair(1, 0) : que.fold();\n            cout << p.first\
    \ * x + p.second << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/foldable_deque.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/deque_operate_all_composite.test.cpp
- /verify/test/yosupo/deque_operate_all_composite.test.cpp.html
title: test/yosupo/deque_operate_all_composite.test.cpp
---
