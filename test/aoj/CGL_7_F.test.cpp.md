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
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\"\
    \n#define ERROR 0.00001\n\n#include \"../../geometry/geometry.hpp\"\n#include\
    \ \"../../geometry/tangents.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(15);\n\n    Vec p, c;\n    T r;\n    cin >>\
    \ p >> c >> r;\n    auto [p1, p2] = tangent_points(Circle(c, r), p);\n    if (p1.real()\
    \ > p2.real() || (p1.real() == p2.real() && p1.imag() > p2.imag())) swap(p1, p2);\n\
    \    cout << p1.real() << \" \" << p1.imag() << endl;\n    cout << p2.real() <<\
    \ \" \" << p2.imag() << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_7_F.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_7_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_F.test.cpp
- /verify/test/aoj/CGL_7_F.test.cpp.html
title: test/aoj/CGL_7_F.test.cpp
---
