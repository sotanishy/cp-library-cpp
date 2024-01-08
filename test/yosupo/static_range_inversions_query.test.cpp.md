---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: Coordinate Compression
  - icon: ':heavy_check_mark:'
    path: misc/mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #include <bits/stdc++.h>\n\n#line 4 \"data-structure/fenwick_tree.hpp\"\n\ntemplate\
    \ <typename M>\nclass FenwickTree {\n    using T = M::T;\n\n   public:\n    FenwickTree()\
    \ = default;\n    explicit FenwickTree(int n) : n(n), data(n + 1, M::id()) {}\n\
    \n    T prefix_fold(int i) const {\n        T ret = M::id();\n        for (; i\
    \ > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return ret;\n    }\n\n\
    \    void update(int i, const T& x) {\n        for (++i; i <= n; i += i & -i)\
    \ data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const T& x) const\
    \ { return lower_bound(x, std::less<>()); }\n\n    template <typename Compare>\n\
    \    int lower_bound(const T& x, Compare cmp) const {\n        if (!cmp(M::id(),\
    \ x)) return 0;\n        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n   \
    \     int i = 0;\n        T v = M::id();\n        for (; k > 0; k >>= 1) {\n \
    \           if (i + k > n) continue;\n            T nv = M::op(v, data[i + k]);\n\
    \            if (cmp(nv, x)) {\n                v = nv;\n                i +=\
    \ k;\n            }\n        }\n        return i + 1;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> data;\n};\n#line 4 \"misc/compress.hpp\"\n\n/**\n\
    \ * @brief Coordinate Compression\n */\ntemplate <typename T>\nclass Compress\
    \ {\n   public:\n    Compress() = default;\n    explicit Compress(const std::vector<T>&\
    \ vs) : xs(vs) {\n        std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n    }\n\n    int compress(const T& x) const {\n        return std::ranges::lower_bound(xs,\
    \ x) - xs.begin();\n    }\n\n    std::vector<int> compress(const std::vector<T>&\
    \ vs) const {\n        std::vector<int> res(vs.size());\n        std::ranges::transform(vs,\
    \ res.begin(),\n                               [&](const T& x) { return compress(x);\
    \ });\n        return res;\n    }\n\n    T decompress(int i) const { return xs[i];\
    \ }\n\n    int size() const { return xs.size(); }\n\n   private:\n    std::vector<T>\
    \ xs;\n};\n#line 5 \"misc/mo.hpp\"\n\nclass Mo {\n   public:\n    Mo() = default;\n\
    \    explicit Mo(int n) : n(n), cnt(0) {}\n\n    void query(int l, int r) { queries.emplace_back(cnt++,\
    \ l, r); }\n\n    template <typename ExL, typename ShL, typename ExR, typename\
    \ ShR,\n              typename Out>\n    void run(ExL exl, ShL shl, ExR exr, ShR\
    \ shr, Out out) {\n        int s = sqrt(n);\n        std::ranges::sort(\n    \
    \        queries, {}, [&](auto& q) { return std::make_pair(q.l / s, q.r); });\n\
    \        int curL = 0, curR = 0;\n        for (auto [id, l, r] : queries) {\n\
    \            while (curL > l) exl(--curL);\n            while (curR < r) exr(curR++);\n\
    \            while (curL < l) shl(curL++);\n            while (curR > r) shr(--curR);\n\
    \            out(id);\n        }\n    }\n\n   private:\n    struct Query {\n \
    \       int id, l, r;\n    };\n\n    int n, cnt;\n    std::vector<Query> queries;\n\
    };\n#line 8 \"test/yosupo/static_range_inversions_query.test.cpp\"\nusing namespace\
    \ std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using T = int;\n    static\
    \ T id() { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (int i = 0;\
    \ i < N; ++i) cin >> A[i];\n    A = Compress<int>(A).compress(A);\n    Mo mo(N);\n\
    \    for (int i = 0; i < Q; ++i) {\n        int l, r;\n        cin >> l >> r;\n\
    \        mo.query(l, r);\n    }\n\n    FenwickTree<AddMonoid> fw(N);\n    ll res\
    \ = 0;\n    vector<ll> ans(Q);\n    auto exl = [&](int i) {\n        res += fw.prefix_fold(A[i]);\n\
    \        fw.update(A[i], 1);\n    };\n    auto shl = [&](int i) {\n        res\
    \ -= fw.prefix_fold(A[i]);\n        fw.update(A[i], -1);\n    };\n    auto exr\
    \ = [&](int i) {\n        res += fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);\n\
    \        fw.update(A[i], 1);\n    };\n    auto shr = [&](int i) {\n        res\
    \ -= fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);\n        fw.update(A[i], -1);\n\
    \    };\n    auto out = [&](int i) { ans[i] = res; };\n    mo.run(exl, shl, exr,\
    \ shr, out);\n    for (auto& x : ans) cout << x << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/fenwick_tree.hpp\"\
    \n#include \"../../misc/compress.hpp\"\n#include \"../../misc/mo.hpp\"\nusing\
    \ namespace std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using T = int;\n\
    \    static T id() { return 0; }\n    static T op(T a, T b) { return a + b; }\n\
    };\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (int i = 0;\
    \ i < N; ++i) cin >> A[i];\n    A = Compress<int>(A).compress(A);\n    Mo mo(N);\n\
    \    for (int i = 0; i < Q; ++i) {\n        int l, r;\n        cin >> l >> r;\n\
    \        mo.query(l, r);\n    }\n\n    FenwickTree<AddMonoid> fw(N);\n    ll res\
    \ = 0;\n    vector<ll> ans(Q);\n    auto exl = [&](int i) {\n        res += fw.prefix_fold(A[i]);\n\
    \        fw.update(A[i], 1);\n    };\n    auto shl = [&](int i) {\n        res\
    \ -= fw.prefix_fold(A[i]);\n        fw.update(A[i], -1);\n    };\n    auto exr\
    \ = [&](int i) {\n        res += fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);\n\
    \        fw.update(A[i], 1);\n    };\n    auto shr = [&](int i) {\n        res\
    \ -= fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);\n        fw.update(A[i], -1);\n\
    \    };\n    auto out = [&](int i) { ans[i] = res; };\n    mo.run(exl, shl, exr,\
    \ shr, out);\n    for (auto& x : ans) cout << x << \"\\n\";\n}"
  dependsOn:
  - data-structure/fenwick_tree.hpp
  - misc/compress.hpp
  - misc/mo.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 16:33:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
