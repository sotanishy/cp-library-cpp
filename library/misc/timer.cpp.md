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


# :warning: misc/timer.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bc957e26ff41470c556ee5d09e96880b">misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/misc/timer.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Timer {
    chrono::steady_clock::time_point start_time;

    void start() {
        start_time = chrono::steady_clock::now();
    }

    long long get_time() {
        auto cur_time = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "misc/timer.cpp"
#include <bits/stdc++.h>
using namespace std;

struct Timer {
    chrono::steady_clock::time_point start_time;

    void start() {
        start_time = chrono::steady_clock::now();
    }

    long long get_time() {
        auto cur_time = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

