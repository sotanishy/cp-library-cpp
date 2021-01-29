// #define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

// #include "../../data-structure/bst/lazy_treap.cpp"
// #include "../../math/modint.cpp"

#include <bits/stdc++.h>
using namespace std;

template <typename M, typename O, typename M::T (*act)(typename M::T, typename O::T)>
class LazyTreap {
    using T = typename M::T;
    using E = typename O::T;

public:
    LazyTreap() = default;

    static LazyTreap join(LazyTreap l, LazyTreap r) {
        return LazyTreap(join(std::move(l.root), std::move(r.root)));
    }

    std::pair<LazyTreap, LazyTreap> split(int k) {
        assert(k <= size());
        auto p = split(std::move(root), k);
        return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};
    }

    void update(int l, int r, const E& x) {
        assert(0 <= l && l < r && r <= size());
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(root), l);
        std::tie(b, c) = split(std::move(b), r - l);
        b->lazy = O::op(b->lazy, x);
        root = join(join(std::move(a), std::move(b)), std::move(c));
    }

    T fold(int l, int r) {
        assert(0 <= l && l < r && r <= size());
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(root), l);
        std::tie(b, c) = split(std::move(b), r - l);
        auto ret = b->sum;
        root = join(join(std::move(a), std::move(b)), std::move(c));
        return ret;
    }

    void reverse(int l, int r) {
        assert(0 <= l && l < r && r <= size());
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(root), l);
        std::tie(b, c) = split(std::move(b), r - l);
        b->rev ^= true;
        root = join(join(std::move(a), std::move(b)), std::move(c));
    }

    void insert(int k, const T& x) {
        auto s = split(std::move(root), k);
        root = join(join(std::move(s.first), std::make_unique<Node>(x)), std::move(s.second));
    }

    void erase(int k) {
        auto p = split(std::move(root), k);
        auto q = split(std::move(p.second), 1);
        root = join(std::move(p.first), std::move(q.second));
    }

    void push_front(const T& x) {
        root = join(std::make_unique<Node>(x), std::move(root));
    }

    void push_back(const T& x) {
        root = join(std::move(root), std::make_unique<Node>(x));
    }

    void pop_front() {
        root = split(std::move(root), 1).second;
    }

    void pop_back() {
        root = split(std::move(root), size() - 1).first;
    }

    int size() const {
        return size(root);
    }

    bool empty() const {
        return size() == 0;
    }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    static unsigned int rand() {
        static int x = 122312555;
        static int y = 336261662;
        static int z = 558127122;
        static int w = 917277772;
        unsigned int t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }

    struct Node {
        node_ptr left, right;
        T val, sum;
        E lazy;
        unsigned int pri;
        int sz;
        bool rev;

        Node() : Node(M::id) {}
        Node(const T& x) : left(nullptr), right(nullptr), val(x), sum(val), lazy(O::id), pri(rand()), sz(1), rev(false) {}
    };

    node_ptr root;

    explicit LazyTreap(node_ptr root) : root(std::move(root)) {}

    static int size(const node_ptr& t) {
        return t ? t->sz : 0;
    }

    static void recalc(const node_ptr& t) {
        if (!t) return;
        t->sz = size(t->left) + 1 + size(t->right);
        t->sum = t->val;
        if (t->left) t->sum = M::op(t->left->sum, t->sum);
        if (t->right) t->sum = M::op(t->sum, t->right->sum);
    }

    static void push(const node_ptr& t) {
        if (t->rev) {
            std::swap(t->left, t->right);
            if (t->left) t->left->rev ^= true;
            if (t->right) t->right->rev ^= true;
            t->rev = false;
        }
        if (t->lazy != O::id) {
            t->val = act(t->val, t->lazy);
            if (t->left) {
                t->left->lazy = O::op(t->left->lazy, t->lazy);
                t->left->sum = act(t->left->sum, t->lazy);
            }
            if (t->right) {
                t->right->lazy = O::op(t->right->lazy, t->lazy);
                t->right->sum = act(t->right->sum, t->lazy);
            }
            t->lazy = O::id;
        }
        recalc(t);
    }

    static node_ptr join(node_ptr l, node_ptr r) {
        if (!l) return r;
        if (!r) return l;
        push(l);
        push(r);
        if (l->pri > r->pri) {
            l->right = join(std::move(l->right), std::move(r));
            recalc(l);
            return l;
        } else {
            r->left = join(std::move(l), std::move(r->left));
            recalc(r);
            return r;
        }
    }

    static std::pair<node_ptr, node_ptr> split(node_ptr t, int k) {
        if (!t) return {nullptr, nullptr};
        push(t);
        if (k <= size(t->left)) {
            auto s = split(std::move(t->left), k);
            t->left = std::move(s.second);
            recalc(t);
            return {std::move(s.first), std::move(t)};
        } else {
            auto s = split(std::move(t->right), k - size(t->left) - 1);
            t->right = std::move(s.first);
            recalc(t);
            return {std::move(t), std::move(s.second)};
        }
    }
};

template <int mod>
class Modint {
    using mint = Modint;
    static_assert(mod > 0, "Modulus must be positive");

public:
    static constexpr int get_mod() noexcept { return mod; }

    constexpr Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}

    constexpr int value() const noexcept { return x; }

    constexpr mint& operator+=(const mint& r) noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }
    constexpr mint& operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod; return *this; }
    constexpr mint& operator*=(const mint& r) noexcept { x = static_cast<int>(1LL * x * r.x % mod); return *this; }
    constexpr mint& operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }

    constexpr mint operator-() const noexcept { return mint(-x); }

    constexpr mint operator+(const mint& r) const noexcept { return mint(*this) += r; }
    constexpr mint operator-(const mint& r) const noexcept { return mint(*this) -= r; }
    constexpr mint operator*(const mint& r) const noexcept { return mint(*this) *= r; }
    constexpr mint operator/(const mint& r) const noexcept { return mint(*this) /= r; }

    constexpr bool operator==(const mint& r) const noexcept { return x == r.x; }
    constexpr bool operator!=(const mint& r) const noexcept { return x != r.x; }

    constexpr mint inv() const noexcept {
        int a = x, b = mod, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return mint(u);
    }

    constexpr mint pow(long long n) const noexcept {
        mint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend std::ostream& operator<<(std::ostream& os, const mint& r) {
        return os << r.x;
    }

    friend std::istream& operator>>(std::istream& is, mint& r) {
        long long t;
        is >> t;
        r = mint(t);
        return is;
    }

private:
    int x;
};

using mint = Modint<998244353>;

struct M {
    using T = pair<mint, mint>;
    static constexpr T id = {0, 0};
    static T op(T a, T b) {
        return {a.first + b.first, a.second + b.second};
    }
};

struct O {
    using T = pair<mint, mint>;
    static constexpr T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

M::T act(M::T a, O::T b) {
    return {a.first * b.first + a.second * b.second, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    LazyTreap<M, O, act> st;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        st.push_back({a, 1});
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int i, x;
            cin >> i >> x;
            st.insert(i, {x, 1});
        } else if (t == 1) {
            int i;
            cin >> i;
            st.erase(i);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            st.reverse(l, r);
        } else if (t == 3) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.update(l, r, {b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.fold(l, r).first << "\n";
        }
    }
}