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


# :x: test/aoj/ALDS1_1_C.sieve.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_1_C.sieve.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 04:06:39+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C</a>


## Depends on

* :x: <a href="../../../library/math/sieve.cpp.html">math/sieve.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include "../../math/sieve.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto prime = sieve(100000000);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (prime[a]) ans++;
    }
    cout << ans << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_1_C.sieve.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

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
#line 4 "test/aoj/ALDS1_1_C.sieve.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto prime = sieve(100000000);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (prime[a]) ans++;
    }
    cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

