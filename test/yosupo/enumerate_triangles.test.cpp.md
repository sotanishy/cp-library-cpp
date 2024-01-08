---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/enumerate_triangles.hpp
    title: Triangle Enumeration
  - icon: ':question:'
    path: math/modint.hpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"test/yosupo/enumerate_triangles.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\n#line 2 \"math/modint.hpp\"\
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
    \ x;\n};\n#line 3 \"graph/enumerate_triangles.hpp\"\n#include <vector>\n\nstd::vector<std::tuple<int,\
    \ int, int>> enumerate_triangles(\n    const std::vector<std::vector<int>>& G)\
    \ {\n    const int n = G.size();\n    std::vector<int> deg(n);\n    std::ranges::transform(G,\
    \ deg.begin(), [&](auto& g) { return g.size(); });\n    std::vector<std::vector<int>>\
    \ G2(n);\n    std::vector<std::pair<int, int>> edges;\n    for (int i = 0; i <\
    \ n; ++i) {\n        for (int j : G[i]) {\n            if (std::make_pair(deg[i],\
    \ i) < std::make_pair(deg[j], j)) {\n                G2[i].push_back(j);\n   \
    \             edges.push_back({i, j});\n            }\n        }\n    }\n    std::vector<std::tuple<int,\
    \ int, int>> ret;\n    std::vector<bool> used(n);\n    for (auto& [a, b] : edges)\
    \ {\n        for (int c : G2[a]) used[c] = true;\n        for (int c : G2[b])\
    \ {\n            if (used[c]) {\n                ret.push_back({a, b, c});\n \
    \           }\n        }\n        for (int c : G2[a]) used[c] = false;\n    }\n\
    \    return ret;\n}\n#line 5 \"test/yosupo/enumerate_triangles.test.cpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)\n#define revrep(i, t,\
    \ s) for (int i = (int)(t)-1; i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\n\
    template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1)\
    \ : 0; }\ntemplate <typename T> bool chmin(T& a, const T& b) { return a > b ?\
    \ (a = b, 1) : 0; }\n\nusing mint = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<mint>\
    \ x(N);\n    for (auto& v : x) cin >> v;\n    vector<vector<int>> G(N);\n    rep(i,0,M)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        G[u].push_back(v);\n \
    \       G[v].push_back(u);\n    }\n    mint ans = 0;\n    for (auto [a, b, c]\
    \ : enumerate_triangles(G)) {\n        ans += x[a]*x[b]*x[c];\n    }\n    cout\
    \ << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    \n#include \"../../math/modint.hpp\"\n#include \"../../graph/enumerate_triangles.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)\n#define revrep(i, t,\
    \ s) for (int i = (int)(t)-1; i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\n\
    template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1)\
    \ : 0; }\ntemplate <typename T> bool chmin(T& a, const T& b) { return a > b ?\
    \ (a = b, 1) : 0; }\n\nusing mint = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<mint>\
    \ x(N);\n    for (auto& v : x) cin >> v;\n    vector<vector<int>> G(N);\n    rep(i,0,M)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        G[u].push_back(v);\n \
    \       G[v].push_back(u);\n    }\n    mint ans = 0;\n    for (auto [a, b, c]\
    \ : enumerate_triangles(G)) {\n        ans += x[a]*x[b]*x[c];\n    }\n    cout\
    \ << ans << endl;\n}\n"
  dependsOn:
  - math/modint.hpp
  - graph/enumerate_triangles.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_triangles.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/enumerate_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_triangles.test.cpp
- /verify/test/yosupo/enumerate_triangles.test.cpp.html
title: test/yosupo/enumerate_triangles.test.cpp
---
