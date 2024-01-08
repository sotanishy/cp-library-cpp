---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: tree/rerooting.hpp
    title: Rerooting
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/yosupo/tree_path_composite_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief Mod int\n */\n\
    template <int m>\nclass Modint {\n    using mint = Modint;\n    static_assert(m\
    \ > 0, \"Modulus must be positive\");\n\n   public:\n    static constexpr int\
    \ mod() { return m; }\n\n    constexpr Modint(long long y = 0) : x(y >= 0 ? y\
    \ % m : (y % m + m) % m) {}\n\n    constexpr int val() const { return x; }\n\n\
    \    constexpr mint& operator+=(const mint& r) {\n        if ((x += r.x) >= m)\
    \ x -= m;\n        return *this;\n    }\n    constexpr mint& operator-=(const\
    \ mint& r) {\n        if ((x += m - r.x) >= m) x -= m;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL\
    \ * x * r.x % m);\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& r) { return *this *= r.inv(); }\n\n    constexpr bool operator==(const\
    \ mint& r) const { return x == r.x; }\n\n    constexpr mint operator+() const\
    \ { return *this; }\n    constexpr mint operator-() const { return mint(-x); }\n\
    \n    constexpr friend mint operator+(const mint& l, const mint& r) {\n      \
    \  return mint(l) += r;\n    }\n    constexpr friend mint operator-(const mint&\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const mint& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n    constexpr friend mint operator/(const mint& l, const mint& r) {\n\
    \        return mint(l) /= r;\n    }\n\n    constexpr mint inv() const {\n   \
    \     int a = x, b = m, u = 1, v = 0;\n        while (b > 0) {\n            int\
    \ t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u -=\
    \ t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const {\n        mint ret(1), mul(x);\n        while (n > 0)\
    \ {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\n   private:\n    int x;\n};\n#line 4 \"tree/rerooting.hpp\"\n\ntemplate\
    \ <typename M, typename Cost,\n          typename M::T (*apply_edge)(typename\
    \ M::T, int, int, Cost),\n          typename M::T (*apply_vertex)(typename M::T,\
    \ int)>\nclass Rerooting {\n    using T = M::T;\n\n   public:\n    explicit Rerooting(int\
    \ n) : G(n) {}\n\n    void add_edge(int u, int v, Cost c) {\n        G[u].emplace_back(v,\
    \ c);\n        G[v].emplace_back(u, c);\n    }\n\n    std::vector<T> run() {\n\
    \        dp_sub.resize(G.size(), M::id());\n        dp_all.resize(G.size());\n\
    \        dfs_sub(0, -1);\n        dfs_all(0, -1, M::id());\n        return dp_all;\n\
    \    }\n\n   private:\n    std::vector<std::vector<std::pair<int, Cost>>> G;\n\
    \    std::vector<T> dp_sub, dp_all;\n\n    void dfs_sub(int v, int p) {\n    \
    \    for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n      \
    \      dfs_sub(c, v);\n            dp_sub[v] = M::op(dp_sub[v], apply_edge(dp_sub[c],\
    \ v, c, cost));\n        }\n        dp_sub[v] = apply_vertex(dp_sub[v], v);\n\
    \    }\n\n    void dfs_all(int v, int p, const T& val) {\n        std::vector<T>\
    \ ds = {val};\n        for (auto [c, cost] : G[v]) {\n            if (c == p)\
    \ continue;\n            ds.push_back(apply_edge(dp_sub[c], v, c, cost));\n  \
    \      }\n        int n = ds.size();\n        std::vector<T> head(n + 1, M::id()),\
    \ tail(n + 1, M::id());\n        for (int i = 0; i < n; ++i) head[i + 1] = M::op(head[i],\
    \ ds[i]);\n        for (int i = n - 1; i >= 0; --i) tail[i] = M::op(ds[i], tail[i\
    \ + 1]);\n        dp_all[v] = apply_vertex(head[n], v);\n        int k = 1;\n\
    \        for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n  \
    \          dfs_all(c, v,\n                    apply_edge(apply_vertex(M::op(head[k],\
    \ tail[k + 1]), v), c,\n                               v, cost));\n          \
    \  ++k;\n        }\n    }\n};\n#line 7 \"test/yosupo/tree_path_composite_sum.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nusing mint = Modint<998244353>;\n\
    \nstruct AddCountMonoid {\n    using T = pair<mint, int>;\n    static T id() {\
    \ return {0, 0}; }\n    static T op(T a, T b) { return {a.first + b.first, a.second\
    \ + b.second}; }\n};\n\nvector<mint> a;\n\npair<mint, int> apply_edge(pair<mint,\
    \ int> x, int, int, pair<mint, mint> e) {\n    return {e.first * x.first + e.second\
    \ * x.second, x.second};\n}\npair<mint, int> apply_vertex(pair<mint, int> x, int\
    \ v) {\n    return {x.first + a[v], x.second + 1};\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    a.resize(N);\n    for\
    \ (auto& x : a) cin >> x;\n    Rerooting<AddCountMonoid, pair<mint, mint>, apply_edge,\
    \ apply_vertex>\n        rerooting(N);\n\n    for (int i = 0; i < N - 1; ++i)\
    \ {\n        int u, v;\n        mint b, c;\n        cin >> u >> v >> b >> c;\n\
    \        rerooting.add_edge(u, v, {b, c});\n    }\n    auto ans = rerooting.run();\n\
    \    for (int i = 0; i < N; ++i) {\n        cout << ans[i].first << (i < N - 1\
    \ ? \" \" : \"\\n\");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/modint.hpp\"\n#include \"\
    ../../tree/rerooting.hpp\"\nusing namespace std;\nusing ll = long long;\n\nusing\
    \ mint = Modint<998244353>;\n\nstruct AddCountMonoid {\n    using T = pair<mint,\
    \ int>;\n    static T id() { return {0, 0}; }\n    static T op(T a, T b) { return\
    \ {a.first + b.first, a.second + b.second}; }\n};\n\nvector<mint> a;\n\npair<mint,\
    \ int> apply_edge(pair<mint, int> x, int, int, pair<mint, mint> e) {\n    return\
    \ {e.first * x.first + e.second * x.second, x.second};\n}\npair<mint, int> apply_vertex(pair<mint,\
    \ int> x, int v) {\n    return {x.first + a[v], x.second + 1};\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N;\n\
    \    cin >> N;\n    a.resize(N);\n    for (auto& x : a) cin >> x;\n    Rerooting<AddCountMonoid,\
    \ pair<mint, mint>, apply_edge, apply_vertex>\n        rerooting(N);\n\n    for\
    \ (int i = 0; i < N - 1; ++i) {\n        int u, v;\n        mint b, c;\n     \
    \   cin >> u >> v >> b >> c;\n        rerooting.add_edge(u, v, {b, c});\n    }\n\
    \    auto ans = rerooting.run();\n    for (int i = 0; i < N; ++i) {\n        cout\
    \ << ans[i].first << (i < N - 1 ? \" \" : \"\\n\");\n    }\n}\n"
  dependsOn:
  - math/modint.hpp
  - tree/rerooting.hpp
  isVerificationFile: true
  path: test/yosupo/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_path_composite_sum.test.cpp
- /verify/test/yosupo/tree_path_composite_sum.test.cpp.html
title: test/yosupo/tree_path_composite_sum.test.cpp
---
