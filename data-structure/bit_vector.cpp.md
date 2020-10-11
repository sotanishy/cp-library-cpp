---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet_matrix.cpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bit Vector
    links: []
  bundledCode: "#line 1 \"data-structure/bit_vector.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Bit Vector\n */\nclass BitVector {\n    using u32 = uint32_t;\n\
    \npublic:\n    BitVector() = default;\n    explicit BitVector(const std::vector<bool>&\
    \ v) {\n        int n = (v.size() + sz - 1) / sz;\n        data.resize(n);\n \
    \       sum.resize(n + 1);\n        for (int i = 0; i < (int) v.size(); ++i) data[i\
    \ / sz] |= v[i] << (i % sz);\n        for (int i = 0; i < n; ++i) sum[i + 1] =\
    \ sum[i] + __builtin_popcount(data[i]);\n    }\n\n    int access(int k) const\
    \ {\n        return data[k / sz] >> (k % sz) & 1;\n    }\n\n    int rank(int k,\
    \ bool b) const {\n        int mask = (1 << (k % sz)) - 1;\n        int r = sum[k\
    \ / sz] + __builtin_popcount(data[k / sz] & mask);\n        return b ? r : k -\
    \ r;\n    }\n\n    int select(int k, bool b) const {\n        int lb = 0, ub =\
    \ data.size();\n        while (ub - lb > 1) {\n            int m = (lb + ub) /\
    \ 2;\n            if (rank(m, b) <= k) lb = m;\n            else ub = m;\n   \
    \     }\n        return lb;\n    }\n\nprivate:\n    static constexpr int sz =\
    \ 32;\n\n    std::vector<u32> data;\n    std::vector<int> sum;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Bit Vector\n */\nclass BitVector\
    \ {\n    using u32 = uint32_t;\n\npublic:\n    BitVector() = default;\n    explicit\
    \ BitVector(const std::vector<bool>& v) {\n        int n = (v.size() + sz - 1)\
    \ / sz;\n        data.resize(n);\n        sum.resize(n + 1);\n        for (int\
    \ i = 0; i < (int) v.size(); ++i) data[i / sz] |= v[i] << (i % sz);\n        for\
    \ (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + __builtin_popcount(data[i]);\n\
    \    }\n\n    int access(int k) const {\n        return data[k / sz] >> (k % sz)\
    \ & 1;\n    }\n\n    int rank(int k, bool b) const {\n        int mask = (1 <<\
    \ (k % sz)) - 1;\n        int r = sum[k / sz] + __builtin_popcount(data[k / sz]\
    \ & mask);\n        return b ? r : k - r;\n    }\n\n    int select(int k, bool\
    \ b) const {\n        int lb = 0, ub = data.size();\n        while (ub - lb >\
    \ 1) {\n            int m = (lb + ub) / 2;\n            if (rank(m, b) <= k) lb\
    \ = m;\n            else ub = m;\n        }\n        return lb;\n    }\n\nprivate:\n\
    \    static constexpr int sz = 32;\n\n    std::vector<u32> data;\n    std::vector<int>\
    \ sum;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bit_vector.cpp
  requiredBy:
  - data-structure/wavelet_matrix.cpp
  timestamp: '2020-10-12 03:03:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: data-structure/bit_vector.cpp
layout: document
redirect_from:
- /library/data-structure/bit_vector.cpp
- /library/data-structure/bit_vector.cpp.html
title: Bit Vector
---
