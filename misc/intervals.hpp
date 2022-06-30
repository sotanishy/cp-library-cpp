#pragma once
#include <cassert>
#include <limits>
#include <set>
#include <utility>
#include <vector>

template <typename X, typename T>
class Intervals {
public:
    static constexpr X INF = std::numeric_limits<T>::max() / 2;

    Intervals(T default_val) : default_val(default_val) {
        st.emplace(INF, INF, default_val);
        st.emplace(-INF, -INF, default_val);
    }

    T get(X x) const {
        auto it = --(st.lower_bound({x + 1, x, default_val}));
        auto [l, r, v] = *it;
        if (l <= x && x <= r) return v;
        return default_val;
    }

    std::vector<std::tuple<X, X, T>> get(X l, X r) const {
        assert(l <= r);
        auto it = --(st.lower_bound({l + 1, l, default_val}));
        std::vector<std::tuple<X, X, T>> ret;
        while (it != st.end()) {
            auto [l_, r_, v_] = *it;
            if (r < l_) break;
            l_ = std::max(l_, l);
            r_ = std::min(r_, r);
            if (l_ <= r_) ret.emplace_back(l_, r_, v_);
            ++it;
        }
        return ret;
    }

    void set(X l, X r, T v) {
        assert(l <= r);
        auto it = --(st.lower_bound({l + 1, l, default_val}));
        std::vector<std::tuple<X, X, T>> intervals;
        if (v != default_val) intervals.emplace_back(l, r, v);
        while (it != st.end()) {
            auto [l_, r_, v_] = *it;
            if (r < l_) break;
            if (l_ < l) {
                intervals.emplace_back(l_, std::min(r_, l - 1), v_);
            }
            if (r < r_) {
                intervals.emplace_back(r + 1, r_, v_);
            }
            it = st.erase(it);
        }
        for (auto [l_, r_, v_] : intervals) st.emplace(l_, r_, v_);
    }

    void erase(X l, X r) { set(l, r, default_val); }

private:
    std::set<std::tuple<X, X, T>> st;
    T default_val;
};