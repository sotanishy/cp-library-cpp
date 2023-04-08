#pragma once
#include <unordered_set>

template <typename M, typename S, S (*act)(typename M::T, S)>
int discrete_log_monoid_action(typename M::T x, S s, S t, long long N) {
    using T = typename M::T;

    // baby-step
    const int m = sqrt(N) + 1;
    std::unordered_set<S> babies;
    S baby = t;
    for (int i = 1; i <= m; ++i) {
        baby = act(x, baby);
        babies.insert(baby);
    }

    // giant-step
    T xm = M::id(), y = x;
    int m_ = m;
    while (m_) {
        if (m_ & 1) xm = M::op(xm, y);
        y = M::op(y, y);
        m_ >>= 1;
    }

    S giant = s;
    bool first = true;
    for (int i = 0; i <= N / m; ++i) {
        if (babies.count(act(xm, giant))) {
            S u = giant;
            for (int j = 0; j < m; ++j) {
                if (u == t) {
                    return m * i + j;
                }
                u = act(x, u);
            }
            if (!first) return -1;
            first = false;
        }
        giant = act(xm, giant);
    }
    return -1;
}
