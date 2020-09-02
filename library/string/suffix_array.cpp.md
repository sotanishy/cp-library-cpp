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


# :heavy_check_mark: string/suffix_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/suffix_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 15:53:19+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_B.test.cpp.html">test/aoj/ALDS1_14_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    vector<int> sa;
    const string s;

    SuffixArray(const string& str) : s(str) {
        int n = s.size();
        sa.resize(n);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int i, int j) {
            return s[i] == s[j] ? i > j : s[i] < s[j];
        });
        int cl = 0;
        vector<int> rank(n);
        for (int i = 1; i < n; i++) {
            if (s[sa[i-1]] != s[sa[i]]) cl++;
            rank[sa[i]] = cl;
        }
        vector<int> tmp(n), nrank(n), cnt(n);
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i++) {
                tmp[i] = sa[i] - k;
                if (tmp[i] < 0) tmp[i] += n;
            }
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; i++) cnt[rank[tmp[i]]]++;
            for (int i = 1; i < n; i++) cnt[i] += cnt[i-1];
            for (int i = n - 1; i >= 0; i--) sa[--cnt[rank[tmp[i]]]] = tmp[i];
            nrank[sa[0]] = 0;
            cl = 0;
            for (int i = 1; i < n; i++) {
                if (rank[sa[i-1]] != rank[sa[i]] || rank[(sa[i-1] + k) % n] != rank[(sa[i] + k) % n]) {
                    cl++;
                }
                nrank[sa[i]] = cl;
            }
            swap(rank, nrank);
        }
    }

    int operator[](int k) const {
        return sa[k];
    }

    bool lt_substr(const string& t, int si = 0, int ti = 0) {
        int sn = s.size(), tn = t.size();
        while (si < sn && ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            si++;
            ti++;
        }
        return si >= sn && ti < tn;
    }

    int lower_bound(const string& t) {
        int lb = -1, ub = sa.size();
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (lt_substr(t, sa[m])) lb = m;
            else ub = m;
        }
        return ub;
    }

    int upper_bound(string& t) {
        t.back()++;
        int i = lower_bound(t);
        t.back()--;
        return i;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/suffix_array.cpp"
#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    vector<int> sa;
    const string s;

    SuffixArray(const string& str) : s(str) {
        int n = s.size();
        sa.resize(n);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int i, int j) {
            return s[i] == s[j] ? i > j : s[i] < s[j];
        });
        int cl = 0;
        vector<int> rank(n);
        for (int i = 1; i < n; i++) {
            if (s[sa[i-1]] != s[sa[i]]) cl++;
            rank[sa[i]] = cl;
        }
        vector<int> tmp(n), nrank(n), cnt(n);
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i++) {
                tmp[i] = sa[i] - k;
                if (tmp[i] < 0) tmp[i] += n;
            }
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; i++) cnt[rank[tmp[i]]]++;
            for (int i = 1; i < n; i++) cnt[i] += cnt[i-1];
            for (int i = n - 1; i >= 0; i--) sa[--cnt[rank[tmp[i]]]] = tmp[i];
            nrank[sa[0]] = 0;
            cl = 0;
            for (int i = 1; i < n; i++) {
                if (rank[sa[i-1]] != rank[sa[i]] || rank[(sa[i-1] + k) % n] != rank[(sa[i] + k) % n]) {
                    cl++;
                }
                nrank[sa[i]] = cl;
            }
            swap(rank, nrank);
        }
    }

    int operator[](int k) const {
        return sa[k];
    }

    bool lt_substr(const string& t, int si = 0, int ti = 0) {
        int sn = s.size(), tn = t.size();
        while (si < sn && ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            si++;
            ti++;
        }
        return si >= sn && ti < tn;
    }

    int lower_bound(const string& t) {
        int lb = -1, ub = sa.size();
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (lt_substr(t, sa[m])) lb = m;
            else ub = m;
        }
        return ub;
    }

    int upper_bound(string& t) {
        t.back()++;
        int i = lower_bound(t);
        t.back()--;
        return i;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

