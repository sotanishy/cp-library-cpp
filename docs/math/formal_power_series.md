## Description

形式的べき級数を扱う．

空間計算量: $O(n)$

## Operations

- `FPS inv(int deg)`
    - $\frac{1}{f(x)}$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `FPS exp(int deg)`
    - $\exp(f(x))$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `FPS log(int deg)`
    - $\log(f(x))$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `FPS pow(long long k, int deg)`
    - $(f(x))^k$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$

## Reference

- [【競技プログラミング】形式的冪級数の応用テクニック(前編)](https://qiita.com/hotman78/items/f0e6d2265badd84d429a)

