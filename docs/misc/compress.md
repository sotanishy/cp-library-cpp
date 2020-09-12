# Coordinate Compression

This struct compresses a list of values into a list of integers less than the size of the list.

Space complexity: $O(n)$

## Methods

- `Compress(const vector<T>& vs)`
    - Compresses the given list `vs`
    - Time complexity: $O(n \lg n)$
- `int compress(const T& x)`
    - Compresses the value into an integer less than $n$
    - Time complexity: $O(\lg n)$
- `T decompress(int i)`
    - Converts the compressed value into the original value.
    - Time complexity: $O(1)$