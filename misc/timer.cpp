#include <bits/stdc++.h>

struct Timer {
    std::chrono::steady_clock::time_point start_time;

    void start() {
        start_time = std::chrono::steady_clock::now();
    }

    long long get_time() {
        auto cur_time = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - start_time).count();
    }
};