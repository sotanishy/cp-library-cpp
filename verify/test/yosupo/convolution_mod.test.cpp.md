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


# :heavy_check_mark: test/yosupo/convolution_mod.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/convolution_mod.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:34:00+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/ntt.cpp.html">Number Theoretic Transform <small>(math/ntt.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../math/ntt.cpp"

using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(N), b(M);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];
    vector<ll> c = NTT<998244353, 3>::convolution(a, b);
    for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i < N + M - 2 ? " " : "\n");
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/convolution_mod.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#line 1 "math/ntt.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Number Theoretic Transform
 * @docs docs/math/ntt.md
 */
template <long long mod, long long primitive_root>
struct NTT {
private:
    static long long mod_pow(long long n, long long p) {
        long long ret = 1;
        while (p > 0) {
            if (p & 1) ret = ret * n % mod;
            n = n * n % mod;
            p >>= 1;
        }
        return ret;
    }

    static pair<long long, long long> extgcd(long long a, long long b) {
        long long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;
        while (t) {
            long long q = s / t;
            s -= t * q;
            swap(s, t);
            sx -= tx * q;
            swap(sx, tx);
            sy -= ty * q;
            swap(sy, ty);
        }
        return {sx, sy};
    }

    static long long mod_inv(long long a) {
        long long inv = extgcd(a, mod).first;
        return (inv % mod + mod) % mod;
    }

    static void untt(vector<long long>& a) {
        int n = a.size();
        for (int m = n; m > 1; m >>= 1) {
            long long omega = mod_pow(primitive_root, (mod - 1) * mod_inv(m) % mod);
            for (int s = 0; s < n / m; s++) {
                long long w = 1;
                for (int i = 0; i < m / 2; i++) {
                    long long l = a[s * m + i];
                    long long r = a[s * m + i + m / 2];
                    a[s * m + i] = (l + r) % mod;
                    a[s * m + i + m / 2] = (l - r + mod) * w % mod;
                    w = w * omega % mod;
                }
            }
        }
    }

    static void iuntt(vector<long long>& a) {
        int n = a.size();
        for (int m = 2; m <= n; m <<= 1) {
            long long omega = mod_inv(mod_pow(primitive_root, (mod - 1) * mod_inv(m) % mod));
            for (int s = 0; s < n / m; s++) {
                long long w = 1;
                for (int i = 0; i < m / 2; i++) {
                    long long l = a[s * m + i];
                    long long r = a[s * m + i + m / 2] * w % mod;
                    a[s * m + i] = (l + r) % mod;
                    a[s * m + i + m / 2] = (l - r + mod) % mod;
                    w = w * omega % mod;
                }
            }
        }
    }


public:
    static vector<long long> convolution(const vector<long long>& a, const vector<long long>& b) {
        int size = a.size() + b.size() - 1;
        int n = 1;
        while (n < size) n <<= 1;
        vector<long long> na = a, nb = b;
        na.resize(n);
        nb.resize(n);
        untt(na);
        untt(nb);
        for (int i = 0; i < n; i++) na[i] = na[i] * nb[i] % mod;
        iuntt(na);
        na.resize(size);
        long long n_inv = mod_inv(n);
        for (int i = 0; i < size; i++) na[i] = na[i] * n_inv % mod;
        return na;
    }
};

// <167772161, 3>
// <469762049, 3>
// <754974721, 11>
// <998244353, 3>
// <1224736769, 3>
#line 4 "test/yosupo/convolution_mod.test.cpp"

using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(N), b(M);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];
    vector<ll> c = NTT<998244353, 3>::convolution(a, b);
    for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i < N + M - 2 ? " " : "\n");
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

