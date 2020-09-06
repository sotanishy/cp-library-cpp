---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/mod_log.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/mod_log.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Depends on

* :heavy_check_mark: <a href="mod_pow.cpp.html">math/mod_pow.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "mod_pow.cpp"
using namespace std;

// returns x such that a^x = b (mod p)
int mod_log(long long a, long long b, long long p) {
    int m = sqrt(p) + 1;
    vector<long long> baby(m);
    unordered_map<long long, int> baby_index;
    long long x = 1;
    for (int i = 0; i < m; i++) {
        baby[i] = x;
        baby_index[x] = i;
        x = x * a % p;
    }

    vector<long long> giant(m);
    long long c = mod_inv(mod_pow(a, m, p), p);
    x = 1;
    for (int i = 0; i < m; i++) {
        giant[i] = x;
        x = x * c % p;
    }

    for (int i = 0; i < m; i++) {
        long long y = b * giant[i] % p;
        if (baby_index.count(y) > 0) {
            return i * m + baby_index[y];
        }
    }
    return -1;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/mod_log.cpp"
#include <bits/stdc++.h>
#line 2 "math/mod_pow.cpp"
using namespace std;

long long mod_pow(long long n, long long p, long long mod) {
    long long ret = 1;
    while (p > 0) {
        if (p & 1) ret = ret * n % mod;
        n = n * n % mod;
        p >>= 1;
    }
    return ret;
}

long long mod_inv(long long n, long long mod) {
    return mod_pow(n, mod - 2, mod);
}
#line 3 "math/mod_log.cpp"
using namespace std;

// returns x such that a^x = b (mod p)
int mod_log(long long a, long long b, long long p) {
    int m = sqrt(p) + 1;
    vector<long long> baby(m);
    unordered_map<long long, int> baby_index;
    long long x = 1;
    for (int i = 0; i < m; i++) {
        baby[i] = x;
        baby_index[x] = i;
        x = x * a % p;
    }

    vector<long long> giant(m);
    long long c = mod_inv(mod_pow(a, m, p), p);
    x = 1;
    for (int i = 0; i < m; i++) {
        giant[i] = x;
        x = x * c % p;
    }

    for (int i = 0; i < m; i++) {
        long long y = b * giant[i] % p;
        if (baby_index.count(y) > 0) {
            return i * m + baby_index[y];
        }
    }
    return -1;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

