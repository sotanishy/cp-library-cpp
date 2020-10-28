// #define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

// #include "../../math/modint.cpp"
// #include "../../tree/link_cut_tree.cpp"

#include <bits/stdc++.h>
using namespace std;

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

template <typename M, typename M::T (*flip)(typename M::T)>
class ReversibleSplayTree {
    using T = typename M::T;

protected:
    struct Node;

public:
    using node_ptr = std::shared_ptr<Node>;

    node_ptr make_node(const T& x) const {
        return std::make_shared<Node>(x);
    }

    void reverse(const node_ptr& t) const {
        std::swap(t->left, t->right);
        t->sum = flip(t->sum);
        t->rev ^= true;
    }

protected:
    struct Node {
        node_ptr left, right, par;
        T val, sum;
        int sz;
        bool rev;

        Node() : left(nullptr), right(nullptr), par(nullptr), sz(1), rev(false) {}
        Node(const T& x) : Node() {
            val = sum = x;
        }
    };

    bool is_root(const node_ptr& t) const {
        return !t->par || (t->par->left != t && t->par->right != t);
    }

    void recalc(const node_ptr& t) const {
        t->sz = 1;
        t->sum = t->val;
        if (t->left) {
            t->sz += t->left->sz;
            t->sum = M::op(t->left->sum, t->sum);
        }
        if (t->right) {
            t->sz += t->right->sz;
            t->sum = M::op(t->sum, t->right->sum);
        }
    }

    void rotate_left(node_ptr t) const {
        auto x = t->par, y = x->par;
        x->right = t->left;
        if (x->right) x->right->par = x;
        t->left = x;
        x->par = t;
        recalc(x);
        recalc(t);
        t->par = y;
        if (y) {
            if (y->left == x) y->left = t;
            if (y->right == x) y->right = t;
            recalc(y);
        }
    }

    void rotate_right(node_ptr t) const {
        auto x = t->par, y = x->par;
        x->left = t->right;
        if (x->left) x->left->par = x;
        t->right = x;
        x->par = t;
        recalc(x);
        recalc(t);
        t->par = y;
        if (y) {
            if (y->left == x) y->left = t;
            if (y->right == x) y->right = t;
            recalc(y);
        }
    }

    void push(const node_ptr& t) const {
        if (t->rev) {
            if (t->left) reverse(t->left);
            if (t->right) reverse(t->right);
            t->rev = false;
        }
    }

    void splay(node_ptr t) const {
        push(t);
        while (!is_root(t)) {
            auto x = t->par;
            if (is_root(x)) {
                push(x);
                push(t);
                if (x->left == t) rotate_right(t);
                else rotate_left(t);
            } else {
                auto y = x->par;
                push(y);
                push(x);
                push(t);
                if (y->left == x) {
                    if (x->left == t) {
                        rotate_right(x);
                        rotate_right(t);
                    } else {
                        rotate_left(t);
                        rotate_right(t);
                    }
                } else {
                    if (x->right == t) {
                        rotate_left(x);
                        rotate_left(t);
                    } else {
                        rotate_right(t);
                        rotate_left(t);
                    }
                }
            }
        }
    }
};


template <typename M, typename M::T (*flip)(typename M::T)>
class LinkCutTree : ReversibleSplayTree<M, flip> {
    using T = typename M::T;
    using RST = ReversibleSplayTree<M, flip>;

public:
    using node_ptr = typename RST::node_ptr;

    using RST::make_node;

    void link(node_ptr v, node_ptr p) const {
        evert(v);
        access(p);
        v->par = p;
        p->right = v;
        recalc(p);
    }

    void cut(node_ptr v) const {
        access(v);
        auto p = v->left;
        v->left = p->par = nullptr;
        recalc(v);
    }

    void evert(node_ptr v) const {
        access(v);
        reverse(v);
    }

    void update(node_ptr v, const T& x) {
        access(v);
        v->val = x;
        recalc(v);
    }

    T fold(node_ptr u, node_ptr v) {
        evert(u);
        access(v);
        return v->sum;
    }

private:
    using RST::reverse;
    using RST::recalc;
    using RST::splay;

    void access(node_ptr v) const {
        node_ptr prev = nullptr;
        for (auto cur = v; cur; cur = cur->par) {
            splay(cur);
            cur->right = prev;
            recalc(cur);
            prev = cur;
        }
        splay(v);
    }
};

using mint = Modint<998244353>;

struct AffineMonoid {
    using T = pair<pair<mint, mint>, pair<mint, mint>>;
    static constexpr T id = {{1, 0}, {1, 0}};
    static T op(T a, T b) {
        return {
            {a.first.first * b.first.first, a.first.second * b.first.first + b.first.second},
            {b.second.first * a.second.first, b.second.second * a.second.first + a.second.second},
        };
    }
};

AffineMonoid::T flip(AffineMonoid::T a) { swap(a.first, a.second); return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    LinkCutTree<AffineMonoid, flip> lct;
    vector<decltype(lct)::node_ptr> nodes;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        nodes.emplace_back(lct.make_node({{a, b}, {a, b}}));
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        lct.link(nodes[u], nodes[v]);
    }
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            lct.evert(nodes[u]);
            lct.cut(nodes[v]);
            lct.link(nodes[w], nodes[x]);
        } else if (t == 1) {
            int p, c, d;
            cin >> p >> c >> d;
            lct.update(nodes[p], {{c, d}, {c, d}});
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            auto f = lct.fold(nodes[u], nodes[v]);
            cout << f.first.first * x + f.first.second << "\n";
        }
    }
}