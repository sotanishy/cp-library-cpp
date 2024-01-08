---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/enumerate_cliques.hpp
    title: Clique Enumeration
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_cliques
    links:
    - https://judge.yosupo.jp/problem/enumerate_cliques
  bundledCode: "#line 1 \"test/yosupo/enumerate_cliques.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n\n#line 2 \"math/modint.hpp\"\
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
    \ x;\n};\n#line 2 \"graph/enumerate_cliques.hpp\"\n#include <cmath>\n#include\
    \ <vector>\n\nstd::vector<std::vector<int>> enumerate_cliques(\n    const std::vector<std::vector<bool>>&\
    \ G) {\n    int N = G.size(), M = 0;\n    std::vector<int> deg(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        for (int j = 0; j < N; ++j) {\n            if\
    \ (G[i][j]) {\n                ++deg[i];\n                ++M;\n            }\n\
    \        }\n    }\n    M /= 2;\n    int B = std::sqrt(2 * M);\n    std::vector<std::vector<int>>\
    \ cliques;\n\n    auto check = [&](const std::vector<int>& vs, bool use_first)\
    \ {\n        int n = vs.size();\n        for (int S = 1; S < 1 << n; ++S) {\n\
    \            if (use_first && !(S & 1)) continue;\n            bool ok = true;\n\
    \            for (int i = 0; i < n - 1; ++i) {\n                if (!(S >> i &\
    \ 1)) continue;\n                for (int j = i + 1; j < n; ++j) {\n         \
    \           if ((S >> j & 1) && !G[vs[i]][vs[j]]) {\n                        ok\
    \ = false;\n                        break;\n                    }\n          \
    \      }\n                if (!ok) break;\n            }\n            if (ok)\
    \ {\n                cliques.emplace_back();\n                for (int i = 0;\
    \ i < n; ++i) {\n                    if (S >> i & 1) {\n                     \
    \   cliques.back().push_back(vs[i]);\n                    }\n                }\n\
    \            }\n        }\n    };\n\n    std::vector<bool> checked(N);\n    std::vector<int>\
    \ big;\n    for (int i = 0; i < N; ++i) {\n        if (deg[i] >= B) {\n      \
    \      big.push_back(i);\n            continue;\n        }\n        std::vector<int>\
    \ vs;\n        vs.push_back(i);\n        for (int j = 0; j < N; ++j) {\n     \
    \       if (G[i][j] && !checked[j]) {\n                vs.push_back(j);\n    \
    \        }\n        }\n        check(vs, true);\n        checked[i] = true;\n\
    \    }\n    check(big, false);\n    return cliques;\n}\n#line 5 \"test/yosupo/enumerate_cliques.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int N, M;\n    cin >> N >> M;\n    vector<mint> x(N);\n    for (auto& y : x)\
    \ cin >> y;\n    vector<vector<bool>> G(N, vector<bool>(N));\n    for (int i =\
    \ 0; i < M; ++i) {\n        int u, v;\n        cin >> u >> v;\n        G[u][v]\
    \ = G[v][u] = true;\n    }\n    mint ans = 0;\n    for (auto& clique : enumerate_cliques(G))\
    \ {\n        mint res = 1;\n        for (int i : clique) {\n            res *=\
    \ x[i];\n        }\n        ans += res;\n    }\n    cout << ans << endl;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n\n\
    #include \"../../math/modint.hpp\"\n#include \"../../graph/enumerate_cliques.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int N, M;\n    cin >> N >> M;\n    vector<mint> x(N);\n    for (auto& y : x)\
    \ cin >> y;\n    vector<vector<bool>> G(N, vector<bool>(N));\n    for (int i =\
    \ 0; i < M; ++i) {\n        int u, v;\n        cin >> u >> v;\n        G[u][v]\
    \ = G[v][u] = true;\n    }\n    mint ans = 0;\n    for (auto& clique : enumerate_cliques(G))\
    \ {\n        mint res = 1;\n        for (int i : clique) {\n            res *=\
    \ x[i];\n        }\n        ans += res;\n    }\n    cout << ans << endl;\n}\n\n"
  dependsOn:
  - math/modint.hpp
  - graph/enumerate_cliques.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_cliques.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_cliques.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_cliques.test.cpp
- /verify/test/yosupo/enumerate_cliques.test.cpp.html
title: test/yosupo/enumerate_cliques.test.cpp
---
