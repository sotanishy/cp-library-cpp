# 2-SAT

This struct solves the 2-satisfiability (2-SAT) problem in conjunctive normal form (CNF).

A 2-SAT can be solved with SCC decomposition, using the fact that a clause $(u \lor v)$ is logically equivalent to $(\lnot u \implies v) \land (\lnot v \implies u)$.

Space complexity: $O(n + m)$, where $n$ is the number of variables and $m$ is the number of clauses.

## Attributes

- `bool satisfiable`
    - `true` if the given problem is satisfiable, otherwise `false`.

## Methods

- `TwoSat(int n)`
    - Initializes the struct with $n$ variables.
- `void add_clause(int u, bool a, int v, bool b)`
    - Adds a clause $(u \lor v)$. If `a == false`, replace $u$ with $\lnot u$. Similarly, if `b == false`, replace $v$ with $\lnot v$.
    - Time complexity: $O(1)$
- `void solve()`
    - Solves the given problem.
    - Time complexity: $O(n + m)$
- `bool operator[](int i)`
    - Returns the truth value of the $i$th variable if `satisfiable == true`
    - Time complexity: $O(1)$