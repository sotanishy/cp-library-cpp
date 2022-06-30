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
  bundledCode: "#line 2 \"misc/interval_set.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <set>\n#include <utility>\n\ntemplate <typename T>\nclass IntervalSet\
    \ {\npublic:\n    static constexpr T INF = std::numeric_limits<T>::max() / 2;\n\
    \n    IntervalSet() {\n        st.emplace(INF, INF);\n        st.emplace(-INF,\
    \ -INF);\n    }\n\n    bool covered(T x) const { return covered(x, x); }\n   \
    \ bool covered(T l, T r) const {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
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
    \ <utility>\n\ntemplate <typename T>\nclass IntervalSet {\npublic:\n    static\
    \ constexpr T INF = std::numeric_limits<T>::max() / 2;\n\n    IntervalSet() {\n\
    \        st.emplace(INF, INF);\n        st.emplace(-INF, -INF);\n    }\n\n   \
    \ bool covered(T x) const { return covered(x, x); }\n    bool covered(T l, T r)\
    \ const {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l + 1,\
    \ l + 1}));\n        return it->first <= l && r <= it->second;\n    }\n\n    std::pair<T,\
    \ T> covered_by(T x) const { return covered_by(x, x); }\n    std::pair<T, T> covered_by(T\
    \ l, T r) const {\n        assert(l <= r);\n        auto it = --(st.lower_bound({l\
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
    \   return x;\n    }\n\nprivate:\n    std::set<std::pair<T, T>> st;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/interval_set.hpp
  requiredBy: []
  timestamp: '2022-06-30 16:20:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/interval_set.hpp
layout: document
redirect_from:
- /library/misc/interval_set.hpp
- /library/misc/interval_set.hpp.html
title: misc/interval_set.hpp
---
