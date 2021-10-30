---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../math/geometry.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\"\
    \n\n#include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int q;\n    cin >> q;\n    while (q--) {\n        Vec p0, p1, p2, p3;\n\
    \        cin >> p0 >> p1 >> p2 >> p3;\n        auto p = p1 - p0, q = p3 - p2;\n\
    \        if (eq(cross(p, q), 0)) {\n            cout << 2 << \"\\n\";\n      \
    \  } else if (eq(dot(p, q), 0)) {\n            cout << 1 << \"\\n\";\n       \
    \ } else {\n            cout << 0 << \"\\n\";\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_2_A.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_A.test.cpp
- /verify/test/aoj/CGL_2_A.test.cpp.html
title: test/aoj/CGL_2_A.test.cpp
---
