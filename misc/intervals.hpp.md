---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/intervals.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <set>\n#include <utility>\n#include <vector>\n\ntemplate <typename X,\
    \ typename T>\nclass Intervals {\npublic:\n    static constexpr X INF = std::numeric_limits<T>::max()\
    \ / 2;\n\n    Intervals(T default_val) : default_val(default_val) {\n        st.emplace(INF,\
    \ INF, default_val);\n        st.emplace(-INF, -INF, default_val);\n    }\n\n\
    \    T get(X x) const {\n        auto it = --(st.lower_bound({x + 1, x, default_val}));\n\
    \        auto [l, r, v] = *it;\n        if (l <= x && x <= r) return v;\n    \
    \    return default_val;\n    }\n\n    std::vector<std::tuple<X, X, T>> get(X\
    \ l, X r) const {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
    \ + 1, l, default_val}));\n        std::vector<std::tuple<X, X, T>> ret;\n   \
    \     while (it != st.end()) {\n            auto [l_, r_, v_] = *it;\n       \
    \     if (r < l_) break;\n            l_ = std::max(l_, l);\n            r_ =\
    \ std::min(r_, r);\n            if (l_ <= r_) ret.emplace_back(l_, r_, v_);\n\
    \            ++it;\n        }\n        return ret;\n    }\n\n    void set(X l,\
    \ X r, T v) {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
    \ + 1, l, default_val}));\n        std::vector<std::tuple<X, X, T>> intervals;\n\
    \        if (v != default_val) intervals.emplace_back(l, r, v);\n        while\
    \ (it != st.end()) {\n            auto [l_, r_, v_] = *it;\n            if (r\
    \ < l_) break;\n            if (l_ < l) {\n                intervals.emplace_back(l_,\
    \ std::min(r_, l - 1), v_);\n            }\n            if (r < r_) {\n      \
    \          intervals.emplace_back(r + 1, r_, v_);\n            }\n           \
    \ it = st.erase(it);\n        }\n        for (auto [l_, r_, v_] : intervals) st.emplace(l_,\
    \ r_, v_);\n    }\n\n    void erase(X l, X r) { set(l, r, default_val); }\n\n\
    private:\n    std::set<std::tuple<X, X, T>> st;\n    T default_val;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <set>\n#include\
    \ <utility>\n#include <vector>\n\ntemplate <typename X, typename T>\nclass Intervals\
    \ {\npublic:\n    static constexpr X INF = std::numeric_limits<T>::max() / 2;\n\
    \n    Intervals(T default_val) : default_val(default_val) {\n        st.emplace(INF,\
    \ INF, default_val);\n        st.emplace(-INF, -INF, default_val);\n    }\n\n\
    \    T get(X x) const {\n        auto it = --(st.lower_bound({x + 1, x, default_val}));\n\
    \        auto [l, r, v] = *it;\n        if (l <= x && x <= r) return v;\n    \
    \    return default_val;\n    }\n\n    std::vector<std::tuple<X, X, T>> get(X\
    \ l, X r) const {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
    \ + 1, l, default_val}));\n        std::vector<std::tuple<X, X, T>> ret;\n   \
    \     while (it != st.end()) {\n            auto [l_, r_, v_] = *it;\n       \
    \     if (r < l_) break;\n            l_ = std::max(l_, l);\n            r_ =\
    \ std::min(r_, r);\n            if (l_ <= r_) ret.emplace_back(l_, r_, v_);\n\
    \            ++it;\n        }\n        return ret;\n    }\n\n    void set(X l,\
    \ X r, T v) {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
    \ + 1, l, default_val}));\n        std::vector<std::tuple<X, X, T>> intervals;\n\
    \        if (v != default_val) intervals.emplace_back(l, r, v);\n        while\
    \ (it != st.end()) {\n            auto [l_, r_, v_] = *it;\n            if (r\
    \ < l_) break;\n            if (l_ < l) {\n                intervals.emplace_back(l_,\
    \ std::min(r_, l - 1), v_);\n            }\n            if (r < r_) {\n      \
    \          intervals.emplace_back(r + 1, r_, v_);\n            }\n           \
    \ it = st.erase(it);\n        }\n        for (auto [l_, r_, v_] : intervals) st.emplace(l_,\
    \ r_, v_);\n    }\n\n    void erase(X l, X r) { set(l, r, default_val); }\n\n\
    private:\n    std::set<std::tuple<X, X, T>> st;\n    T default_val;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/intervals.hpp
  requiredBy: []
  timestamp: '2022-06-30 16:20:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/intervals.hpp
layout: document
title: Intervals
---

## Description

整数の閉区間を管理する．

機能的には range update point get の双対セグメント木の上位互換である (`long long` 型の座標を扱える + 区間の列挙が可能である)．

## Operations

- `Intervals(T default_val)`
    - デフォルトの値 `default_val` を受け取り，初期化する
- `T get(X x)`
    - 点 $x$ での値を返す
    - 時間計算量: $O(\log n)$
- `vector<tuple<X, X, T>> get(X l, X r, T v)`
    - 区間 $[l, r]$ と交わる区間を返す
    - 時間計算量: $O(k\log n)$, $k$ は $[l, r]$ と交わる区間の数
- `void insert(X l, X y, T v)`
    - 区間 $[l, r]$ の値を $v$ に更新する．
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void erase(X l, X r)`
    - 区間 $[l, r]$ の値をデフォルトの値に戻す
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$