#pragma once
#include <functional>
#include <limits>
#include <queue>
#include <vector>

template <typename T>
class SlopeTrick {
   public:
    SlopeTrick() {
        const T INF = std::numeric_limits<T>::max() / 2;
        left.push(-INF);
        right.push(INF);
    }

    void add_const(T a) { min_y += a; }

    void add_x_minus_a(T a) {
        T l = top_l();
        if (l < a) {
            push_r(a);
        } else {
            min_y += l - a;
            push_l(a);
            push_r(pop_l());
        }
    }

    void add_a_minus_x(T a) {
        T r = top_r();
        if (a < r) {
            push_l(a);
        } else {
            min_y += a - r;
            push_r(a);
            push_l(pop_r());
        }
    }

    void add_abs(T a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }

    void clear_left() { left.clear(); }
    void clear_right() { right.clear(); }

    void shift(T a) { shift(a, a); }

    void shift(T a, T b) {
        add_l += a;
        add_r += b;
    }

    T get_min() { return min_y; }

    T get(T x) {
        T ret = min_y;
        std::priority_queue<T, std::vector<T>> tmp_l;
        std::priority_queue<T, std::vector<T>, std::greater<T>> tmp_r;
        while (!left.empty()) {
            T a = pop_l();
            ret += max(T(0), a - x);
            tmp_l.push(a);
        }
        while (!right.empty()) {
            T a = pop_r();
            ret += max(T(0), x - a);
            tmp_r.push(a);
        }
        left.swap(tmp_l);
        right.swap(tmp_r);
        add_l = add_r = 0;
        return ret;
    }

   private:
    T min_y = 0, add_l = 0, add_r = 0;
    std::priority_queue<T, std::vector<T>> left;
    std::priority_queue<T, std::vector<T>, std::greater<T>> right;

    void push_l(T a) { left.push(a - add_l); }
    void push_r(T a) { right.push(a - add_r); }

    T top_l() { return left.top() + add_l; }
    T top_r() { return right.top() + add_r; }

    T pop_l() {
        T a = top_l();
        left.pop();
        return a;
    }

    T pop_r() {
        T a = top_r();
        right.pop();
        return a;
    }
};