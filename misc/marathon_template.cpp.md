---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"misc/marathon_template.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <set>\n#include <unordered_set>\n#include <map>\n#include\
    \ <unordered_map>\n#include <cstdio>\n#include <bitset>\n#include <queue>\n#include\
    \ <deque>\n#include <algorithm>\n#include <numeric>\n#include <cassert>\n#include\
    \ <functional>\n#include <stack>\n#include <cmath>\n#include <string>\n#include\
    \ <chrono>\n\nusing namespace std;\nusing ll = long long;\n\nstruct Random {\n\
    \    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\
    \n    unsigned int xorshift() {\n        unsigned int t;\n        t = x ^ (x <<\
    \ 11);\n        x = y; y = z; z = w;\n        return w = w ^ (w >> 19) ^ (t ^\
    \ (t >> 8));\n    }\n\n    // returns a random integer in the range [0, n)\n \
    \   unsigned int next_int(unsigned int n) {\n        return xorshift() % n;\n\
    \    }\n\n    // returns a random double number in the range [0, 1)\n    double\
    \ next_double() {\n        return xorshift() * (1.0 / 0xFFFFFFFFu);\n    }\n}\
    \ rng;\n\nstruct Timer {\n    chrono::steady_clock::time_point start_time;\n\n\
    \    void start() {\n        start_time = chrono::steady_clock::now();\n    }\n\
    \n    long long get_time() {\n        auto cur_time = chrono::steady_clock::now();\n\
    \        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();\n\
    \    }\n} timer;\n\n/***************************************************************\n\
    \ * CODE BELOW\n ***************************************************************/\n\
    \n#define DEBUG\n\nstruct State {\n\n    ll score;\n\n    State() {\n\n    }\n\
    \n    void move() {\n\n    }\n\n    void move_back() {\n\n    }\n};\n\ndouble\
    \ accept(ll prev_score, ll cur_score, double temperature) {\n    if (prev_score\
    \ < cur_score) return 1.0;\n    return exp((double) (cur_score - prev_score) /\
    \ temperature);\n}\n\nState simulated_annealing(State& beginning_state, ll duration)\
    \ {\n\n    double temp_start = 2e3;\n    double temp_end = 6e2;\n    double temperature\
    \ = temp_start;\n\n    State cur_state = beginning_state;\n    State best_state\
    \ = cur_state;\n    int iter = 0;\n    ll cur_time = 0;\n    timer.start();\n\n\
    \    while (true) {\n        if (iter % 100 == 0) {\n            cur_time = timer.get_time();\n\
    \            if (cur_time > duration) break;\n            double t = (double)\
    \ cur_time / duration;\n            temperature = pow(temp_start, 1 - t) * pow(temp_end,\
    \ t);\n        }\n\n        #ifdef DEBUG\n        if (iter % 100000 == 0) cerr\
    \ << temperature << endl;\n        #endif\n\n        ll prev_score = cur_state.score;\n\
    \        cur_state.move();\n\n        if (accept(prev_score, cur_state.score,\
    \ temperature) > rng.next_double()) {\n            if (cur_state.score > best_state.score)\
    \ {\n                best_state = cur_state;\n            }\n        } else {\n\
    \            cur_state.move_back();\n        }\n\n        iter++;\n    }\n\n \
    \   #ifdef DEBUG\n    cerr << \"Iterations: \" << iter << endl;\n    #endif\n\n\
    \    return best_state;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n}\n"
  code: "#include <iostream>\n#include <vector>\n#include <set>\n#include <unordered_set>\n\
    #include <map>\n#include <unordered_map>\n#include <cstdio>\n#include <bitset>\n\
    #include <queue>\n#include <deque>\n#include <algorithm>\n#include <numeric>\n\
    #include <cassert>\n#include <functional>\n#include <stack>\n#include <cmath>\n\
    #include <string>\n#include <chrono>\n\nusing namespace std;\nusing ll = long\
    \ long;\n\nstruct Random {\n    unsigned int x = 123456789, y = 362436069, z =\
    \ 521288629, w = 88675123;\n\n    unsigned int xorshift() {\n        unsigned\
    \ int t;\n        t = x ^ (x << 11);\n        x = y; y = z; z = w;\n        return\
    \ w = w ^ (w >> 19) ^ (t ^ (t >> 8));\n    }\n\n    // returns a random integer\
    \ in the range [0, n)\n    unsigned int next_int(unsigned int n) {\n        return\
    \ xorshift() % n;\n    }\n\n    // returns a random double number in the range\
    \ [0, 1)\n    double next_double() {\n        return xorshift() * (1.0 / 0xFFFFFFFFu);\n\
    \    }\n} rng;\n\nstruct Timer {\n    chrono::steady_clock::time_point start_time;\n\
    \n    void start() {\n        start_time = chrono::steady_clock::now();\n    }\n\
    \n    long long get_time() {\n        auto cur_time = chrono::steady_clock::now();\n\
    \        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();\n\
    \    }\n} timer;\n\n/***************************************************************\n\
    \ * CODE BELOW\n ***************************************************************/\n\
    \n#define DEBUG\n\nstruct State {\n\n    ll score;\n\n    State() {\n\n    }\n\
    \n    void move() {\n\n    }\n\n    void move_back() {\n\n    }\n};\n\ndouble\
    \ accept(ll prev_score, ll cur_score, double temperature) {\n    if (prev_score\
    \ < cur_score) return 1.0;\n    return exp((double) (cur_score - prev_score) /\
    \ temperature);\n}\n\nState simulated_annealing(State& beginning_state, ll duration)\
    \ {\n\n    double temp_start = 2e3;\n    double temp_end = 6e2;\n    double temperature\
    \ = temp_start;\n\n    State cur_state = beginning_state;\n    State best_state\
    \ = cur_state;\n    int iter = 0;\n    ll cur_time = 0;\n    timer.start();\n\n\
    \    while (true) {\n        if (iter % 100 == 0) {\n            cur_time = timer.get_time();\n\
    \            if (cur_time > duration) break;\n            double t = (double)\
    \ cur_time / duration;\n            temperature = pow(temp_start, 1 - t) * pow(temp_end,\
    \ t);\n        }\n\n        #ifdef DEBUG\n        if (iter % 100000 == 0) cerr\
    \ << temperature << endl;\n        #endif\n\n        ll prev_score = cur_state.score;\n\
    \        cur_state.move();\n\n        if (accept(prev_score, cur_state.score,\
    \ temperature) > rng.next_double()) {\n            if (cur_state.score > best_state.score)\
    \ {\n                best_state = cur_state;\n            }\n        } else {\n\
    \            cur_state.move_back();\n        }\n\n        iter++;\n    }\n\n \
    \   #ifdef DEBUG\n    cerr << \"Iterations: \" << iter << endl;\n    #endif\n\n\
    \    return best_state;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/marathon_template.cpp
  requiredBy: []
  timestamp: '2020-09-14 04:40:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/marathon_template.cpp
layout: document
redirect_from:
- /library/misc/marathon_template.cpp
- /library/misc/marathon_template.cpp.html
title: misc/marathon_template.cpp
---
