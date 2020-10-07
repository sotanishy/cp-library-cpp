---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Persistent Stack
    links: []
  bundledCode: "#line 1 \"data-structure/persistent_stack.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Persistent Stack\n */\ntemplate <typename T>\nclass PersistentStack\
    \ {\npublic:\n    PersistentStack() = default;\n\n    T top() const {\n      \
    \  return last->val;\n    }\n\n    PersistentStack push(const T& val) const {\n\
    \        return PersistentStack(std::make_shared<Node>(val, last));\n    }\n\n\
    \    PersistentStack pop() const {\n        return PersistentStack(last->prev);\n\
    \    }\n\nprivate:\n    struct Node {\n        T val;\n        std::shared_ptr<Node>\
    \ prev;\n    };\n\n    std::shared_ptr<Node> last;\n\n    explicit PersistentStack(std::shared_ptr<Node>\
    \ last) : last(last) {}\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Persistent Stack\n */\ntemplate\
    \ <typename T>\nclass PersistentStack {\npublic:\n    PersistentStack() = default;\n\
    \n    T top() const {\n        return last->val;\n    }\n\n    PersistentStack\
    \ push(const T& val) const {\n        return PersistentStack(std::make_shared<Node>(val,\
    \ last));\n    }\n\n    PersistentStack pop() const {\n        return PersistentStack(last->prev);\n\
    \    }\n\nprivate:\n    struct Node {\n        T val;\n        std::shared_ptr<Node>\
    \ prev;\n    };\n\n    std::shared_ptr<Node> last;\n\n    explicit PersistentStack(std::shared_ptr<Node>\
    \ last) : last(last) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent_stack.cpp
  requiredBy: []
  timestamp: '2020-10-08 02:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/persistent_stack.cpp
layout: document
redirect_from:
- /library/data-structure/persistent_stack.cpp
- /library/data-structure/persistent_stack.cpp.html
title: Persistent Stack
---
