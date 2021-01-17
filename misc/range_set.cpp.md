---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/range_set.cpp\"\n#include <cassert>\n#include <limits>\n\
    #include <set>\n#include <utility>\n\ntemplate <typename T>\nclass RangeSet {\n\
    public:\n    static constexpr T INF = std::numeric_limits<T>::max() / 2;\n\n \
    \   RangeSet() {\n        st.emplace(INF, INF);\n        st.emplace(-INF, -INF);\n\
    \    }\n\n    bool covered(T x) const { return covered(x, x); }\n    bool covered(T\
    \ l, T r) const {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
    \ + 1, l + 1}));\n        return it->first <= l && r <= it->second;\n    }\n\n\
    \    std::pair<T, T> covered_by(T x) const { return covered_by(x, x); }\n    std::pair<T,\
    \ T> covered_by(T l, T r) const {\n        assert(l <= r);\n        auto it =\
    \ --(st.lower_bound({l + 1, l + 1}));\n        if (it->first <= l && r <= it->second)\
    \ return *it;\n        return {-INF, -INF};\n    }\n\n    void insert(T x) { insert(x,\
    \ x); }\n    void insert(T l, T r) {\n        assert(l <= r);\n        auto it\
    \ = --(st.lower_bound({l + 1, l + 1}));\n        if (it->first <= l && r <= it->second)\
    \ return;\n        if (it->first <= l && l <= it->second + 1) {\n            l\
    \ = it->first;\n            it = st.erase(it);\n        } else {\n           \
    \ ++it;\n        }\n        while (it->second < r) {\n            it = st.erase(it);\n\
    \        }\n        if (it->first - 1 <= r && r <= it->second) {\n           \
    \ r = it->second;\n            st.erase(it);\n        }\n        st.emplace(l,\
    \ r);\n    }\n\n    void erase(T x) { erase(x, x); }\n    void erase(T l, T r)\
    \ {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l + 1, l +\
    \ 1}));\n        if (it->first <= l && r <= it->second) {\n            if (it->first\
    \ < l) st.emplace(it->first, l - 1);\n            if (r < it->second) st.emplace(r\
    \ + 1, it->second);\n            st.erase(it);\n            return;\n        }\n\
    \        if (it->first <= l && l <= it->second) {\n            if (it->first <\
    \ l) st.emplace(it->first, l - 1);\n            it = st.erase(it);\n        }\
    \ else {\n            ++it;\n        }\n        while (it->second <= r) {\n  \
    \          it = st.erase(it);\n        }\n        if (it->first <= r && r <= it->second)\
    \ {\n            if (r < it->second) st.emplace(r + 1, it->second);\n        \
    \    st.erase(it);\n        }\n    }\n\n    std::set<std::pair<T, T>> ranges()\
    \ const { return st; }\n\n    T mex(T x) const {\n        auto it = --(st.lower_bound({x\
    \ + 1, x + 1}));\n        if (it->first <= x && x <= it->second) return it->second\
    \ + 1;\n        return x;\n    }\n\nprivate:\n    std::set<std::pair<T, T>> st;\n\
    };\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <set>\n#include\
    \ <utility>\n\ntemplate <typename T>\nclass RangeSet {\npublic:\n    static constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n\n    RangeSet() {\n        st.emplace(INF,\
    \ INF);\n        st.emplace(-INF, -INF);\n    }\n\n    bool covered(T x) const\
    \ { return covered(x, x); }\n    bool covered(T l, T r) const {\n        assert(l\
    \ <= r);\n        auto it = --(st.lower_bound({l + 1, l + 1}));\n        return\
    \ it->first <= l && r <= it->second;\n    }\n\n    std::pair<T, T> covered_by(T\
    \ x) const { return covered_by(x, x); }\n    std::pair<T, T> covered_by(T l, T\
    \ r) const {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
    \ + 1, l + 1}));\n        if (it->first <= l && r <= it->second) return *it;\n\
    \        return {-INF, -INF};\n    }\n\n    void insert(T x) { insert(x, x); }\n\
    \    void insert(T l, T r) {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
    \ + 1, l + 1}));\n        if (it->first <= l && r <= it->second) return;\n   \
    \     if (it->first <= l && l <= it->second + 1) {\n            l = it->first;\n\
    \            it = st.erase(it);\n        } else {\n            ++it;\n       \
    \ }\n        while (it->second < r) {\n            it = st.erase(it);\n      \
    \  }\n        if (it->first - 1 <= r && r <= it->second) {\n            r = it->second;\n\
    \            st.erase(it);\n        }\n        st.emplace(l, r);\n    }\n\n  \
    \  void erase(T x) { erase(x, x); }\n    void erase(T l, T r) {\n        assert(l\
    \ <= r);\n        auto it = --(st.lower_bound({l + 1, l + 1}));\n        if (it->first\
    \ <= l && r <= it->second) {\n            if (it->first < l) st.emplace(it->first,\
    \ l - 1);\n            if (r < it->second) st.emplace(r + 1, it->second);\n  \
    \          st.erase(it);\n            return;\n        }\n        if (it->first\
    \ <= l && l <= it->second) {\n            if (it->first < l) st.emplace(it->first,\
    \ l - 1);\n            it = st.erase(it);\n        } else {\n            ++it;\n\
    \        }\n        while (it->second <= r) {\n            it = st.erase(it);\n\
    \        }\n        if (it->first <= r && r <= it->second) {\n            if (r\
    \ < it->second) st.emplace(r + 1, it->second);\n            st.erase(it);\n  \
    \      }\n    }\n\n    std::set<std::pair<T, T>> ranges() const { return st; }\n\
    \n    T mex(T x) const {\n        auto it = --(st.lower_bound({x + 1, x + 1}));\n\
    \        if (it->first <= x && x <= it->second) return it->second + 1;\n     \
    \   return x;\n    }\n\nprivate:\n    std::set<std::pair<T, T>> st;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/range_set.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:23:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/range_set.cpp
layout: document
title: Range Set
---

## Description

整数の閉区間の集合を管理する．

## Operations

- `bool covered(T x)`
- `bool covered(T l, T r)`
    - 区間 $[l, r]$ が含まれているか判定する
    - 時間計算量: $O(\lg n)$
- `pair<T, T> covered_by(T x)`
- `pair<T, T> covered_by(T l, T r)`
    - 区間 $[l, r]$ を含む区間を返す．そのような区間がない場合は $(-\infty, -\infty)$ を返す
    - 時間計算量: $O(\lg n)$
- `void insert(T x)`
- `void insert(T l, T r)`
    - 区間 $[l, r]$ を集合に追加する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void erase(T x)`
- `void erase(T l, T r)`
    - 区間 $[l, r]$ を集合から削除する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `T mex(T x)`
    - $x$ 以上の整数のうち，集合に含まれない最小のものを返す
    - 時間計算量: $O(\lg n)$

## Reference

- [区間をsetで管理するやつでもうバグらせたくない](https://mugen1337.hatenablog.com/entry/2020/10/14/134022)
- [要素の追加・削除と mex を対数時間で処理するよ](https://rsk0315.hatenablog.com/entry/2020/10/11/125049)
