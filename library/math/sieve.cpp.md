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


# :x: math/sieve.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Verified with

* :x: <a href="../../verify/test/aoj/ALDS1_1_C.sieve.test.cpp.html">test/aoj/ALDS1_1_C.sieve.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int j = 4; j <= n; j += 2) prime[j] = false;
    for (int i = 3; i <= n; i += 2) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= n; j += 2 * i) prime[j] = false;
    }
    return prime;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/sieve.cpp"
#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int j = 4; j <= n; j += 2) prime[j] = false;
    for (int i = 3; i <= n; i += 2) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= n; j += 2 * i) prime[j] = false;
    }
    return prime;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

