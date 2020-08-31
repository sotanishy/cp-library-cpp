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


# :warning: math/matrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    vector<vector<long long>> A;
    int m, n;

    Matrix(int m, int n) : A(m, vector<long long>(m)), m(m), n(n) {};

    Matrix(int n) : A(n, vector<long long>(n)), m(n), n(n) {};

    static Matrix I(int n) {
        Matrix ret(n);
        for (int i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
    }

    vector<long long> operator[](int i) const {
        return A[i];
    }

    Matrix operator+=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    Matrix operator-=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& B) {
        return Matrix(*this) += B;
    }

    Matrix operator-(const Matrix& B) {
        return Matrix(*this) -= B;
    }

    Matrix matmul(const Matrix& B, long long mod) {
        assert(n == B.m);
        Matrix C(m, B.n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < B.n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    Matrix pow(long long k, long long mod) {
        assert(m == n);
        Matrix ret = Matrix::I(n);
        Matrix B(*this);
        while (k > 0) {
            if (k & 1) ret = ret.matmul(B, mod);
            B = B.matmul(B, mod);
            k >>= 1LL;
        }
        return ret;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix.cpp"
#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    vector<vector<long long>> A;
    int m, n;

    Matrix(int m, int n) : A(m, vector<long long>(m)), m(m), n(n) {};

    Matrix(int n) : A(n, vector<long long>(n)), m(n), n(n) {};

    static Matrix I(int n) {
        Matrix ret(n);
        for (int i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
    }

    vector<long long> operator[](int i) const {
        return A[i];
    }

    Matrix operator+=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    Matrix operator-=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& B) {
        return Matrix(*this) += B;
    }

    Matrix operator-(const Matrix& B) {
        return Matrix(*this) -= B;
    }

    Matrix matmul(const Matrix& B, long long mod) {
        assert(n == B.m);
        Matrix C(m, B.n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < B.n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    Matrix pow(long long k, long long mod) {
        assert(m == n);
        Matrix ret = Matrix::I(n);
        Matrix B(*this);
        while (k > 0) {
            if (k & 1) ret = ret.matmul(B, mod);
            B = B.matmul(B, mod);
            k >>= 1LL;
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

