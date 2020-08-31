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


# :warning: misc/random.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bc957e26ff41470c556ee5d09e96880b">misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/misc/random.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Random {
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;

    unsigned int xorshift() {
        unsigned int t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }

    // returns a random integer in the range [0, n)
    int next_int(int n) {
        return xorshift() % n;
    }

    // returns a random double number in the range [0, 1)
    double next_double() {
        return xorshift() * (1.0 / 0xFFFFFFFFu);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "misc/random.cpp"
#include <bits/stdc++.h>
using namespace std;

struct Random {
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;

    unsigned int xorshift() {
        unsigned int t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }

    // returns a random integer in the range [0, n)
    int next_int(int n) {
        return xorshift() % n;
    }

    // returns a random double number in the range [0, 1)
    double next_double() {
        return xorshift() * (1.0 / 0xFFFFFFFFu);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

