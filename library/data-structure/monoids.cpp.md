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


# :warning: data-structure/monoids.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/monoids.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 16:31:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

// monoids

struct AddMonoid {
    using T = int;
    static inline T id = 0;
    static T op(T a, T b) {
        return a + b;
    }
};

struct MinMonoid {
    using T = int;
    static inline T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return min(a, b);
    }
};

struct AddRangeMonoid {
    using T = pair<int, int>;
    static inline T id = {0, 0};
    static T op(T a, T b) {
        return {a.first + b.first, a.second + b.second};
    }
};

struct UpdateMonoid {
    using T = int;
    static inline T id = -1;
    static T op(T a, T b) {
        return b;
    }
};

struct AffineMonoid {
    using T = pair<int, int>;
    static inline T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

// actions

AddRangeMonoid::T act(AddRangeMonoid::T a, AffineMonoid::T b) {
    return {a.first * b.first + a.second * b.second, a.second};
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/monoids.cpp"
#include <bits/stdc++.h>
using namespace std;

// monoids

struct AddMonoid {
    using T = int;
    static inline T id = 0;
    static T op(T a, T b) {
        return a + b;
    }
};

struct MinMonoid {
    using T = int;
    static inline T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return min(a, b);
    }
};

struct AddRangeMonoid {
    using T = pair<int, int>;
    static inline T id = {0, 0};
    static T op(T a, T b) {
        return {a.first + b.first, a.second + b.second};
    }
};

struct UpdateMonoid {
    using T = int;
    static inline T id = -1;
    static T op(T a, T b) {
        return b;
    }
};

struct AffineMonoid {
    using T = pair<int, int>;
    static inline T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

// actions

AddRangeMonoid::T act(AddRangeMonoid::T a, AffineMonoid::T b) {
    return {a.first * b.first + a.second * b.second, a.second};
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

