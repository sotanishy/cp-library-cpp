---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sqrt_tree.cpp
    title: data-structure/sqrt_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/staticrmq.sqrt_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"data-structure/sqrt_tree.cpp\"\
    \n#include <algorithm>\n#include <vector>\n\ntemplate <typename M>\nclass SqrtTree\
    \ {\n    using T = typename M::T;\n\npublic:\n    SqrtTree() = default;\n    explicit\
    \ SqrtTree(const std::vector<T>& vs) : n(vs.size()), v(vs) {\n        int size\
    \ = 1;\n        lg = 0;\n        while (size < (int) v.size()) size <<= 1, ++lg;\n\
    \        bitlen.resize(size);\n        for (int i = 1; i < size; ++i) bitlen[i]\
    \ = bitlen[i >> 1] + 1;\n        on_layer.resize(lg + 1);\n        for (int i\
    \ = lg; i > 1; i = (i + 1) / 2) {\n            on_layer[i] = layer_lg.size();\n\
    \            layer_lg.push_back(i);\n        }\n        for (int i = lg - 1; i\
    \ >= 0; --i) on_layer[i] = std::max(on_layer[i], on_layer[i + 1]);\n        v.resize(size);\n\
    \        pref.resize(layer_lg.size(), std::vector<T>(size));\n        suf.resize(layer_lg.size(),\
    \ std::vector<T>(size));\n        btwn.resize(layer_lg.size(), std::vector<T>(size));\n\
    \        build(0, 0, n);\n    }\n\n    T fold(int l, int r) const {\n        --r;\n\
    \        if (l == r) return v[l];\n        if (l + 1 == r) return M::op(v[l],\
    \ v[r]);\n        int layer = on_layer[bitlen[l ^ r]];\n        int b_sz = 1 <<\
    \ ((layer_lg[layer] + 1) / 2);\n        int b_cnt = 1 << (layer_lg[layer] / 2);\n\
    \        int a = (l >> layer_lg[layer]) << layer_lg[layer];\n        int lblock\
    \ = (l - a) / b_sz + 1;\n        int rblock = (r - a) / b_sz - 1;\n        T val\
    \ = suf[layer][l];\n        if (lblock <= rblock) {\n            val = M::op(val,\
    \ btwn[layer][a + lblock * b_cnt + rblock]);\n        }\n        val = M::op(val,\
    \ pref[layer][r]);\n        return val;\n    }\n\nprivate:\n    int n, lg;\n \
    \   std::vector<int> bitlen, layer_lg, on_layer;\n    std::vector<T> v;\n    std::vector<std::vector<T>>\
    \ pref, suf, btwn;\n\n    void build(int layer, int l, int r) {\n        if (layer\
    \ >= (int) layer_lg.size()) return;\n        int b_sz = 1 << ((layer_lg[layer]\
    \ + 1) / 2);\n        for (int a = l; a < r; a += b_sz) {\n            int b =\
    \ std::min(a + b_sz, r);\n            // build a block\n            pref[layer][a]\
    \ = v[a];\n            for (int i = a + 1; i < b; ++i) {\n                pref[layer][i]\
    \ = M::op(pref[layer][i - 1], v[i]);\n            }\n            suf[layer][b\
    \ - 1] = v[b - 1];\n            for (int i = b - 2; i >= a; --i) {\n         \
    \       suf[layer][i] = M::op(v[i], suf[layer][i + 1]);\n            }\n     \
    \       build(layer + 1, a, b);\n        }\n        // build btwn\n        int\
    \ b_cnt = 1 << (layer_lg[layer] / 2);\n        for (int i = 0; i < b_cnt; ++i)\
    \ {\n            T val = M::id;\n            for (int j = i; j < b_cnt; ++j) {\n\
    \                val = M::op(val, suf[layer][l + j * b_sz]);\n               \
    \ btwn[layer][l + i * b_cnt + j] = val;\n            }\n        }\n    }\n};\n\
    #line 4 \"test/yosupo/staticrmq.sqrt_tree.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct MinMonoid {\n    using T = int;\n    static constexpr\
    \ T id = 1e9;\n    static T op(T a, T b) {\n        return min(a, b);\n    }\n\
    };\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> a[i];\n    SqrtTree<MinMonoid> st(a);\n    for (int i = 0;\
    \ i < Q; i++) {\n        int l, r;\n        cin >> l >> r;\n        cout << st.fold(l,\
    \ r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../data-structure/sqrt_tree.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct MinMonoid {\n    using T = int;\n    static constexpr T id =\
    \ 1e9;\n    static T op(T a, T b) {\n        return min(a, b);\n    }\n};\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0; i < N;\
    \ i++) cin >> a[i];\n    SqrtTree<MinMonoid> st(a);\n    for (int i = 0; i < Q;\
    \ i++) {\n        int l, r;\n        cin >> l >> r;\n        cout << st.fold(l,\
    \ r) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/sqrt_tree.cpp
  isVerificationFile: true
  path: test/yosupo/staticrmq.sqrt_tree.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 21:06:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/staticrmq.sqrt_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/staticrmq.sqrt_tree.test.cpp
- /verify/test/yosupo/staticrmq.sqrt_tree.test.cpp.html
title: test/yosupo/staticrmq.sqrt_tree.test.cpp
---
