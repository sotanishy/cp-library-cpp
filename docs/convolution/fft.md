---
title: Fast Fourier Transform
documentation_of: ../../convolution/fft.hpp
---

## Description

高速 Fourier 変換 (FFT) は数列の離散 Fourier 変換を計算するアルゴリズムであり，2つの数列の畳み込みを高速に計算するのに用いられる．

この実装では Cooley-Tukey のアルゴリズムを用いている．

## Operations

- `void fft(vector<complex<double>> a)`
    - 数列 $a$ を高速 Fourier 変換する
    - 時間計算量: $O(n\log n)$
- `void ifft(vector<complex<double>> a)`
    - 数列 $a$ を逆高速 Fourier 変換する
    - 時間計算量: $O(n\log n)$
- `vector<double> convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の畳み込みを計算する
    - 時間計算量: $O(n\log n)$