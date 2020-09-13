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


# :warning: Fast Fourier Transform <small>(math/fft.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/fft.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:34:00+09:00




# Fast Fourier Transform

A fast Fourier Transform (FFT) is an algorithm for computing the discrete Fourier transform of a sequence, and it is used for efficiently calculating the convolution of two sequences.

This struct uses the Cooley-Tukey algorithm to compute the FFT of a sequence.

## Member functions

- `template <typename T> static vector<double> convolution(const vector<T>& a, const vector<T>& b)`
    - Calculates the convolution of `a` and `b`.
    - Time complexity: $O(n\lg n)$

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fast Fourier Transform
 * @docs docs/math/fft.md
 */
struct FFT {
private:
    inline static const double PI = acos(-1);

    struct C {
        double real, imag;
        C() : real(0), imag(0) {}
        C(double real, double imag) : real(real), imag(imag) {}
        C operator+(const C& c) { return C(real + c.real, imag + c.imag); }
        C operator-(const C& c) { return C(real - c.real, imag - c.imag); }
        C operator*(const C& c) { return C(real * c.real - imag * c.imag, real * c.imag + imag * c.real); }
    };

    static void ufft(vector<C>& a) {
        int n = a.size();
        for (int m = n; m > 1; m >>= 1) {
            double ang = 2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; s++) {
                C w(1, 0);
                for (int i = 0; i < m / 2; i++) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2];
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = (l - r) * w;
                    w = w * omega;
                }
            }
        }
    }

    static void iufft(vector<C>& a) {
        int n = a.size();
        for (int m = 2; m <= n; m <<= 1) {
            double ang = -2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; s++) {
                C w(1, 0);
                for (int i = 0; i < m / 2; i++) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2] * w;
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = l - r;
                    w = w * omega;
                }
            }
        }
    }

public:
    template <typename T>
    static vector<double> convolution(const vector<T>& a, const vector<T>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        vector<C> na(n), nb(n);
        for (int i = 0; i < a.size(); i++) na[i].real = a[i];
        for (int i = 0; i < b.size(); i++) nb[i].real = b[i];
        ufft(na);
        ufft(nb);
        for (int i = 0; i < n; i++) na[i] = na[i] * nb[i];
        iufft(na);
        vector<double> ret(size);
        for (int i = 0; i < size; i++) ret[i] = na[i].real / n;
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

/*
 * @brief Fast Fourier Transform
 * @docs docs/math/fft.md
 */
struct FFT {
private:
    inline static const double PI = acos(-1);

    struct C {
        double real, imag;
        C() : real(0), imag(0) {}
        C(double real, double imag) : real(real), imag(imag) {}
        C operator+(const C& c) { return C(real + c.real, imag + c.imag); }
        C operator-(const C& c) { return C(real - c.real, imag - c.imag); }
        C operator*(const C& c) { return C(real * c.real - imag * c.imag, real * c.imag + imag * c.real); }
    };

    static void ufft(vector<C>& a) {
        int n = a.size();
        for (int m = n; m > 1; m >>= 1) {
            double ang = 2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; s++) {
                C w(1, 0);
                for (int i = 0; i < m / 2; i++) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2];
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = (l - r) * w;
                    w = w * omega;
                }
            }
        }
    }

    static void iufft(vector<C>& a) {
        int n = a.size();
        for (int m = 2; m <= n; m <<= 1) {
            double ang = -2.0 * PI / m;
            C omega(cos(ang), sin(ang));
            for (int s = 0; s < n / m; s++) {
                C w(1, 0);
                for (int i = 0; i < m / 2; i++) {
                    C l = a[s * m + i];
                    C r = a[s * m + i + m / 2] * w;
                    a[s * m + i] = l + r;
                    a[s * m + i + m / 2] = l - r;
                    w = w * omega;
                }
            }
        }
    }

public:
    template <typename T>
    static vector<double> convolution(const vector<T>& a, const vector<T>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        vector<C> na(n), nb(n);
        for (int i = 0; i < a.size(); i++) na[i].real = a[i];
        for (int i = 0; i < b.size(); i++) nb[i].real = b[i];
        ufft(na);
        ufft(nb);
        for (int i = 0; i < n; i++) na[i] = na[i] * nb[i];
        iufft(na);
        vector<double> ret(size);
        for (int i = 0; i < size; i++) ret[i] = na[i].real / n;
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

