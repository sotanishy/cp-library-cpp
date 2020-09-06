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


# :heavy_check_mark: math/prime_factor.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime_factor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_A.test.cpp.html">test/aoj/NTL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

map<long long, int> prime_factor(long long n) {
    map<long long, int> ret;
    if (n % 2 == 0) {
        int cnt = 0;
        while (n % 2 == 0) {
            cnt++;
            n /= 2;
        }
        ret[2] = cnt;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ret[i] = cnt;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime_factor.cpp"
#include <bits/stdc++.h>
using namespace std;

map<long long, int> prime_factor(long long n) {
    map<long long, int> ret;
    if (n % 2 == 0) {
        int cnt = 0;
        while (n % 2 == 0) {
            cnt++;
            n /= 2;
        }
        ret[2] = cnt;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ret[i] = cnt;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

