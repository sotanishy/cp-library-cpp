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


# :warning: math/combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Depends on

* :warning: <a href="mod_pow.cpp.html">math/mod_pow.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "mod_pow.cpp"
using namespace std;

long long comb(int n, int k, int mod) {
    long long num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = num * (n-i) % mod;
        den = den * (i+1) % mod;
    }
    return num * mod_inv(den, mod) % mod;
}

void comb(int n, int mod) {
    vector<long long> fact(n+1, 1), fact_inv(n+1, 1);
    for (long long i = 1; i <= n; i++) {
        fact[i] = i * fact[i-1] % mod;
    }
    fact_inv[n] = mod_inv(fact[n], mod);
    for (long long i = n; i > 0; i--) {
        fact_inv[i-1] = i * fact_inv[i] % mod;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/combination.cpp"
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
#line 3 "math/combination.cpp"
using namespace std;

long long comb(int n, int k, int mod) {
    long long num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = num * (n-i) % mod;
        den = den * (i+1) % mod;
    }
    return num * mod_inv(den, mod) % mod;
}

void comb(int n, int mod) {
    vector<long long> fact(n+1, 1), fact_inv(n+1, 1);
    for (long long i = 1; i <= n; i++) {
        fact[i] = i * fact[i-1] % mod;
    }
    fact_inv[n] = mod_inv(fact[n], mod);
    for (long long i = n; i > 0; i--) {
        fact_inv[i-1] = i * fact_inv[i] % mod;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

