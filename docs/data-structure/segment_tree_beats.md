# Segment Tree Beats

A segment tree beats is a variant of a segment tree with lazy propagation that allows range chmin/chmax/add operations and range min/max/sum queries.

Space complexity: $O(n)$

## Template parameters

- `T`
    - The type of the elements.

## Constructor

- `SegmentTreeBeats(int n)`
    - Constructs a segment tree beats of size `n` with all elements set to 0.
    - Time complexity: $O(n)$
- `SegmentTreeBeats(const vector<T>& v)`
    - Constructs a segment tree beats of size `n = v.size()` using the values in `v`.
    - Time complexity: $O(n)$

## Member functions

- `T operator[](int k)`
    - Returns $a_k$.
    - Time complexity: $O(\lg^2 n)$
- `void chmin(int l, int r, T x)`
    - Sets $a_i$ to $min(a_i, x)$ for $i \in [l, r)$
    - Time complexity: $O(\lg^2 n)$
- `void chmax(int l, int r, T x)`
    - Sets $a_i$ to $max(a_i, x)$ for $i \in [l, r)$
    - Time complexity: $O(\lg^2 n)$
- `void add(int l, int r, T x)`
    - Sets $a_i$ to $a_i + x$ for $i \in [l, r)$
    - Time complexity: $O(\lg^2 n)$
- `T fold_min(int l, int r)`
    - Calculates $min(a_l, a_{l+1}, \cdots, a_{r-1})$.
    - Time complexity: $O(\lg^2 n)$
- `T fold_max(int l, int r)`
    - Calculates $max(a_l, a_{l+1}, \cdots, a_{r-1})$.
    - Time complexity: $O(\lg^2 n)$
- `T fold_sum(int l, int r)`
    - Calculates $a_l + a_{l+1} + \cdots + a_{r-1}$.
    - Time complexity: $O(\lg^2 n)$
