---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick_tree.cpp
    title: Fenwick Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"test/yosupo/number_of_subsequences.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n\n#line 2 \"math/modint.cpp\"\
    \n#include <iostream>\n#include <algorithm>\n\n/**\n * @brief Mod int\n */\ntemplate\
    \ <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod >\
    \ 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
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
    \    }\n\nprivate:\n    int x;\n};\n#line 2 \"data-structure/fenwick_tree.cpp\"\
    \n#include <functional>\n#include <vector>\n\ntemplate <typename M>\nclass FenwickTree\
    \ {\n    using T = typename M::T;\n\n   public:\n    FenwickTree() = default;\n\
    \    explicit FenwickTree(int n) : n(n), data(n + 1, M::id()) {}\n\n    T prefix_fold(int\
    \ i) const {\n        T ret = M::id();\n        for (; i > 0; i -= i & -i) ret\
    \ = M::op(ret, data[i]);\n        return ret;\n    }\n\n    void update(int i,\
    \ const T& x) {\n        for (++i; i <= n; i += i & -i) data[i] = M::op(data[i],\
    \ x);\n    }\n\n    int lower_bound(const T& x) const { return lower_bound(x,\
    \ std::less<>()); }\n\n    template <typename Compare>\n    int lower_bound(const\
    \ T& x, Compare cmp) const {\n        if (!cmp(M::id(), x)) return 0;\n      \
    \  int k = 1;\n        while (k * 2 <= n) k <<= 1;\n        int i = 0;\n     \
    \   T v = M::id();\n        for (; k > 0; k >>= 1) {\n            if (i + k >\
    \ n) continue;\n            T nv = M::op(v, data[i + k]);\n            if (cmp(nv,\
    \ x)) {\n                v = nv;\n                i += k;\n            }\n   \
    \     }\n        return i + 1;\n    }\n\n   private:\n    int n;\n    std::vector<T>\
    \ data;\n};\n#line 5 \"test/yosupo/number_of_subsequences.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\n\
    struct AddMonoid {\n    using T = mint;\n    static T id() { return 0; }\n   \
    \ static T op(T a, T b) {\n        return a + b;\n    }\n};\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int N;\n    cin\
    \ >> N;\n    vector<int> A(N);\n    for (auto& x : A) cin >> x;\n    map<int,\
    \ int> last;\n    FenwickTree<AddMonoid> ft(N+1);\n    ft.update(0, 1);\n    for\
    \ (int i = 0; i < N; ++i) {\n        int l = last[A[i]];\n        ft.update(i+1,\
    \ ft.prefix_fold(i+1) - ft.prefix_fold(l));\n        last[A[i]] = i + 1;\n   \
    \ }\n    cout << ft.prefix_fold(N + 1) - 1 << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n\n#include \"../../math/modint.cpp\"\n#include \"../../data-structure/fenwick_tree.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct AddMonoid {\n    using T = mint;\n    static T id() { return 0; }\n \
    \   static T op(T a, T b) {\n        return a + b;\n    }\n};\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int N;\n    cin\
    \ >> N;\n    vector<int> A(N);\n    for (auto& x : A) cin >> x;\n    map<int,\
    \ int> last;\n    FenwickTree<AddMonoid> ft(N+1);\n    ft.update(0, 1);\n    for\
    \ (int i = 0; i < N; ++i) {\n        int l = last[A[i]];\n        ft.update(i+1,\
    \ ft.prefix_fold(i+1) - ft.prefix_fold(l));\n        last[A[i]] = i + 1;\n   \
    \ }\n    cout << ft.prefix_fold(N + 1) - 1 << endl;\n}"
  dependsOn:
  - math/modint.cpp
  - data-structure/fenwick_tree.cpp
  isVerificationFile: true
  path: test/yosupo/number_of_subsequences.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 14:56:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number_of_subsequences.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_of_subsequences.test.cpp
- /verify/test/yosupo/number_of_subsequences.test.cpp.html
title: test/yosupo/number_of_subsequences.test.cpp
---
