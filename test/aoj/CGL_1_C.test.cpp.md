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
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    Vec p0, p1;\n    cin >> p0 >> p1;\n    int q;\n    cin >> q;\n    while\
    \ (q--) {\n        Vec p2;\n        cin >> p2;\n        switch (ccw(p0, p1, p2))\
    \ {\n            case 0:\n            if (on_segment(p0, p1, p2)) cout << \"ON_SEGMENT\\\
    n\";\n            else if (on_segment(p1, p2, p0)) cout << \"ONLINE_BACK\\n\"\
    ;\n            else if (on_segment(p2, p0, p1)) cout << \"ONLINE_FRONT\\n\";\n\
    \            break;\n\n            case 1:\n            cout << \"COUNTER_CLOCKWISE\\\
    n\";\n            break;\n\n            case -1:\n            cout << \"CLOCKWISE\\\
    n\";\n            break;\n        }\n    }\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_C.test.cpp
- /verify/test/aoj/CGL_1_C.test.cpp.html
title: test/aoj/CGL_1_C.test.cpp
---
