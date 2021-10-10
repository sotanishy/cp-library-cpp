---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/cht/li_chao_tree.cpp
    title: Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/yosupo/segment_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n#line 2 \"data-structure/cht/li_chao_tree.cpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T>\nclass LiChaoTree {\npublic:\n    LiChaoTree() = default;\n\
    \    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        size = 1;\n        while (size < (int) xs.size()) size <<= 1;\n     \
    \   node.resize(2 * size, {0, INF});\n        while ((int) xs.size() <= size)\
    \ xs.push_back(xs.back() + 1);\n    }\n\n    void add_line(T a, T b) {\n     \
    \   update({a, b}, 1, 0, size);\n    }\n\n    void add_segment(T a, T b, T xl,\
    \ T xr) {\n        int l = std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n\
    \        int r = std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin();\n\n\
    \        Line line(a, b);\n        int len = 1;\n        int l0 = l, r0 = r;\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {\n  \
    \          if (l & 1) {\n                update(line, l++, l0, l0 + len);\n  \
    \              ++l;\n                l0 += len;\n            }\n            if\
    \ (r & 1) {\n                --r;\n                r0 -= len;\n              \
    \  update(line, r, r0, r0 + len);\n            }\n        }\n    }\n\n    T get(T\
    \ x) const {\n        int k = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \        k += size;\n        T res = node[k](x);\n        while (k >>= 1) res\
    \ = std::min(res, node[k](x));\n        return res;\n    }\n\nprivate:\n    struct\
    \ Line {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n        T operator()(T\
    \ x) const { return a * x + b; }\n    };\n\n    static constexpr T INF = std::numeric_limits<T>::max();\n\
    \n    int size;\n    std::vector<T> xs;\n    std::vector<Line> node;\n\n    void\
    \ update(Line line, int k, int l, int r) {\n        while (true) {\n         \
    \   int m = (l + r) / 2;\n            bool left = line(xs[l]) < node[k](xs[l]);\n\
    \            bool mid = line(xs[m]) < node[k](xs[m]);\n            bool right\
    \ = line(xs[r]) < node[k](xs[r]);\n\n            if (!left && !right) break;\n\
    \            if (left && right) {\n                node[k] = line;\n         \
    \       break;\n            }\n            if (mid) std::swap(node[k], line);\n\
    \            if (r - l == 1) break;\n            if (left != mid) {\n        \
    \        k = 2 * k;\n                r = m;\n            } else {\n          \
    \      k = 2 * k + 1;\n                l = m;\n            }\n        }\n    }\n\
    };\n#line 4 \"test/yosupo/segment_add_get_min.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct Segment {\n    ll l, r,\
    \ a, b;\n    Segment() = default;\n    Segment(ll l, ll r, ll a, ll b) : l(l),\
    \ r(r), a(a), b(b) {}\n};\n\nstruct Query {\n    int t;\n    Segment seg;\n  \
    \  ll p;\n    Query(int t, ll l, ll r, ll a, ll b) : t(t), seg(l, r, a, b) {}\n\
    \    Query(int t, ll p) : t(t), p(p) {}\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> xs;\n\
    \    vector<Segment> seg(N);\n    for (int i = 0; i < N; ++i) {\n        cin >>\
    \ seg[i].l >> seg[i].r >> seg[i].a >> seg[i].b;\n        xs.push_back(seg[i].l);\n\
    \        xs.push_back(seg[i].r);\n    }\n    vector<Query> query;\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            ll l, r, a, b;\n            cin >> l >> r >> a >> b;\n      \
    \      query.emplace_back(t, l, r, a, b);\n        } else {\n            ll p;\n\
    \            cin >> p;\n            query.emplace_back(t, p);\n            xs.push_back(p);\n\
    \        }\n    }\n    LiChaoTree<ll> lct(xs);\n    for (auto& s : seg) {\n  \
    \      lct.add_segment(s.a, s.b, s.l, s.r);\n    }\n    for (auto& q : query)\
    \ {\n        if (q.t == 0) {\n            lct.add_segment(q.seg.a, q.seg.b, q.seg.l,\
    \ q.seg.r);\n        } else {\n            ll ans = lct.get(q.p);\n          \
    \  if (ans > 5e18) cout << \"INFINITY\\n\";\n            else cout << ans << \"\
    \\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../../data-structure/cht/li_chao_tree.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct Segment {\n    ll l, r,\
    \ a, b;\n    Segment() = default;\n    Segment(ll l, ll r, ll a, ll b) : l(l),\
    \ r(r), a(a), b(b) {}\n};\n\nstruct Query {\n    int t;\n    Segment seg;\n  \
    \  ll p;\n    Query(int t, ll l, ll r, ll a, ll b) : t(t), seg(l, r, a, b) {}\n\
    \    Query(int t, ll p) : t(t), p(p) {}\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> xs;\n\
    \    vector<Segment> seg(N);\n    for (int i = 0; i < N; ++i) {\n        cin >>\
    \ seg[i].l >> seg[i].r >> seg[i].a >> seg[i].b;\n        xs.push_back(seg[i].l);\n\
    \        xs.push_back(seg[i].r);\n    }\n    vector<Query> query;\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            ll l, r, a, b;\n            cin >> l >> r >> a >> b;\n      \
    \      query.emplace_back(t, l, r, a, b);\n        } else {\n            ll p;\n\
    \            cin >> p;\n            query.emplace_back(t, p);\n            xs.push_back(p);\n\
    \        }\n    }\n    LiChaoTree<ll> lct(xs);\n    for (auto& s : seg) {\n  \
    \      lct.add_segment(s.a, s.b, s.l, s.r);\n    }\n    for (auto& q : query)\
    \ {\n        if (q.t == 0) {\n            lct.add_segment(q.seg.a, q.seg.b, q.seg.l,\
    \ q.seg.r);\n        } else {\n            ll ans = lct.get(q.p);\n          \
    \  if (ans > 5e18) cout << \"INFINITY\\n\";\n            else cout << ans << \"\
    \\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/cht/li_chao_tree.cpp
  isVerificationFile: true
  path: test/yosupo/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2021-10-10 23:27:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/segment_add_get_min.test.cpp
- /verify/test/yosupo/segment_add_get_min.test.cpp.html
title: test/yosupo/segment_add_get_min.test.cpp
---
