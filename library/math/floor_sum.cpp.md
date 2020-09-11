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


# :warning: math/floor_sum.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/floor_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:56:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

long long floor_sum(long long n, long long m, long long a, long long b) {
    long long sum = 0;
    if (a >= m) {
        sum += (a / m) * n * (n - 1) / 2;
        a %= m;
    }
    if (b >= m) {
        sum += (b / m) * n;
        b %= m;
    }
    long long y = (a * n + b) / m;
    if (y == 0) return sum;
    long long x = (m * y - b + a - 1) / a;
    sum += (n - x) * y + floor_sum(y, a, m, a * x - m * y + b);
    return sum;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/floor_sum.cpp"
#include <bits/stdc++.h>
using namespace std;

long long floor_sum(long long n, long long m, long long a, long long b) {
    long long sum = 0;
    if (a >= m) {
        sum += (a / m) * n * (n - 1) / 2;
        a %= m;
    }
    if (b >= m) {
        sum += (b / m) * n;
        b %= m;
    }
    long long y = (a * n + b) / m;
    if (y == 0) return sum;
    long long x = (m * y - b + a - 1) / a;
    sum += (n - x) * y + floor_sum(y, a, m, a * x - m * y + b);
    return sum;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

