# Segment Tree

A segment tree stores a sequence $(a_0, a_1, \dots, a_n)$ of a monoid $M$.

See the note for how to use the template argument.

A segment tree supports point update and range query both in $O(\lg n)$ time.

For range update and point query, use [a dual segment tree](dual_segment_tree.md)

For range update and range query, use [a segment tree with lazy propagation](lazy_segment_tree.md)

Space complexity: $O(n)$

## Methods

- `SegmentTree(int n)`
    - Constructs a segment tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$
- `SegmentTree(const vector<T>& v)`
    - Constructs a segment tree of size `v.size()` using the given sequence.
    - Time complexity: $O(n)$
- `T operator[](int k)`
    - Returns $a_k$.
    - Time complexity: $O(1)$
- `void update(int k, const T& x)`
    - Sets $a_k$ to $x$.
    - Time complexity: $O(\lg n)$
- `T query(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(\lg n)$
- `int find_first(int l, const function<bool(T)>& cond)`
    - Returns the first index $r$ after $l$ such that $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ satisfies the condition `cond`. Returns `-1` if none found.
    - Time complexity: $O(\lg n)$
- `int find_last(int r, const function<bool(T)>& cond)`
    - Returns the last index $l$ before $r$ such that $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ satisfies the condition `cond`. Returns `-1` if none found.
    - Time complexity: $O(\lg n)$

## Note

The template argument `M` represents a monoid $M$ and is a class/struct with the following members defined:
* `T`: the type of the elements in $M$
* `T id`: the identity element $e$
* `T op(T, T)`: an associative binary operation $\cdot$

See the verify files for examples of implementation.