#include <bits/stdc++.h>
using namespace std;

struct Timer {
    chrono::steady_clock::time_point start_time;

    void start() {
        start_time = chrono::steady_clock::now();
    }

    long long get_time() {
        auto cur_time = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();
    }
};