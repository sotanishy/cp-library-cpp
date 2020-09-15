# Fast Fourier Transform

高速フーリエ変換 (FFT) は数列の離散フーリエ変換を計算するアルゴリズムであり，2つの数列の畳み込みを高速に計算するのに用いられる．

この実装では Cooley-Tukey のアルゴリズムを用いている．

## Member functions

- `template <typename T> static vector<double> convolution(const vector<T>& a, const vector<T>& b)`
    - `a` と `b` の畳み込みを計算する
    - 時間計算量: $O(n\lg n)$