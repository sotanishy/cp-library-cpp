# Fast Fourier Transform

A fast Fourier Transform (FFT) is an algorithm for computing the discrete Fourier transform of a sequence, and it is used for efficiently calculating the convolution of two sequences.

This struct uses the Cooley-Tukey algorithm to compute the FFT of a sequence.

## Member functions

- `template <typename T> static vector<double> convolution(const vector<T>& a, const vector<T>& b)`
    - Calculates the convolution of `a` and `b`.
    - Time complexity: $O(n\lg n)$