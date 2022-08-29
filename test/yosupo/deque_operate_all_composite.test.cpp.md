---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/deque_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\n\n\
    // #include \"../../data-structure/sliding_window_aggregation.cpp\"\n// #include\
    \ \"../../math/modint.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod\
    \ > 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
    \ noexcept { return mod; }\n\n    constexpr Modint(long long y = 0) noexcept :\
    \ x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr int value()\
    \ const noexcept { return x; }\n\n    constexpr mint& operator+=(const mint& r)\
    \ noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept { x\
    \ = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr mint&\
    \ operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\n \
    \   constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
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
    \    }\n\nprivate:\n    int x;\n};\n\nusing mint = Modint<998244353>;\n\nstruct\
    \ M {\n    using T = pair<mint, mint>;\n    static T op(T a, T b) {\n        return\
    \ {a.first * b.first, a.second * b.first + b.second};\n    }\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int Q;\n  \
    \  cin >> Q;\n    FoldableDeque<M> que;\n    for (int i = 0; i < Q; i++) {\n \
    \       int t;\n        cin >> t;\n        if (t == 0) {\n            int a, b;\n\
    \            cin >> a >> b;\n            que.push_front({a, b});\n        } else\
    \ if (t == 1) {\n            int a, b;\n            cin >> a >> b;\n         \
    \   que.push_back({a, b});\n        } else if (t == 2) {\n            que.pop_front();\n\
    \        } else if (t == 3) {\n            que.pop_back();\n        } else {\n\
    \            int x;\n            cin >> x;\n            pair<mint, mint> p = que.empty()\
    \ ? make_pair(1, 0) : que.fold();\n            cout << p.first * x + p.second\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n// #include \"../../data-structure/sliding_window_aggregation.cpp\"\n// #include\
    \ \"../../math/modint.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod\
    \ > 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
    \ noexcept { return mod; }\n\n    constexpr Modint(long long y = 0) noexcept :\
    \ x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr int value()\
    \ const noexcept { return x; }\n\n    constexpr mint& operator+=(const mint& r)\
    \ noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept { x\
    \ = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr mint&\
    \ operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\n \
    \   constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
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
    \    }\n\nprivate:\n    int x;\n};\n\nusing mint = Modint<998244353>;\n\nstruct\
    \ M {\n    using T = pair<mint, mint>;\n    static T op(T a, T b) {\n        return\
    \ {a.first * b.first, a.second * b.first + b.second};\n    }\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int Q;\n  \
    \  cin >> Q;\n    FoldableDeque<M> que;\n    for (int i = 0; i < Q; i++) {\n \
    \       int t;\n        cin >> t;\n        if (t == 0) {\n            int a, b;\n\
    \            cin >> a >> b;\n            que.push_front({a, b});\n        } else\
    \ if (t == 1) {\n            int a, b;\n            cin >> a >> b;\n         \
    \   que.push_back({a, b});\n        } else if (t == 2) {\n            que.pop_front();\n\
    \        } else if (t == 3) {\n            que.pop_back();\n        } else {\n\
    \            int x;\n            cin >> x;\n            pair<mint, mint> p = que.empty()\
    \ ? make_pair(1, 0) : que.fold();\n            cout << p.first * x + p.second\
    \ << \"\\n\";\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2022-08-29 11:20:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/deque_operate_all_composite.test.cpp
- /verify/test/yosupo/deque_operate_all_composite.test.cpp.html
title: test/yosupo/deque_operate_all_composite.test.cpp
---
