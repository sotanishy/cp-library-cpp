---
title: Fast Fourier Transform
documentation_of: ../../math/fft.cpp
---

## Description

高速フーリエ変換 (FFT) は数列の離散フーリエ変換を計算するアルゴリズムであり，2つの数列の畳み込みを高速に計算するのに用いられる．

この実装では Cooley-Tukey のアルゴリズムを用いている．

## Operations

- `static vector<double> convolve(vector<T> a, vector<T> b)`
    - $a$ と $b$ の畳み込みを計算する
    - 時間計算量: $O(n\lg n)$
- `static void fft(vector<complex<double>> a, bool ordered)`
    - $a$ を高速フーリエ変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\lg n)$
- `static void ifft(vector<complex<double>> a, bool ordered)`
    - $a$ を逆高速フーリエ変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\lg n)$