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


# :warning: math/fast_fourier_transform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/fast_fourier_transform.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct FastFourierTransform {
private:
    static void dft(vector<complex<double>>& f, int inv) {
        int n = f.size();
        if (n == 1) return;
        vector<complex<double>> a, b;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(f[2 * i]);
            b.push_back(f[2 * i + 1]);
        }
        dft(a, inv);
        dft(b, inv);
        complex<double> cur = 1, zeta = polar(1.0, inv * 2.0 * acos(-1) / n);
        for (int i = 0; i < n; i++) {
            f[i] = a[i % (n / 2)] + cur * b[i % (n / 2)];
            cur *= zeta;
        }
    }

public:
    template <typename T>
    static vector<double> multiply(vector<T> f, vector<T> g) {
        int n = 1;
        while (n < f.size() + g.size()) n *= 2;
        vector<complex<double>> nf(n), ng(n);
        for (int i = 0; i < f.size(); i++) {
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf, 1);
        dft(ng, 1);
        for (int i = 0; i < n; i++) nf[i] *= ng[i];
        dft(nf, -1);
        vector<double> ret(n);
        for (int i = 0; i < n; i++) ret[i] = nf[i].real() / n;
        return ret;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/fast_fourier_transform.cpp"
#include <bits/stdc++.h>
using namespace std;

struct FastFourierTransform {
private:
    static void dft(vector<complex<double>>& f, int inv) {
        int n = f.size();
        if (n == 1) return;
        vector<complex<double>> a, b;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(f[2 * i]);
            b.push_back(f[2 * i + 1]);
        }
        dft(a, inv);
        dft(b, inv);
        complex<double> cur = 1, zeta = polar(1.0, inv * 2.0 * acos(-1) / n);
        for (int i = 0; i < n; i++) {
            f[i] = a[i % (n / 2)] + cur * b[i % (n / 2)];
            cur *= zeta;
        }
    }

public:
    template <typename T>
    static vector<double> multiply(vector<T> f, vector<T> g) {
        int n = 1;
        while (n < f.size() + g.size()) n *= 2;
        vector<complex<double>> nf(n), ng(n);
        for (int i = 0; i < f.size(); i++) {
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf, 1);
        dft(ng, 1);
        for (int i = 0; i < n; i++) nf[i] *= ng[i];
        dft(nf, -1);
        vector<double> ret(n);
        for (int i = 0; i < n; i++) ret[i] = nf[i].real() / n;
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

