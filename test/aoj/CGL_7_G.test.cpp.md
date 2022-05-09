---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../geometry/tangents.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G\"\
    \n#define ERROR 0.00001\n\n#include \"../../geometry/geometry.hpp\"\n#include\
    \ \"../../geometry/tangents.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(15);\n\n    Vec c1, c2;\n    T r1, r2;\n  \
    \  cin >> c1 >> r1 >> c2 >> r2;\n    auto ls = common_tangents(Circle(c1, r1),\
    \ Circle(c2, r2));\n    vector<Vec> ps;\n    for (auto& l : common_tangents(Circle(c1,\
    \ r1), Circle(c2, r2))) {\n        ps.push_back(l.p1);\n    }\n    sort(ps.begin(),\
    \ ps.end(), [&](auto& p, auto& q) {\n        if (eq(p.real(), q.real())) return\
    \ lt(p.imag(), q.imag());\n        return lt(p.real(), q.real());\n    });\n \
    \   for (auto& p : ps) {\n        cout << p.real() << \" \" << p.imag() << endl;\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_7_G.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_7_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_G.test.cpp
- /verify/test/aoj/CGL_7_G.test.cpp.html
title: test/aoj/CGL_7_G.test.cpp
---
