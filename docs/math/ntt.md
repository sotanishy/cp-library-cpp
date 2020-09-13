# Number Theoretic Transform

A number theoretic transform (NTT) is a fast Fourier transform (FFT) over the quotient ring $\mathbb{Z}/p\mathbb{Z}$.

## Template parameters

- `mod`
    - The modulus $p$.
- `primitive_root`
    - The primitive root modulo $p$.

## Member functions

- `static vector<long long> convolution(const vector<long long>& a, const vector<long long>& b)`
    - Calculates the convolution of `a` and `b` mod $p$.
    - Time complexity: $O(n\lg n)$

## Note

Some good pairs of `mod` and `primitive_root` are:
- <167772161, 3>
- <469762049, 3>
- <754974721, 11>
- <998244353, 3>
- <1224736769, 3>