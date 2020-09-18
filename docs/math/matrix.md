# Matrix

行列を表す．

絶対使わない機能ばかりついているので，使用するときは使う部分だけ残すとよい．また行列の積で mod を取る機能はついていないので，そこは自分でその都度実装する．

## Template parameters

- `T`
    - 行列の要素の型

## Constructor

- `Matrix(int m, int n)`
    - $m \times n$ 零行列を構築する
    - 時間計算量: $O(mn)$

- `Matrix(initializer_list<initializer_list<T>> list)`
    - `list` の要素で行列を構築する
    - 時間計算量: $O(mn)$

## Member functions

- `static Matrix I(int n)`
    - $n \times n$ 単位行列を返す
    - 時間計算量: $O(n^2)$

- `static Matrix concatenate(const Matrix& A, const Matrix& B)`
    - $A$ と $B$ を結合した行列を返す
    - 時間計算量: $O(mn_A n_B)$

- `Matrix transpose()`
    - 転置行列を返す
    - 時間計算量: $O(mn)$

- `Matrix matmul(const Matrix& B)`
    - 行列積 $AB$ を返す
    - 時間計算量: $O(m_A n_A n_B)$

- `Matrix pow(long long k)`
    - $A^k$ を返す
    - 時間計算量: $O(n^3 \lg k)$

- `Matrix rref()`
    - $A$ に対して掃き出し法を行った結果を返す
    - 時間計算量: $O(mn^2)$

- `T det()`
    - 行列式 $|A|$ を返す
    - 時間計算量: $O(mn^2)$

- `int rank()`
    - $A$ の階数を返す
    - 時間計算量: $O(mn^2)$

- `Matrix inverse()`
    - 逆行列 $A^{-1}$ を返す
    - 時間計算量: $O(mn^2)$