---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Die
    links: []
  bundledCode: "#line 2 \"misc/die.hpp\"\n#include <cassert>\n\n/**\n * @brief Die\n\
    \ */\nstruct Die {\n    int top = 1, south = 2, east = 3, west = 4, north = 5,\
    \ bottom = 6;\n\n    void roll(char dir) {\n        if (dir == 'N') {\n      \
    \      int tmp = top;\n            top = south;\n            south = bottom;\n\
    \            bottom = north;\n            north = tmp;\n        } else if (dir\
    \ == 'E') {\n            int tmp = top;\n            top = west;\n           \
    \ west = bottom;\n            bottom = east;\n            east = tmp;\n      \
    \  } else if (dir == 'W') {\n            int tmp = top;\n            top = east;\n\
    \            east = bottom;\n            bottom = west;\n            west = tmp;\n\
    \        } else if (dir == 'S') {\n            int tmp = top;\n            top\
    \ = north;\n            north = bottom;\n            bottom = south;\n       \
    \     south = tmp;\n        } else {\n            assert(false);\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n\n/**\n * @brief Die\n */\nstruct Die {\n\
    \    int top = 1, south = 2, east = 3, west = 4, north = 5, bottom = 6;\n\n  \
    \  void roll(char dir) {\n        if (dir == 'N') {\n            int tmp = top;\n\
    \            top = south;\n            south = bottom;\n            bottom = north;\n\
    \            north = tmp;\n        } else if (dir == 'E') {\n            int tmp\
    \ = top;\n            top = west;\n            west = bottom;\n            bottom\
    \ = east;\n            east = tmp;\n        } else if (dir == 'W') {\n       \
    \     int tmp = top;\n            top = east;\n            east = bottom;\n  \
    \          bottom = west;\n            west = tmp;\n        } else if (dir ==\
    \ 'S') {\n            int tmp = top;\n            top = north;\n            north\
    \ = bottom;\n            bottom = south;\n            south = tmp;\n        }\
    \ else {\n            assert(false);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/die.hpp
  requiredBy: []
  timestamp: '2025-01-11 16:44:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/die.hpp
layout: document
redirect_from:
- /library/misc/die.hpp
- /library/misc/die.hpp.html
title: Die
---
