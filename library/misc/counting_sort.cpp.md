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


# :warning: misc/counting_sort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bc957e26ff41470c556ee5d09e96880b">misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/misc/counting_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:18:51+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> counting_sort(vector<int>& v, int k) {
    vector<int> cnt(k+1);
    for (int i = 0; i < v.size(); i++) cnt[v[i]]++;
    for (int i = 1; i <= k; i++) cnt[i] += cnt[i-1];
    vector<int> ret(v.size());
    for (int i = v.size() - 1; i >= 0; i--) ret[--cnt[v[i]]] = v[i];
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "misc/counting_sort.cpp"
#include <bits/stdc++.h>
using namespace std;

vector<int> counting_sort(vector<int>& v, int k) {
    vector<int> cnt(k+1);
    for (int i = 0; i < v.size(); i++) cnt[v[i]]++;
    for (int i = 1; i <= k; i++) cnt[i] += cnt[i-1];
    vector<int> ret(v.size());
    for (int i = v.size() - 1; i >= 0; i--) ret[--cnt[v[i]]] = v[i];
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

