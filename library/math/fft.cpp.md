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


# :warning: math/fft.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/fft.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 20:23:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct FFT {
private:
    inline static const double PI = acos(-1);

    static void dft(vector<complex<double>>& f, int sign) {
        int n = f.size();
        if (n == 1) return;
        vector<complex<double>> a, b;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(f[2 * i]);
            b.push_back(f[2 * i + 1]);
        }
        dft(a, sign);
        dft(b, sign);
        complex<double> cur = 1, zeta = polar(1.0, sign * 2.0 * PI / n);
        for (int i = 0; i < n; i++) {
            f[i] = a[i % (n / 2)] + cur * b[i % (n / 2)];
            cur *= zeta;
        }
    }

public:
    template <typename T>
    static vector<double> convolution(const vector<T>& a, const vector<T>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        vector<complex<double>> na(n), nb(n);
        for (int i = 0; i < a.size(); i++) {
            na[i] = a[i];
            nb[i] = b[i];
        }
        dft(na, 1);
        dft(nb, 1);
        for (int i = 0; i < n; i++) na[i] *= nb[i];
        dft(na, -1);
        vector<double> ret(size);
        for (int i = 0; i < size; i++) ret[i] = na[i].real() / n;
        return ret;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/fft.cpp"
#include <bits/stdc++.h>
using namespace std;

struct FFT {
private:
    inline static const double PI = acos(-1);

    static void dft(vector<complex<double>>& f, int sign) {
        int n = f.size();
        if (n == 1) return;
        vector<complex<double>> a, b;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(f[2 * i]);
            b.push_back(f[2 * i + 1]);
        }
        dft(a, sign);
        dft(b, sign);
        complex<double> cur = 1, zeta = polar(1.0, sign * 2.0 * PI / n);
        for (int i = 0; i < n; i++) {
            f[i] = a[i % (n / 2)] + cur * b[i % (n / 2)];
            cur *= zeta;
        }
    }

public:
    template <typename T>
    static vector<double> convolution(const vector<T>& a, const vector<T>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        vector<complex<double>> na(n), nb(n);
        for (int i = 0; i < a.size(); i++) {
            na[i] = a[i];
            nb[i] = b[i];
        }
        dft(na, 1);
        dft(nb, 1);
        for (int i = 0; i < n; i++) na[i] *= nb[i];
        dft(na, -1);
        vector<double> ret(size);
        for (int i = 0; i < size; i++) ret[i] = na[i].real() / n;
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

