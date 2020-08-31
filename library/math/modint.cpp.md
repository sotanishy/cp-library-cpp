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


# :warning: math/modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod)) {}

    ModInt &operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt& p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) *= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u - t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(long long n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream &operator>>(istream& is, ModInt& a) {
        long long t;
        is >> t;
        a = ModInt<mod>(t);
        return is;
    }

    static int get_mod() { return mod; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modint.cpp"
#include <bits/stdc++.h>
using namespace std;

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod)) {}

    ModInt &operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt& p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) *= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u - t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(long long n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream &operator>>(istream& is, ModInt& a) {
        long long t;
        is >> t;
        a = ModInt<mod>(t);
        return is;
    }

    static int get_mod() { return mod; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

