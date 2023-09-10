#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)
#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)
#define all(x) begin(x), end(x)
template <typename T>
bool chmax(T& a, const T& b) {
    return a < b ? (a = b, 1) : 0;
}
template <typename T>
bool chmin(T& a, const T& b) {
    return a > b ? (a = b, 1) : 0;
}

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

class Random {
   public:
    // returns a random integer in the range [0, n)
    unsigned int next_int(int n) noexcept { return xorshift() % n; }

    // returns a random double number in the range [0, 1)
    double next_double() noexcept { return xorshift() * (1.0 / 0xFFFFFFFFu); }

   private:
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;

    unsigned int xorshift() noexcept {
        unsigned int t;
        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }
} rng;

class Timer {
   public:
    void start() { start_time = chrono::steady_clock::now(); }

    long long get_time() const {
        auto cur_time = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(cur_time -
                                                           start_time)
            .count();
    }

   private:
    chrono::steady_clock::time_point start_time;
} timer;

/***************************************************************
 * CODE BELOW
 ***************************************************************/

struct State {
    ll score;

    State() {}

    void move() {}

    void move_back() {}
};

inline double accept(ll prev_score, ll cur_score, double temperature) {
    if (prev_score < cur_score) return 1.0;
    return exp((cur_score - prev_score) / temperature);
}

State anneal(State cur_state, ll duration) {
    double temp_start = 2e3;
    double temp_end = 6e2;
    double temperature = temp_start;

    State best_state = cur_state;
    int iter = 0;
    ll start_time = timer.get_time();

    while (true) {
        if (iter % 100 == 0) {
            ll cur_time = timer.get_time() - start_time;
            if (cur_time > duration) break;
            double t = (double)cur_time / duration;
            temperature = pow(temp_start, 1 - t) * pow(temp_end, t);
        }

#ifdef DEBUG
        if (iter % 100000 == 0) cerr << temperature << endl;
#endif

        ll prev_score = cur_state.score;
        cur_state.move();

        if (accept(prev_score, cur_state.score, temperature) >
            rng.next_double()) {
            if (cur_state.score > best_state.score) {
                best_state = cur_state;
            }
        } else {
            cur_state.move_back();
        }

        ++iter;
    }

#ifdef DEBUG
    cerr << "Iterations: " << iter << endl;
#endif

    return best_state;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    timer.start();
}