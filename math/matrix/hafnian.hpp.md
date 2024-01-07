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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../set/set_power_series.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"../set/set_power_series.hpp\"\
    \n\ntemplate <typename T, int N>\nT hafnian(std::vector<std::vector<T>> mat) {\n\
    \    const int n = mat.size();\n    assert(n % 2 == 0);\n    const int n2 = n\
    \ / 2;\n\n    // cyc[S]: number of alternating cycles using all edges in S\n \
    \   SetPowerSeries<T, N> cyc(1 << n2);\n\n    for (int i = 0; i < n2; ++i) {\n\
    \        int ui = 2 * i, vi = 2 * i + 1;\n        // ui-vi=ui\n        cyc[1 <<\
    \ i] += mat[ui][vi];\n\n        // dp[S][v]: number of alternating paths between\
    \ ui and v\n        // using all edges in S\n        std::vector dp(1 << i, std::vector<T>(2\
    \ * i));\n        for (int j = 0; j < i; ++j) {\n            int uj = 2 * j, vj\
    \ = 2 * j + 1;\n            dp[1 << j][uj] += mat[ui][vj];  // ui-vj=uj\n    \
    \        dp[1 << j][vj] += mat[ui][uj];  // ui-uj=vj\n        }\n\n        for\
    \ (int S = 0; S < (1 << i); ++S) {\n            for (int j = 0; j < i; ++j) {\n\
    \                int uj = 2 * j, vj = 2 * j + 1;\n                cyc[S | (1 <<\
    \ i)] +=\n                    dp[S][uj] * mat[vi][uj];  // ui-...=uj-vi=ui\n \
    \               cyc[S | (1 << i)] +=\n                    dp[S][vj] * mat[vi][vj];\
    \  // ui-...=vj-vi=ui\n\n                for (int k = 0; k < i; ++k) {\n     \
    \               if (!(S >> k & 1)) {\n                        int uk = 2 * k,\
    \ vk = 2 * k + 1;\n                        int nS = S | (1 << k);\n\n        \
    \                dp[nS][uk] +=\n                            dp[S][uj] * mat[uj][vk];\
    \  // ui-...=uj-vk=uk\n                        dp[nS][uk] +=\n               \
    \             dp[S][vj] * mat[vj][vk];  // ui-...=vj-vk=uk\n                 \
    \       dp[nS][vk] +=\n                            dp[S][uj] * mat[uj][uk];  //\
    \ ui-...=uj-uk=vk\n                        dp[nS][vk] +=\n                   \
    \         dp[S][vj] * mat[vj][uk];  // ui-...=vj-uk=vk\n                    }\n\
    \                }\n            }\n        }\n    }\n    return cyc.exp().back();\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/hafnian.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/hafnian.hpp
layout: document
title: Hafnian
---

## Description

偶数次対称行列のハフニアンを求める． $2n \times 2n$ 対称行列 $A$ のハフニアンは次式で定義される．
$$
\operatorname{haf}(A) = \sum_{\rho \in P_{2n}^2} \prod_{\{i,j\} \in \rho} A_{i,j}
$$
ここで， $P_{2n}^n$ は $\{1,2,\dots,2n\}$ の大きさ $2$ の部分集合への分割の全体である．

これは， $A$ を隣接行列として持つ無向グラフの完全マッチングの個数である．

## Operations

- `T hafnian(vector<vector<T>> mat)`
    - 与えられた偶数次対称行列のハフニアンを求める
    - 時間計算量: $O(n^2 2^{n/2})$

## Reference

- [Hafnian of Matrix - @tko919, HackMD](https://hackmd.io/@tko919/HyTPhjWco)
- [集合べき級数関連 (4) 問題例 - maspyのHP](https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b)