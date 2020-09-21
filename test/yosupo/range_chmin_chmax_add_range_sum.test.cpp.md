---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment_tree_beats.cpp
    title: Segment Tree Beats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#line 1 \"data-structure/segment_tree_beats.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Segment Tree Beats\n * @docs docs/data-structure/segment_tree_beats.md\n\
    \ */\ntemplate <typename T>\nclass SegmentTreeBeats {\npublic:\n    explicit SegmentTreeBeats(int\
    \ n) : SegmentTreeBeats(std::vector<T>(n)) {}\n    explicit SegmentTreeBeats(const\
    \ std::vector<T>& v) {\n        size = 1;\n        while (size < (int) v.size())\
    \ size <<= 1;\n        sum.resize(2 * size);\n        lazy.resize(2 * size);\n\
    \        max_val.resize(2 * size, NINF);\n        smax_val.resize(2 * size, NINF);\n\
    \        max_cnt.resize(2 * size);\n        min_val.resize(2 * size, INF);\n \
    \       smin_val.resize(2 * size, INF);\n        min_cnt.resize(2 * size);\n \
    \       len.resize(2 * size);\n        len[1] = size;\n        for (int i = 2;\
    \ i < 2 * size; i++) len[i] = len[i / 2] >> 1;\n        for (int i = 0; i < (int)\
    \ v.size(); i++) {\n            sum[size + i] = max_val[size + i] = min_val[size\
    \ + i] = v[i];\n            max_cnt[size + i] = min_cnt[size + i] = 1;\n     \
    \   }\n        for (int i = size - 1; i > 0; i--) recalc(i);\n    }\n\n    T operator[](int\
    \ k) {\n        return fold_sum(k, k + 1);\n    }\n\n    void chmin(int l, int\
    \ r, T x) { update<CHMIN>(l, r, x, 1, 0, size); }\n    void chmax(int l, int r,\
    \ T x) { update<CHMAX>(l, r, x, 1, 0, size); }\n    void add(int l, int r, T x)\
    \ { update<ADD>(l, r, x, 1, 0, size); }\n\n    T fold_min(int l, int r) { return\
    \ fold<MIN>(l, r, 1, 0, size); }\n    T fold_max(int l, int r) { return fold<MAX>(l,\
    \ r, 1, 0, size); }\n    T fold_sum(int l, int r) { return fold<SUM>(l, r, 1,\
    \ 0, size); }\n\nprivate:\n    const T INF = std::numeric_limits<T>::max();\n\
    \    const T NINF = std::numeric_limits<T>::min();\n\n    int size;\n    std::vector<T>\
    \ sum, lazy;\n    std::vector<T> max_val, smax_val;\n    std::vector<T> min_val,\
    \ smin_val;\n    std::vector<int> len, max_cnt, min_cnt;\n\n    enum OpType {\n\
    \        CHMIN, CHMAX, ADD\n    };\n\n    enum QueryType {\n        MIN, MAX,\
    \ SUM\n    };\n\n    void recalc(int k) {\n        sum[k] = sum[2 * k] + sum[2\
    \ * k + 1];\n\n        if (max_val[2 * k] > max_val[2 * k + 1]) {\n          \
    \  max_val[k] = max_val[2 * k];\n            max_cnt[k] = max_cnt[2 * k];\n  \
    \          smax_val[k] = std::max(smax_val[2 * k], max_val[2 * k + 1]);\n    \
    \    } else if (max_val[2 * k] < max_val[2 * k + 1]) {\n            max_val[k]\
    \ = max_val[2 * k + 1];\n            max_cnt[k] = max_cnt[2 * k + 1];\n      \
    \      smax_val[k] = std::max(max_val[2 * k], smax_val[2 * k + 1]);\n        }\
    \ else {\n            max_val[k] = max_val[2 * k];\n            max_cnt[k] = max_cnt[2\
    \ * k] + max_cnt[2 * k + 1];\n            smax_val[k] = std::max(smax_val[2 *\
    \ k], smax_val[2 * k + 1]);\n        }\n\n        if (min_val[2 * k] < min_val[2\
    \ * k + 1]) {\n            min_val[k] = min_val[2 * k];\n            min_cnt[k]\
    \ = min_cnt[2 * k];\n            smin_val[k] = std::min(smin_val[2 * k], min_val[2\
    \ * k + 1]);\n        } else if (min_val[2 * k] > min_val[2 * k + 1]) {\n    \
    \        min_val[k] = min_val[2 * k + 1];\n            min_cnt[k] = min_cnt[2\
    \ * k + 1];\n            smin_val[k] = std::min(min_val[2 * k], smin_val[2 * k\
    \ + 1]);\n        } else {\n            min_val[k] = min_val[2 * k];\n       \
    \     min_cnt[k] = min_cnt[2 * k] + min_cnt[2 * k + 1];\n            smin_val[k]\
    \ = std::min(smin_val[2 * k], smin_val[2 * k + 1]);\n        }\n    }\n\n    template\
    \ <OpType TYPE>\n    void tag(int k, T x) {\n        if (TYPE == CHMIN) {\n  \
    \          sum[k] += (x - max_val[k]) * max_cnt[k];\n            if (max_val[k]\
    \ == min_val[k]) min_val[k] = x;\n            else if (max_val[k] == smin_val[k])\
    \ smin_val[k] = x;\n            max_val[k] = x;\n        } else if (TYPE == CHMAX)\
    \ {\n            sum[k] += (x - min_val[k]) * min_cnt[k];\n            if (min_val[k]\
    \ == max_val[k]) max_val[k] = x;\n            else if (min_val[k] == smax_val[k])\
    \ smax_val[k] = x;\n            min_val[k] = x;\n        } else if (TYPE == ADD)\
    \ {\n            min_val[k] += x;\n            if (smin_val[k] != INF) smin_val[k]\
    \ += x;\n            max_val[k] += x;\n            if (smax_val[k] != NINF) smax_val[k]\
    \ += x;\n            sum[k] += x * len[k];\n            lazy[k] += x;\n      \
    \  }\n    }\n\n    void push(int k) {\n        if (lazy[k] != 0) {\n         \
    \   tag<ADD>(2 * k, lazy[k]);\n            tag<ADD>(2 * k + 1, lazy[k]);\n   \
    \         lazy[k] = 0;\n        }\n        if (max_val[k] < max_val[2 * k]) tag<CHMIN>(2\
    \ * k, max_val[k]);\n        if (min_val[k] > min_val[2 * k]) tag<CHMAX>(2 * k,\
    \ min_val[k]);\n        if (max_val[k] < max_val[2 * k + 1]) tag<CHMIN>(2 * k\
    \ + 1, max_val[k]);\n        if (min_val[k] > min_val[2 * k + 1]) tag<CHMAX>(2\
    \ * k + 1, min_val[k]);\n    }\n\n    template <OpType TYPE>\n    inline bool\
    \ break_cond(int k, T x) {\n        if (TYPE == CHMIN) return max_val[k] <= x;\n\
    \        if (TYPE == CHMAX) return min_val[k] >= x;\n        if (TYPE == ADD)\
    \ return false;\n    }\n\n    template <OpType TYPE>\n    inline bool tag_cond(int\
    \ k, T x) {\n        if (TYPE == CHMIN) return smax_val[k] < x;\n        if (TYPE\
    \ == CHMAX) return smin_val[k] > x;\n        if (TYPE == ADD) return true;\n \
    \   }\n\n    template <OpType TYPE>\n    void update(int a, int b, T x, int k,\
    \ int l, int r) {\n        if (r <= a || b <= l || break_cond<TYPE>(k, x)) return;\n\
    \        if (a <= l && r <= b && tag_cond<TYPE>(k, x)) {\n            tag<TYPE>(k,\
    \ x);\n            return;\n        }\n        push(k);\n        int m = (l +\
    \ r) / 2;\n        update<TYPE>(a, b, x, 2 * k, l, m);\n        update<TYPE>(a,\
    \ b, x, 2 * k + 1, m, r);\n        recalc(k);\n    }\n\n    template <QueryType\
    \ TYPE>\n    T fold(int a, int b, int k, int l, int r) {\n        if (r <= a ||\
    \ b <= l) {\n            if (TYPE == MIN) return INF;\n            if (TYPE ==\
    \ MAX) return NINF;\n            if (TYPE == SUM) return 0;\n        }\n     \
    \   if (a <= l && r <= b) {\n            if (TYPE == MIN) return min_val[k];\n\
    \            if (TYPE == MAX) return max_val[k];\n            if (TYPE == SUM)\
    \ return sum[k];\n        }\n        push(k);\n        int m = (l + r) / 2;\n\
    \        T vl = fold<TYPE>(a, b, 2 * k, l, m);\n        T vr = fold<TYPE>(a, b,\
    \ 2 * k + 1, m, r);\n        if (TYPE == MIN) return std::min(vl, vr);\n     \
    \   if (TYPE == MAX) return std::max(vl, vr);\n        if (TYPE == SUM) return\
    \ vl + vr;\n        return -1;\n    }\n};\n#line 4 \"test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\nusing namespace std;\n\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    SegmentTreeBeats<ll> st(a);\n\
    \    for (int i = 0; i < Q; i++) {\n        int t, l, r;\n        ll b;\n    \
    \    cin >> t >> l >> r;\n        if (t != 3) cin >> b;\n        if (t == 0) {\n\
    \            st.chmin(l, r, b);\n        } else if (t == 1) {\n            st.chmax(l,\
    \ r, b);\n        } else if (t == 2) {\n            st.add(l, r, b);\n       \
    \ } else {\n            cout << st.fold_sum(l, r) << \"\\n\";\n        }\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"../../data-structure/segment_tree_beats.cpp\"\n\nusing namespace\
    \ std;\n\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    SegmentTreeBeats<ll> st(a);\n\
    \    for (int i = 0; i < Q; i++) {\n        int t, l, r;\n        ll b;\n    \
    \    cin >> t >> l >> r;\n        if (t != 3) cin >> b;\n        if (t == 0) {\n\
    \            st.chmin(l, r, b);\n        } else if (t == 1) {\n            st.chmax(l,\
    \ r, b);\n        } else if (t == 2) {\n            st.add(l, r, b);\n       \
    \ } else {\n            cout << st.fold_sum(l, r) << \"\\n\";\n        }\n   \
    \ }\n}"
  dependsOn:
  - data-structure/segment_tree_beats.cpp
  isVerificationFile: true
  path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
---
