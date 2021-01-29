---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bst/lazy_treap.cpp\"\n#include <cassert>\n\
    #include <memory>\n#include <random>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n\ntemplate <typename M, typename O, typename M::T (*act)(typename\
    \ M::T, typename O::T)>\nclass LazyTreap {\n    using T = typename M::T;\n   \
    \ using E = typename O::T;\n\n    private:\n\n    inline int xorshift(){\n   \
    \     static int x=122312555;\n        static int y=336261662;\n        static\
    \ int z=558127122;\n        static int w=917277772;\n        int t;\n        t=x^(x<<11);\n\
    \        x=y;y=z;z=w;\n        return w=(w^(w>>19))^(t^(t>>8));\n    }\n\n   \
    \ struct Node{\n        Node *l,*r;\n        int cnt,priority;\n        T val,acc;\n\
    \        E lazy;\n        bool rev;\n        Node()=default;\n        Node(const\
    \ T &val,const E &lazy,int priority):\n        l(nullptr),r(nullptr),cnt(1),priority(priority),val(val),acc(val),lazy(lazy),rev(false){}\n\
    \    } *root=nullptr;\n\n    int count(const Node *t){return t?t->cnt:0;}\n  \
    \  T acc(const Node *t){return t?t->acc:M::id;}\n\n    Node *update(Node *t){\n\
    \        t->cnt=count(t->l)+count(t->r)+1;\n        t->acc=M::op(M::op(acc(t->l),t->val),acc(t->r));\n\
    \        return t;\n    }\n    Node *propagate(Node *t){\n        if(t and t->rev){\n\
    \            t->rev=false;\n            swap(t->l,t->r);\n            if(t->l)\
    \ t->l->rev^=1;\n            if(t->r) t->r->rev^=1;\n        }\n        if(t and\
    \ t->lazy!=O::id){\n            t->val=act(t->val,t->lazy);\n            if(t->l){\n\
    \                t->l->lazy=O::op(t->l->lazy,t->lazy);\n                t->l->acc=act(t->l->acc,t->lazy);\n\
    \            }\n            if(t->r){\n                t->r->lazy=O::op(t->r->lazy,t->lazy);\n\
    \                t->r->acc=act(t->r->acc,t->lazy);\n            }\n          \
    \  t->lazy=O::id;\n        }\n        return update(t);\n    }\n\n    Node *merge(Node\
    \ *l,Node *r){\n        if(!l or !r) return l?l:r;\n        if(l->priority>r->priority){\n\
    \            l=propagate(l);\n            l->r=merge(l->r,r);\n            return\
    \ update(l);\n        }else{\n            r=propagate(r);\n            r->l=merge(l,r->l);\n\
    \            return update(r);\n        }\n    }\n    pair<Node *,Node *> split(Node\
    \ *t,int k){\n        if(!t) return {nullptr,nullptr};\n        t=propagate(t);\n\
    \        if(k<=count(t->l)){\n            auto s=split(t->l,k);\n            t->l=s.second;\n\
    \            return {s.first,update(t)};\n        }else{\n            auto s=split(t->r,k-count(t->l)-1);\n\
    \            t->r=s.first;\n            return {update(t),s.second};\n       \
    \ }\n    }\n\n    void insert(Node *&t,int k,const T &x){\n        auto s=split(t,k);\n\
    \        t=merge(merge(s.first,new Node(x,O::id,xorshift())),s.second);\n    }\n\
    \    void erase(Node *&t,int k){\n        auto s=split(t,k);\n        t=merge(s.first,split(s.second,1).second);\n\
    \    }\n\n    T fold(Node *&t,int a,int b){\n        if(a>b) return M::id;\n \
    \       auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        auto\
    \ ret=acc(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n     \
    \   return ret;\n    }\n    void update(Node *&t,int a,int b,const E &o){\n  \
    \      if(a>b) return ;\n        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n\
    \        y.first->lazy=O::op(y.first->lazy,o);\n        t=merge(x.first,merge(propagate(y.first),y.second));\n\
    \    }\n    void reverse(Node *&t,int a,int b){\n        if(a>b) return ;\n  \
    \      auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        y.first->rev^=1;\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n    void dump(Node\
    \ *t,typename vector<T>::iterator &ite){\n        if(!t) return ;\n        t=propagate(t);\n\
    \        dump(t->l,ite);\n        *ite=t->val;\n        dump(t->r,++ite);\n  \
    \  }\n\n\n    public:\n\n    int size(){return count(root);}\n    bool empty(){return\
    \ !root;}\n\n    void insert(int k,const T &x){insert(root,k,x);}\n    void erase(int\
    \ k){erase(root,k);}\n    void reverse(int l,int r){reverse(root,l,r);}\n    T\
    \ fold(int l,int r){return fold(root,l,r);}\n    void update(int l,int r,const\
    \ E &x){update(root,l,r,x);}\n    vector<T> dump(){\n        vector<T> ret(size());\n\
    \        auto ite=begin(ret);\n        dump(root,ite);\n        return ret;\n\
    \    }\n\n};\n/*\ntemplate <typename M, typename O, typename M::T (*act)(typename\
    \ M::T, typename O::T)>\nclass LazyTreap {\n    using T = typename M::T;\n   \
    \ using E = typename O::T;\n\npublic:\n    LazyTreap() = default;\n\n    static\
    \ LazyTreap join(LazyTreap l, LazyTreap r) {\n        return LazyTreap(join(std::move(l.root),\
    \ std::move(r.root)));\n    }\n\n    std::pair<LazyTreap, LazyTreap> split(int\
    \ k) {\n        assert(0 <= k && k <= size());\n        auto p = split(std::move(root),\
    \ k);\n        return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};\n\
    \    }\n\n    void update(int l, int r, const E& x) {\n        assert(0 <= l &&\
    \ l < r && r <= size());\n        node_ptr a, b, c;\n        std::tie(a, b) =\
    \ split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b), r -\
    \ l);\n        b->lazy = O::op(b->lazy, x);\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    T fold(int l, int r) {\n       \
    \ assert(0 <= l && l < r && r <= size());\n        node_ptr a, b, c;\n       \
    \ std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        auto ret = b->sum;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n        return ret;\n    }\n\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= size());\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto s = split(std::move(root), k);\n        root = join(join(std::move(s.first),\
    \ std::make_unique<Node>(x)), std::move(s.second));\n    }\n\n    void erase(int\
    \ k) {\n        auto p = split(std::move(root), k);\n        auto q = split(std::move(p.second),\
    \ 1);\n        root = join(std::move(p.first), std::move(q.second));\n    }\n\n\
    \    void push_front(const T& x) {\n        root = join(std::make_unique<Node>(x),\
    \ std::move(root));\n    }\n\n    void push_back(const T& x) {\n        root =\
    \ join(std::move(root), std::make_unique<Node>(x));\n    }\n\n    void pop_front()\
    \ {\n        root = split(std::move(root), 1).second;\n    }\n\n    void pop_back()\
    \ {\n        root = split(std::move(root), size() - 1).first;\n    }\n\n    int\
    \ size() const {\n        return size(root);\n    }\n\n    bool empty() const\
    \ {\n        return size() == 0;\n    }\n\nprivate:\n    struct Node;\n    using\
    \ node_ptr = std::unique_ptr<Node>;\n\n    static unsigned int rand() {\n    \
    \    static std::random_device rd;\n        static std::mt19937 rng(rd());\n \
    \       return rng();\n    }\n\n    struct Node {\n        node_ptr left, right;\n\
    \        T val, sum;\n        E lazy;\n        unsigned int pri;\n        int\
    \ sz;\n        bool rev;\n\n        Node() : Node(M::id) {}\n        Node(const\
    \ T& x) : left(nullptr), right(nullptr), val(x), sum(val), lazy(O::id), pri(rand()),\
    \ sz(1), rev(false) {}\n    };\n\n    node_ptr root;\n\n    explicit LazyTreap(node_ptr\
    \ root) : root(std::move(root)) {}\n\n    static int size(const node_ptr& t) {\n\
    \        return t ? t->sz : 0;\n    }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left,\
    \ t->right);\n            if (t->left) t->left->rev ^= true;\n            if (t->right)\
    \ t->right->rev ^= true;\n            t->rev = false;\n        }\n        if (t->lazy\
    \ != O::id) {\n            t->val = act(t->val, t->lazy);\n            if (t->left)\
    \ {\n                t->left->lazy = O::op(t->left->lazy, t->lazy);\n        \
    \        t->left->sum = act(t->left->sum, t->lazy);\n            }\n         \
    \   if (t->right) {\n                t->right->lazy = O::op(t->right->lazy, t->lazy);\n\
    \                t->right->sum = act(t->right->sum, t->lazy);\n            }\n\
    \            t->lazy = O::id;\n        }\n        recalc(t);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        push(l);\n        push(r);\n        if (l->pri >\
    \ r->pri) {\n            l->right = join(std::move(l->right), std::move(r));\n\
    \            recalc(l);\n            return l;\n        } else {\n           \
    \ r->left = join(std::move(l), std::move(r->left));\n            recalc(r);\n\
    \            return r;\n        }\n    }\n\n    static std::pair<node_ptr, node_ptr>\
    \ split(node_ptr t, int k) {\n        if (!t) return {nullptr, nullptr};\n   \
    \     push(t);\n        if (k <= size(t->left)) {\n            auto s = split(std::move(t->left),\
    \ k);\n            t->left = std::move(s.second);\n            recalc(t);\n  \
    \          return {std::move(s.first), std::move(t)};\n        } else {\n    \
    \        auto s = split(std::move(t->right), k - size(t->left) - 1);\n       \
    \     t->right = std::move(s.first);\n            recalc(t);\n            return\
    \ {std::move(t), std::move(s.second)};\n        }\n    }\n};\n\n*/\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <random>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n\ntemplate <typename\
    \ M, typename O, typename M::T (*act)(typename M::T, typename O::T)>\nclass LazyTreap\
    \ {\n    using T = typename M::T;\n    using E = typename O::T;\n\n    private:\n\
    \n    inline int xorshift(){\n        static int x=122312555;\n        static\
    \ int y=336261662;\n        static int z=558127122;\n        static int w=917277772;\n\
    \        int t;\n        t=x^(x<<11);\n        x=y;y=z;z=w;\n        return w=(w^(w>>19))^(t^(t>>8));\n\
    \    }\n\n    struct Node{\n        Node *l,*r;\n        int cnt,priority;\n \
    \       T val,acc;\n        E lazy;\n        bool rev;\n        Node()=default;\n\
    \        Node(const T &val,const E &lazy,int priority):\n        l(nullptr),r(nullptr),cnt(1),priority(priority),val(val),acc(val),lazy(lazy),rev(false){}\n\
    \    } *root=nullptr;\n\n    int count(const Node *t){return t?t->cnt:0;}\n  \
    \  T acc(const Node *t){return t?t->acc:M::id;}\n\n    Node *update(Node *t){\n\
    \        t->cnt=count(t->l)+count(t->r)+1;\n        t->acc=M::op(M::op(acc(t->l),t->val),acc(t->r));\n\
    \        return t;\n    }\n    Node *propagate(Node *t){\n        if(t and t->rev){\n\
    \            t->rev=false;\n            swap(t->l,t->r);\n            if(t->l)\
    \ t->l->rev^=1;\n            if(t->r) t->r->rev^=1;\n        }\n        if(t and\
    \ t->lazy!=O::id){\n            t->val=act(t->val,t->lazy);\n            if(t->l){\n\
    \                t->l->lazy=O::op(t->l->lazy,t->lazy);\n                t->l->acc=act(t->l->acc,t->lazy);\n\
    \            }\n            if(t->r){\n                t->r->lazy=O::op(t->r->lazy,t->lazy);\n\
    \                t->r->acc=act(t->r->acc,t->lazy);\n            }\n          \
    \  t->lazy=O::id;\n        }\n        return update(t);\n    }\n\n    Node *merge(Node\
    \ *l,Node *r){\n        if(!l or !r) return l?l:r;\n        if(l->priority>r->priority){\n\
    \            l=propagate(l);\n            l->r=merge(l->r,r);\n            return\
    \ update(l);\n        }else{\n            r=propagate(r);\n            r->l=merge(l,r->l);\n\
    \            return update(r);\n        }\n    }\n    pair<Node *,Node *> split(Node\
    \ *t,int k){\n        if(!t) return {nullptr,nullptr};\n        t=propagate(t);\n\
    \        if(k<=count(t->l)){\n            auto s=split(t->l,k);\n            t->l=s.second;\n\
    \            return {s.first,update(t)};\n        }else{\n            auto s=split(t->r,k-count(t->l)-1);\n\
    \            t->r=s.first;\n            return {update(t),s.second};\n       \
    \ }\n    }\n\n    void insert(Node *&t,int k,const T &x){\n        auto s=split(t,k);\n\
    \        t=merge(merge(s.first,new Node(x,O::id,xorshift())),s.second);\n    }\n\
    \    void erase(Node *&t,int k){\n        auto s=split(t,k);\n        t=merge(s.first,split(s.second,1).second);\n\
    \    }\n\n    T fold(Node *&t,int a,int b){\n        if(a>b) return M::id;\n \
    \       auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        auto\
    \ ret=acc(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n     \
    \   return ret;\n    }\n    void update(Node *&t,int a,int b,const E &o){\n  \
    \      if(a>b) return ;\n        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n\
    \        y.first->lazy=O::op(y.first->lazy,o);\n        t=merge(x.first,merge(propagate(y.first),y.second));\n\
    \    }\n    void reverse(Node *&t,int a,int b){\n        if(a>b) return ;\n  \
    \      auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        y.first->rev^=1;\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n    void dump(Node\
    \ *t,typename vector<T>::iterator &ite){\n        if(!t) return ;\n        t=propagate(t);\n\
    \        dump(t->l,ite);\n        *ite=t->val;\n        dump(t->r,++ite);\n  \
    \  }\n\n\n    public:\n\n    int size(){return count(root);}\n    bool empty(){return\
    \ !root;}\n\n    void insert(int k,const T &x){insert(root,k,x);}\n    void erase(int\
    \ k){erase(root,k);}\n    void reverse(int l,int r){reverse(root,l,r);}\n    T\
    \ fold(int l,int r){return fold(root,l,r);}\n    void update(int l,int r,const\
    \ E &x){update(root,l,r,x);}\n    vector<T> dump(){\n        vector<T> ret(size());\n\
    \        auto ite=begin(ret);\n        dump(root,ite);\n        return ret;\n\
    \    }\n\n};\n/*\ntemplate <typename M, typename O, typename M::T (*act)(typename\
    \ M::T, typename O::T)>\nclass LazyTreap {\n    using T = typename M::T;\n   \
    \ using E = typename O::T;\n\npublic:\n    LazyTreap() = default;\n\n    static\
    \ LazyTreap join(LazyTreap l, LazyTreap r) {\n        return LazyTreap(join(std::move(l.root),\
    \ std::move(r.root)));\n    }\n\n    std::pair<LazyTreap, LazyTreap> split(int\
    \ k) {\n        assert(0 <= k && k <= size());\n        auto p = split(std::move(root),\
    \ k);\n        return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};\n\
    \    }\n\n    void update(int l, int r, const E& x) {\n        assert(0 <= l &&\
    \ l < r && r <= size());\n        node_ptr a, b, c;\n        std::tie(a, b) =\
    \ split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b), r -\
    \ l);\n        b->lazy = O::op(b->lazy, x);\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    T fold(int l, int r) {\n       \
    \ assert(0 <= l && l < r && r <= size());\n        node_ptr a, b, c;\n       \
    \ std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        auto ret = b->sum;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n        return ret;\n    }\n\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= size());\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto s = split(std::move(root), k);\n        root = join(join(std::move(s.first),\
    \ std::make_unique<Node>(x)), std::move(s.second));\n    }\n\n    void erase(int\
    \ k) {\n        auto p = split(std::move(root), k);\n        auto q = split(std::move(p.second),\
    \ 1);\n        root = join(std::move(p.first), std::move(q.second));\n    }\n\n\
    \    void push_front(const T& x) {\n        root = join(std::make_unique<Node>(x),\
    \ std::move(root));\n    }\n\n    void push_back(const T& x) {\n        root =\
    \ join(std::move(root), std::make_unique<Node>(x));\n    }\n\n    void pop_front()\
    \ {\n        root = split(std::move(root), 1).second;\n    }\n\n    void pop_back()\
    \ {\n        root = split(std::move(root), size() - 1).first;\n    }\n\n    int\
    \ size() const {\n        return size(root);\n    }\n\n    bool empty() const\
    \ {\n        return size() == 0;\n    }\n\nprivate:\n    struct Node;\n    using\
    \ node_ptr = std::unique_ptr<Node>;\n\n    static unsigned int rand() {\n    \
    \    static std::random_device rd;\n        static std::mt19937 rng(rd());\n \
    \       return rng();\n    }\n\n    struct Node {\n        node_ptr left, right;\n\
    \        T val, sum;\n        E lazy;\n        unsigned int pri;\n        int\
    \ sz;\n        bool rev;\n\n        Node() : Node(M::id) {}\n        Node(const\
    \ T& x) : left(nullptr), right(nullptr), val(x), sum(val), lazy(O::id), pri(rand()),\
    \ sz(1), rev(false) {}\n    };\n\n    node_ptr root;\n\n    explicit LazyTreap(node_ptr\
    \ root) : root(std::move(root)) {}\n\n    static int size(const node_ptr& t) {\n\
    \        return t ? t->sz : 0;\n    }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left,\
    \ t->right);\n            if (t->left) t->left->rev ^= true;\n            if (t->right)\
    \ t->right->rev ^= true;\n            t->rev = false;\n        }\n        if (t->lazy\
    \ != O::id) {\n            t->val = act(t->val, t->lazy);\n            if (t->left)\
    \ {\n                t->left->lazy = O::op(t->left->lazy, t->lazy);\n        \
    \        t->left->sum = act(t->left->sum, t->lazy);\n            }\n         \
    \   if (t->right) {\n                t->right->lazy = O::op(t->right->lazy, t->lazy);\n\
    \                t->right->sum = act(t->right->sum, t->lazy);\n            }\n\
    \            t->lazy = O::id;\n        }\n        recalc(t);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        push(l);\n        push(r);\n        if (l->pri >\
    \ r->pri) {\n            l->right = join(std::move(l->right), std::move(r));\n\
    \            recalc(l);\n            return l;\n        } else {\n           \
    \ r->left = join(std::move(l), std::move(r->left));\n            recalc(r);\n\
    \            return r;\n        }\n    }\n\n    static std::pair<node_ptr, node_ptr>\
    \ split(node_ptr t, int k) {\n        if (!t) return {nullptr, nullptr};\n   \
    \     push(t);\n        if (k <= size(t->left)) {\n            auto s = split(std::move(t->left),\
    \ k);\n            t->left = std::move(s.second);\n            recalc(t);\n  \
    \          return {std::move(s.first), std::move(t)};\n        } else {\n    \
    \        auto s = split(std::move(t->right), k - size(t->left) - 1);\n       \
    \     t->right = std::move(s.first);\n            recalc(t);\n            return\
    \ {std::move(t), std::move(s.second)};\n        }\n    }\n};\n\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bst/lazy_treap.cpp
  requiredBy: []
  timestamp: '2021-01-30 00:35:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
documentation_of: data-structure/bst/lazy_treap.cpp
layout: document
title: Treap with Lazy Propagation
---

## Description

遅延伝搬ツリープは，区間更新が可能なツリープである．扱える代数的構造は遅延伝搬セグメント木と同様なので，そちらを参照．遅延伝搬セグメント木が提供する操作に加えて挿入，削除，併合，分割，区間反転が可能である．

基本的には非可換のモノイドも扱えるが，`reverse` 操作をする場合は可換性が必要がある．非可換も実装を少しいじれば扱えるがめんどくさいので実装していない．

空間計算量: $O(n)$

## Operations

- `static Treap join(Treap l, Treap r)`
    - `l` と `r` を併合する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `pair<Treap, Treap> split(int k)`
    - $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる．
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾に $x$ を追加する/の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 空か判定する
    - 時間計算量: $O(1)$