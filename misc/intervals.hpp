#pragma once
#include <cassert>
#include <limits>
#include <set>
#include <utility>

template <typename T>
class Intervals {
public:
    static constexpr T INF = std::numeric_limits<T>::max() / 2;

    Intervals() {
        st.emplace(INF, INF);
        st.emplace(-INF, -INF);
    }

    bool covered(T x) const { return covered(x, x); }
    bool covered(T l, T r) const {
        assert(l <= r);
        auto it = --(st.lower_bound({l + 1, l + 1}));
        return it->first <= l && r <= it->second;
    }

    std::pair<T, T> get(T x) const {
        auto it = --(st.lower_bound({x + 1, x + 1}));
        if (it->first <= x && x <= it->second) return *it;
        return {-INF, -INF};
    }

    std::vector<std::pair<T, T>> get(T l, T r) const {
        assert(l <= r);
        auto it = --(st.lower_bound({l + 1, l + 1}));
        std::vector<std::pair<T, T>> ret;
        while (it != st.end()) {
            if (l <= it->second && it->first <= r) ret.push_back(*it);
            ++it;
        }
        return ret;
    }

    void insert(T x) { insert(x, x); }
    void insert(T l, T r) {
        assert(l <= r);
        auto it = --(st.lower_bound({l + 1, l + 1}));
        if (it->first <= l && r <= it->second) return;
        if (it->first <= l && l <= it->second + 1) {
            l = it->first;
            it = st.erase(it);
        } else {
            ++it;
        }
        while (it->second < r) {
            it = st.erase(it);
        }
        if (it->first - 1 <= r && r <= it->second) {
            r = it->second;
            st.erase(it);
        }
        st.emplace(l, r);
    }

    void erase(T x) { erase(x, x); }
    void erase(T l, T r) {
        assert(l <= r);
        auto it = --(st.lower_bound({l + 1, l + 1}));
        if (it->first <= l && r <= it->second) {
            if (it->first < l) st.emplace(it->first, l - 1);
            if (r < it->second) st.emplace(r + 1, it->second);
            st.erase(it);
            return;
        }
        if (it->first <= l && l <= it->second) {
            if (it->first < l) st.emplace(it->first, l - 1);
            it = st.erase(it);
        } else {
            ++it;
        }
        while (it->second <= r) {
            it = st.erase(it);
        }
        if (it->first <= r && r <= it->second) {
            if (r < it->second) st.emplace(r + 1, it->second);
            st.erase(it);
        }
    }

    std::set<std::pair<T, T>> ranges() const { return st; }

    T mex(T x) const {
        auto it = --(st.lower_bound({x + 1, x + 1}));
        if (it->first <= x && x <= it->second) return it->second + 1;
        return x;
    }

private:
    std::set<std::pair<T, T>> st;
};