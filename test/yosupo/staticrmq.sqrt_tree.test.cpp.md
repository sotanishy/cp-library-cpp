---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/sqrt_tree.hpp
    title: Sqrt Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/staticrmq.sqrt_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\n\n\
    #line 3 \"data-structure/sqrt_tree.hpp\"\n#include <bit>\n#line 5 \"data-structure/sqrt_tree.hpp\"\
    \n\ntemplate <typename S>\nclass SqrtTree {\n    using T = S::T;\n\n   public:\n\
    \    SqrtTree() = default;\n    explicit SqrtTree(const std::vector<T>& v) : v(v)\
    \ {\n        const int n = v.size(), lg = std::bit_width(n);\n        on_layer.resize(lg\
    \ + 1);\n        int n_layer = 0;\n        for (int i = lg; i > 1; i = (i + 1)\
    \ / 2) {\n            on_layer[i] = n_layer++;\n            layer_lg.push_back(i);\n\
    \        }\n        for (int i = lg - 1; i >= 0; --i)\n            on_layer[i]\
    \ = std::max(on_layer[i], on_layer[i + 1]);\n        pref.resize(n_layer, std::vector<T>(n));\n\
    \        suf.resize(n_layer, std::vector<T>(n));\n        btwn.resize(n_layer,\
    \ std::vector<T>(1 << lg));\n\n        for (int layer = 0; layer < n_layer; ++layer)\
    \ {\n            int prev_b_sz = 1 << layer_lg[layer];\n            int b_sz =\
    \ 1 << ((layer_lg[layer] + 1) / 2);\n            int b_cnt = 1 << (layer_lg[layer]\
    \ / 2);\n\n            for (int l = 0; l < n; l += prev_b_sz) {\n            \
    \    int r = std::min(l + prev_b_sz, n);\n\n                // calculate pref\
    \ and suf\n                for (int a = l; a < r; a += b_sz) {\n             \
    \       int b = std::min(a + b_sz, r);\n                    pref[layer][a] = v[a];\n\
    \                    for (int i = a + 1; i < b; ++i) {\n                     \
    \   pref[layer][i] = S::op(pref[layer][i - 1], v[i]);\n                    }\n\
    \                    suf[layer][b - 1] = v[b - 1];\n                    for (int\
    \ i = b - 2; i >= a; --i) {\n                        suf[layer][i] = S::op(v[i],\
    \ suf[layer][i + 1]);\n                    }\n                }\n            \
    \    // calculate btwn\n                for (int i = 0; i < b_cnt; ++i) {\n  \
    \                  T val = suf[layer][l + i * b_sz];\n                    btwn[layer][l\
    \ + i * b_cnt + i] = val;\n                    for (int j = i + 1; j < b_cnt;\
    \ ++j) {\n                        val = S::op(val, suf[layer][l + j * b_sz]);\n\
    \                        btwn[layer][l + i * b_cnt + j] = val;\n             \
    \       }\n                }\n            }\n        }\n    }\n\n    T fold(int\
    \ l, int r) const {\n        --r;\n        if (l == r) return v[l];\n        if\
    \ (l + 1 == r) return S::op(v[l], v[r]);\n        int layer = on_layer[std::bit_width((unsigned\
    \ int)(l ^ r))];\n        int b_sz = 1 << ((layer_lg[layer] + 1) / 2);\n     \
    \   int b_cnt = 1 << (layer_lg[layer] / 2);\n        int a = (l >> layer_lg[layer])\
    \ << layer_lg[layer];\n        int lblock = (l - a) / b_sz + 1;\n        int rblock\
    \ = (r - a) / b_sz - 1;\n        T val = suf[layer][l];\n        if (lblock <=\
    \ rblock)\n            val = S::op(val, btwn[layer][a + lblock * b_cnt + rblock]);\n\
    \        val = S::op(val, pref[layer][r]);\n        return val;\n    }\n\n   private:\n\
    \    std::vector<int> layer_lg, on_layer;\n    std::vector<T> v;\n    std::vector<std::vector<T>>\
    \ pref, suf, btwn;\n};\n#line 6 \"test/yosupo/staticrmq.sqrt_tree.test.cpp\"\n\
    using namespace std;\n\nstruct MinSemigroup {\n    using T = int;\n    static\
    \ T op(T a, T b) { return min(a, b); }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (auto& x : a) cin >> x;\n    SqrtTree<MinSemigroup> st(a);\n    while\
    \ (Q--) {\n        int l, r;\n        cin >> l >> r;\n        cout << st.fold(l,\
    \ r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../data-structure/sqrt_tree.hpp\"\nusing namespace\
    \ std;\n\nstruct MinSemigroup {\n    using T = int;\n    static T op(T a, T b)\
    \ { return min(a, b); }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (auto& x : a) cin >> x;\n    SqrtTree<MinSemigroup> st(a);\n    while\
    \ (Q--) {\n        int l, r;\n        cin >> l >> r;\n        cout << st.fold(l,\
    \ r) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/sqrt_tree.hpp
  isVerificationFile: true
  path: test/yosupo/staticrmq.sqrt_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/staticrmq.sqrt_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/staticrmq.sqrt_tree.test.cpp
- /verify/test/yosupo/staticrmq.sqrt_tree.test.cpp.html
title: test/yosupo/staticrmq.sqrt_tree.test.cpp
---
