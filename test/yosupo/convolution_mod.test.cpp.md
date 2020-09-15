---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ntt.cpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/yosupo/convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 1 \"math/ntt.cpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Number Theoretic\
    \ Transform\n * @docs docs/math/ntt.md\n */\ntemplate <long long mod, long long\
    \ primitive_root>\nstruct NTT {\nprivate:\n    static long long mod_pow(long long\
    \ n, long long p) {\n        long long ret = 1;\n        while (p > 0) {\n   \
    \         if (p & 1) ret = ret * n % mod;\n            n = n * n % mod;\n    \
    \        p >>= 1;\n        }\n        return ret;\n    }\n\n    static pair<long\
    \ long, long long> extgcd(long long a, long long b) {\n        long long s = a,\
    \ sx = 1, sy = 0, t = b, tx = 0, ty = 1;\n        while (t) {\n            long\
    \ long q = s / t;\n            s -= t * q;\n            swap(s, t);\n        \
    \    sx -= tx * q;\n            swap(sx, tx);\n            sy -= ty * q;\n   \
    \         swap(sy, ty);\n        }\n        return {sx, sy};\n    }\n\n    static\
    \ long long mod_inv(long long a) {\n        long long inv = extgcd(a, mod).first;\n\
    \        return (inv % mod + mod) % mod;\n    }\n\n    static void untt(vector<long\
    \ long>& a) {\n        int n = a.size();\n        for (int m = n; m > 1; m >>=\
    \ 1) {\n            long long omega = mod_pow(primitive_root, (mod - 1) / m);\n\
    \            for (int s = 0; s < n / m; s++) {\n                long long w =\
    \ 1;\n                for (int i = 0; i < m / 2; i++) {\n                    long\
    \ long l = a[s * m + i];\n                    long long r = a[s * m + i + m /\
    \ 2];\n                    a[s * m + i] = (l + r) % mod;\n                   \
    \ a[s * m + i + m / 2] = (l - r + mod) * w % mod;\n                    w = w *\
    \ omega % mod;\n                }\n            }\n        }\n    }\n\n    static\
    \ void iuntt(vector<long long>& a) {\n        int n = a.size();\n        for (int\
    \ m = 2; m <= n; m <<= 1) {\n            long long omega = mod_inv(mod_pow(primitive_root,\
    \ (mod - 1) / m));\n            for (int s = 0; s < n / m; s++) {\n          \
    \      long long w = 1;\n                for (int i = 0; i < m / 2; i++) {\n \
    \                   long long l = a[s * m + i];\n                    long long\
    \ r = a[s * m + i + m / 2] * w % mod;\n                    a[s * m + i] = (l +\
    \ r) % mod;\n                    a[s * m + i + m / 2] = (l - r + mod) % mod;\n\
    \                    w = w * omega % mod;\n                }\n            }\n\
    \        }\n    }\n\n\npublic:\n    static vector<long long> convolution(const\
    \ vector<long long>& a, const vector<long long>& b) {\n        int size = a.size()\
    \ + b.size() - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n   \
    \     vector<long long> na = a, nb = b;\n        na.resize(n);\n        nb.resize(n);\n\
    \        untt(na);\n        untt(nb);\n        for (int i = 0; i < n; i++) na[i]\
    \ = na[i] * nb[i] % mod;\n        iuntt(na);\n        na.resize(size);\n     \
    \   long long n_inv = mod_inv(n);\n        for (int i = 0; i < size; i++) na[i]\
    \ = na[i] * n_inv % mod;\n        return na;\n    }\n};\n\n// <167772161, 3>\n\
    // <469762049, 3>\n// <754974721, 11>\n// <998244353, 3>\n// <1224736769, 3>\n\
    #line 4 \"test/yosupo/convolution_mod.test.cpp\"\n\nusing ll = long long;\n\n\
    int main() {\n    int N, M;\n    cin >> N >> M;\n    vector<ll> a(N), b(M);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    for (int i = 0; i < M; i++)\
    \ cin >> b[i];\n    vector<ll> c = NTT<998244353, 3>::convolution(a, b);\n   \
    \ for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i < N + M - 2 ? \" \" :\
    \ \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../math/ntt.cpp\"\n\nusing ll = long long;\n\nint main() {\n    int N,\
    \ M;\n    cin >> N >> M;\n    vector<ll> a(N), b(M);\n    for (int i = 0; i <\
    \ N; i++) cin >> a[i];\n    for (int i = 0; i < M; i++) cin >> b[i];\n    vector<ll>\
    \ c = NTT<998244353, 3>::convolution(a, b);\n    for (int i = 0; i < N + M - 1;\
    \ i++) cout << c[i] << (i < N + M - 2 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - math/ntt.cpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 02:03:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod.test.cpp
- /verify/test/yosupo/convolution_mod.test.cpp.html
title: test/yosupo/convolution_mod.test.cpp
---
