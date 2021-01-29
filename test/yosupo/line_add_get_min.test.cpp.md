---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/li_chao_tree.cpp
    title: Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo/line_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line 2 \"data-structure/li_chao_tree.cpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <utility>\n#include <vector>\n\
    \n/*\n * @brief Li Chao Tree\n * @docs docs/data-structure/li_chao_tree.md\n */\n\
    template <typename T>\nclass LiChaoTree {\n    using Line = std::pair<T, T>;\n\
    \npublic:\n    LiChaoTree() = default;\n    explicit LiChaoTree(const std::vector<T>&\
    \ vs) : xs(vs) {\n        size = 1;\n        while (size < (int) xs.size()) size\
    \ <<= 1;\n        node.resize(2 * size, {0, INF});\n        while ((int) xs.size()\
    \ <= size) xs.push_back(xs.back() + 1);\n    }\n\n    void add_line(T a, T b)\
    \ {\n        update({a, b}, 1, 0, size);\n    }\n\n    void add_segment(T a, T\
    \ b, int l, int r) {\n        Line line(a, b);\n        int len = 1;\n       \
    \ int l0 = l, r0 = r;\n        for (l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1, len <<= 1) {\n            if (l & 1) {\n                update(line, l, l0,\
    \ l0 + len);\n                ++l;\n                l0 += len;\n            }\n\
    \            if (r & 1) {\n                --r;\n                r0 -= len;\n\
    \                update(line, r, r0, r0 + len);\n            }\n        }\n  \
    \  }\n\n    T get_min(int k) const {\n        const T x = xs[k];\n        k +=\
    \ size;\n        T res = f(node[k], x);\n        while (k >>= 1) res = std::min(res,\
    \ f(node[k], x));\n        return res;\n    }\n\nprivate:\n    static constexpr\
    \ T INF = std::numeric_limits<T>::max();\n\n    int size;\n    std::vector<T>\
    \ xs;\n    std::vector<Line> node;\n\n    inline T f(const Line& line, T x) const\
    \ {\n        return line.first * x + line.second;\n    }\n\n    void update(Line\
    \ line, int k, int l, int r) {\n        while (true) {\n            int m = (l\
    \ + r) / 2;\n            bool left = f(line, xs[l]) < f(node[k], xs[l]);\n   \
    \         bool mid = f(line, xs[m]) < f(node[k], xs[m]);\n            bool right\
    \ = f(line, xs[r]) < f(node[k], xs[r]);\n\n            if (!left && !right) break;\n\
    \            if (left && right) {\n                node[k] = line;\n         \
    \       break;\n            }\n            if (mid) std::swap(node[k], line);\n\
    \            if (r - l == 1) break;\n            if (left != mid) {\n        \
    \        k = 2 * k;\n                r = m;\n            } else {\n          \
    \      k = 2 * k + 1;\n                l = m;\n            }\n        }\n    }\n\
    };\n#line 4 \"test/yosupo/line_add_get_min.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct Query {\n    int t;\n  \
    \  ll a, b, p;\n    Query(int t, ll a, ll b) : t(t), a(a), b(b) {}\n    Query(int\
    \ t, ll p) : t(t), p(p) {}\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<ll,\
    \ ll>> ab(N);\n    for (int i = 0; i < N; ++i) cin >> ab[i].first >> ab[i].second;\n\
    \    vector<Query> query;\n    vector<ll> xs;\n    for (int i = 0; i < Q; ++i)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            ll\
    \ a, b;\n            cin >> a >> b;\n            query.emplace_back(t, a, b);\n\
    \        } else {\n            ll p;\n            cin >> p;\n            query.emplace_back(t,\
    \ p);\n            xs.push_back(p);\n        }\n    }\n    sort(xs.begin(), xs.end());\n\
    \    xs.erase(unique(xs.begin(), xs.end()), xs.end());\n    LiChaoTree<ll> lct(xs);\n\
    \    for (auto& p : ab) {\n        lct.add_line(p.first, p.second);\n    }\n \
    \   for (auto& q : query) {\n        if (q.t == 0) {\n            lct.add_line(q.a,\
    \ q.b);\n        } else {\n            cout << lct.get_min(lower_bound(xs.begin(),\
    \ xs.end(), q.p) - xs.begin()) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../../data-structure/li_chao_tree.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct Query {\n    int t;\n  \
    \  ll a, b, p;\n    Query(int t, ll a, ll b) : t(t), a(a), b(b) {}\n    Query(int\
    \ t, ll p) : t(t), p(p) {}\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<ll,\
    \ ll>> ab(N);\n    for (int i = 0; i < N; ++i) cin >> ab[i].first >> ab[i].second;\n\
    \    vector<Query> query;\n    vector<ll> xs;\n    for (int i = 0; i < Q; ++i)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            ll\
    \ a, b;\n            cin >> a >> b;\n            query.emplace_back(t, a, b);\n\
    \        } else {\n            ll p;\n            cin >> p;\n            query.emplace_back(t,\
    \ p);\n            xs.push_back(p);\n        }\n    }\n    sort(xs.begin(), xs.end());\n\
    \    xs.erase(unique(xs.begin(), xs.end()), xs.end());\n    LiChaoTree<ll> lct(xs);\n\
    \    for (auto& p : ab) {\n        lct.add_line(p.first, p.second);\n    }\n \
    \   for (auto& q : query) {\n        if (q.t == 0) {\n            lct.add_line(q.a,\
    \ q.b);\n        } else {\n            cout << lct.get_min(lower_bound(xs.begin(),\
    \ xs.end(), q.p) - xs.begin()) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/li_chao_tree.cpp
  isVerificationFile: true
  path: test/yosupo/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2020-11-02 19:09:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min.test.cpp
- /verify/test/yosupo/line_add_get_min.test.cpp.html
title: test/yosupo/line_add_get_min.test.cpp
---
