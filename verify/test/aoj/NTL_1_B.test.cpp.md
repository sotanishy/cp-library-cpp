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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/NTL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:54:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/mod_pow.cpp.html">math/mod_pow.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../math/mod_pow.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    cout << mod_pow(m, n, 1e9 + 7) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#line 1 "math/mod_pow.cpp"
#include <bits/stdc++.h>
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
#line 4 "test/aoj/NTL_1_B.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    cout << mod_pow(m, n, 1e9 + 7) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

