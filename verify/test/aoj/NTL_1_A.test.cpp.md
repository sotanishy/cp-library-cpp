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


# :heavy_check_mark: test/aoj/NTL_1_A.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:54:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/prime_factor.cpp.html">math/prime_factor.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include "../../math/prime_factor.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << n << ":";
    auto prime = prime_factor(n);
    for (auto& p : prime) {
        for (int i = 0; i < p.second; i++) cout << " " << p.first;
    }
    cout << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_A.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

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
#line 4 "test/aoj/NTL_1_A.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << n << ":";
    auto prime = prime_factor(n);
    for (auto& p : prime) {
        for (int i = 0; i < p.second; i++) cout << " " << p.first;
    }
    cout << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

