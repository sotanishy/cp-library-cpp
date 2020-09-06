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


# :heavy_check_mark: test/aoj/ALDS1_1_C.is_prime.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_1_C.is_prime.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:54:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/is_prime.cpp.html">math/is_prime.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include "../../math/is_prime.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (is_prime(a)) ans++;
    }
    cout << ans << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_1_C.is_prime.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#line 1 "math/is_prime.cpp"
#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    if (n < 9) return true;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
#line 4 "test/aoj/ALDS1_1_C.is_prime.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (is_prime(a)) ans++;
    }
    cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

