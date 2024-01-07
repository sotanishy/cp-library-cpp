---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/fft.hpp
    title: Fast Fourier Transform
  - icon: ':question:'
    path: tree/centroid_decomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/yosupo/frequency_table_of_tree_distance.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#line 2 \"tree/centroid_decomposition.hpp\"\n#include <tuple>\n#include <vector>\n\
    \nstd::tuple<std::vector<int>, std::vector<int>, std::vector<int>> centroid_decomposition(const\
    \ std::vector<std::vector<int>>& G) {\n    int N = G.size();\n    std::vector<int>\
    \ sz(N), level(N, -1), sz_comp(N), par(N);\n\n    auto dfs_size = [&](auto& dfs_size,\
    \ int v, int p) -> int {\n        sz[v] = 1;\n        for (int c : G[v]) {\n \
    \           if (c != p && level[c] == -1) sz[v] += dfs_size(dfs_size, c, v);\n\
    \        }\n        return sz[v];\n    };\n\n    auto dfs_centroid = [&](auto&\
    \ dfs_centroid, int v, int p, int n) -> int {\n        for (int c : G[v]) {\n\
    \            if (c != p && level[c] == -1 && sz[c] > n / 2) return dfs_centroid(dfs_centroid,\
    \ c, v, n);\n        }\n        return v;\n    };\n\n    auto decompose = [&](auto&\
    \ decompose, int v, int k, int p) -> void {\n        int n = dfs_size(dfs_size,\
    \ v, -1);\n        int s = dfs_centroid(dfs_centroid, v, -1, n);\n        level[s]\
    \ = k;\n        sz_comp[s] = n;\n        par[s] = p;\n        for (int c : G[s])\
    \ {\n            if (level[c] == -1) decompose(decompose, c, k + 1, s);\n    \
    \    }\n    };\n\n    decompose(decompose, 0, 0, -1);\n    return {level, sz_comp,\
    \ par};\n}\n#line 2 \"convolution/fft.hpp\"\n#include <complex>\n#include <numbers>\n\
    #line 5 \"convolution/fft.hpp\"\n\nvoid fft(std::vector<std::complex<double>>&\
    \ a) {\n    const int n = a.size();\n    for (int m = n; m > 1; m >>= 1) {\n \
    \       double ang = 2.0 * std::numbers::pi / m;\n        std::complex<double>\
    \ omega(cos(ang), sin(ang));\n        for (int s = 0; s < n / m; ++s) {\n    \
    \        std::complex<double> w(1, 0);\n            for (int i = 0; i < m / 2;\
    \ ++i) {\n                auto l = a[s * m + i];\n                auto r = a[s\
    \ * m + i + m / 2];\n                a[s * m + i] = l + r;\n                a[s\
    \ * m + i + m / 2] = (l - r) * w;\n                w *= omega;\n            }\n\
    \        }\n    }\n}\n\nvoid ifft(std::vector<std::complex<double>>& a) {\n  \
    \  const int n = a.size();\n    for (int m = 2; m <= n; m <<= 1) {\n        double\
    \ ang = -2.0 * std::numbers::pi / m;\n        std::complex<double> omega(cos(ang),\
    \ sin(ang));\n        for (int s = 0; s < n / m; ++s) {\n            std::complex<double>\
    \ w(1, 0);\n            for (int i = 0; i < m / 2; ++i) {\n                auto\
    \ l = a[s * m + i];\n                auto r = a[s * m + i + m / 2] * w;\n    \
    \            a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = l -\
    \ r;\n                w *= omega;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nstd::vector<double> convolution(const std::vector<T>& a,\n   \
    \                             const std::vector<T>& b) {\n    const int size =\
    \ a.size() + b.size() - 1;\n    const int n = std::bit_ceil(size);\n    std::vector<std::complex<double>>\
    \ na(a.begin(), a.end()),\n        nb(b.begin(), b.end());\n    na.resize(n);\n\
    \    nb.resize(n);\n    fft(na);\n    fft(nb);\n    for (int i = 0; i < n; ++i)\
    \ na[i] *= nb[i];\n    ifft(na);\n    std::vector<double> ret(size);\n    for\
    \ (int i = 0; i < size; ++i) ret[i] = na[i].real() / n;\n    return ret;\n}\n\
    #line 5 \"test/yosupo/frequency_table_of_tree_distance.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define rep(i,\
    \ s, t) for (int i = (int)(s); i < (int)(t); ++i)\n#define revrep(i, t, s) for\
    \ (int i = (int)(t)-1; i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\n\
    template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1)\
    \ : 0; }\ntemplate <typename T> bool chmin(T& a, const T& b) { return a > b ?\
    \ (a = b, 1) : 0; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n \
    \   cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int N;\n\
    \    cin >> N;\n    vector<vector<int>> G(N);\n    rep(i,0,N-1) {\n        int\
    \ a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n\
    \    }\n\n    vector<int> level, sz, par;\n    tie(level, sz, par) = centroid_decomposition(G);\n\
    \n    vector<ll> ans(N);\n    vector<double> cnt;\n\n    auto dfs = [&](auto&\
    \ dfs, int v, int p, int d, int l) -> void {\n        if (cnt.size() <= d) cnt.push_back(0);\n\
    \        ++cnt[d];\n        for (int c : G[v]) {\n            if (c != p && level[c]\
    \ > l) {\n                dfs(dfs, c, v, d+1, l);\n            }\n        }\n\
    \    };\n\n    auto calc = [&](int s) {\n        vector<double> res(sz[s]);\n\
    \        cnt.assign(1, 0);\n        for (int c : G[s]) {\n            if (level[c]\
    \ > level[s]) {\n                dfs(dfs, c, s, 1, level[s]);\n            }\n\
    \        }\n        auto conv = convolution(cnt, cnt);\n        rep(d,0,cnt.size())\
    \ {\n            res[d] += cnt[d];\n        }\n        rep(d,0,min(conv.size(),\
    \ res.size())) {\n            res[d] += conv[d]/2;\n        }\n        for (int\
    \ c : G[s]) {\n            if (level[c] > level[s]) {\n                cnt.assign(1,\
    \ 0);\n                dfs(dfs, c, s, 1, level[s]);\n                auto conv\
    \ = convolution(cnt, cnt);\n                rep(d,0,min(conv.size(), res.size()))\
    \ {\n                    res[d] -= conv[d]/2;\n                }\n           \
    \ }\n        }\n        rep(d,0,sz[s]) {\n            ans[d] += (ll) round(res[d]);\n\
    \        }\n    };\n\n    rep(i,0,N) calc(i);\n    rep(d,1,N) cout << ans[d] <<\
    \ (d < N-1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../../tree/centroid_decomposition.hpp\"\n#include \"../../convolution/fft.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)\n#define revrep(i, t,\
    \ s) for (int i = (int)(t)-1; i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\n\
    template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1)\
    \ : 0; }\ntemplate <typename T> bool chmin(T& a, const T& b) { return a > b ?\
    \ (a = b, 1) : 0; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n \
    \   cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int N;\n\
    \    cin >> N;\n    vector<vector<int>> G(N);\n    rep(i,0,N-1) {\n        int\
    \ a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n\
    \    }\n\n    vector<int> level, sz, par;\n    tie(level, sz, par) = centroid_decomposition(G);\n\
    \n    vector<ll> ans(N);\n    vector<double> cnt;\n\n    auto dfs = [&](auto&\
    \ dfs, int v, int p, int d, int l) -> void {\n        if (cnt.size() <= d) cnt.push_back(0);\n\
    \        ++cnt[d];\n        for (int c : G[v]) {\n            if (c != p && level[c]\
    \ > l) {\n                dfs(dfs, c, v, d+1, l);\n            }\n        }\n\
    \    };\n\n    auto calc = [&](int s) {\n        vector<double> res(sz[s]);\n\
    \        cnt.assign(1, 0);\n        for (int c : G[s]) {\n            if (level[c]\
    \ > level[s]) {\n                dfs(dfs, c, s, 1, level[s]);\n            }\n\
    \        }\n        auto conv = convolution(cnt, cnt);\n        rep(d,0,cnt.size())\
    \ {\n            res[d] += cnt[d];\n        }\n        rep(d,0,min(conv.size(),\
    \ res.size())) {\n            res[d] += conv[d]/2;\n        }\n        for (int\
    \ c : G[s]) {\n            if (level[c] > level[s]) {\n                cnt.assign(1,\
    \ 0);\n                dfs(dfs, c, s, 1, level[s]);\n                auto conv\
    \ = convolution(cnt, cnt);\n                rep(d,0,min(conv.size(), res.size()))\
    \ {\n                    res[d] -= conv[d]/2;\n                }\n           \
    \ }\n        }\n        rep(d,0,sz[s]) {\n            ans[d] += (ll) round(res[d]);\n\
    \        }\n    };\n\n    rep(i,0,N) calc(i);\n    rep(d,1,N) cout << ans[d] <<\
    \ (d < N-1 ? \" \" : \"\\n\");\n}"
  dependsOn:
  - tree/centroid_decomposition.hpp
  - convolution/fft.hpp
  isVerificationFile: true
  path: test/yosupo/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 22:37:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp.html
title: test/yosupo/frequency_table_of_tree_distance.test.cpp
---
