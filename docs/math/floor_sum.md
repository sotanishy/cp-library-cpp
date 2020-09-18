# Floor Sum

一次関数の床関数の和 $\sum_{i=0}^{N-1} \left\lfloor \frac{A*i + B}{M} \right\rfloor$ を再帰的に計算する．

計算量はユークリッドの互除法と同様に対数時間となるが，どの変数に依存するのかは考えていないのでよくわからない(考えろ)．

- `long long floor_sum(long long n, long long m, long long a, long long b)`