---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: misc/marathon_template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bc957e26ff41470c556ee5d09e96880b">misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/misc/marathon_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 04:40:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <bitset>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <stack>
#include <cmath>
#include <string>
#include <chrono>

using namespace std;
using ll = long long;

struct Random {
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;

    unsigned int xorshift() {
        unsigned int t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }

    // returns a random integer in the range [0, n)
    unsigned int next_int(unsigned int n) {
        return xorshift() % n;
    }

    // returns a random double number in the range [0, 1)
    double next_double() {
        return xorshift() * (1.0 / 0xFFFFFFFFu);
    }
} rng;

struct Timer {
    chrono::steady_clock::time_point start_time;

    void start() {
        start_time = chrono::steady_clock::now();
    }

    long long get_time() {
        auto cur_time = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();
    }
} timer;

/***************************************************************
 * CODE BELOW
 ***************************************************************/

#define DEBUG

struct State {

    ll score;

    State() {

    }

    void move() {

    }

    void move_back() {

    }
};

double accept(ll prev_score, ll cur_score, double temperature) {
    if (prev_score < cur_score) return 1.0;
    return exp((double) (cur_score - prev_score) / temperature);
}

State simulated_annealing(State& beginning_state, ll duration) {

    double temp_start = 2e3;
    double temp_end = 6e2;
    double temperature = temp_start;

    State cur_state = beginning_state;
    State best_state = cur_state;
    int iter = 0;
    ll cur_time = 0;
    timer.start();

    while (true) {
        if (iter % 100 == 0) {
            cur_time = timer.get_time();
            if (cur_time > duration) break;
            double t = (double) cur_time / duration;
            temperature = pow(temp_start, 1 - t) * pow(temp_end, t);
        }

        #ifdef DEBUG
        if (iter % 100000 == 0) cerr << temperature << endl;
        #endif

        ll prev_score = cur_state.score;
        cur_state.move();

        if (accept(prev_score, cur_state.score, temperature) > rng.next_double()) {
            if (cur_state.score > best_state.score) {
                best_state = cur_state;
            }
        } else {
            cur_state.move_back();
        }

        iter++;
    }

    #ifdef DEBUG
    cerr << "Iterations: " << iter << endl;
    #endif

    return best_state;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "misc/marathon_template.cpp"
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <bitset>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <stack>
#include <cmath>
#include <string>
#include <chrono>

using namespace std;
using ll = long long;

struct Random {
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;

    unsigned int xorshift() {
        unsigned int t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }

    // returns a random integer in the range [0, n)
    unsigned int next_int(unsigned int n) {
        return xorshift() % n;
    }

    // returns a random double number in the range [0, 1)
    double next_double() {
        return xorshift() * (1.0 / 0xFFFFFFFFu);
    }
} rng;

struct Timer {
    chrono::steady_clock::time_point start_time;

    void start() {
        start_time = chrono::steady_clock::now();
    }

    long long get_time() {
        auto cur_time = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();
    }
} timer;

/***************************************************************
 * CODE BELOW
 ***************************************************************/

#define DEBUG

struct State {

    ll score;

    State() {

    }

    void move() {

    }

    void move_back() {

    }
};

double accept(ll prev_score, ll cur_score, double temperature) {
    if (prev_score < cur_score) return 1.0;
    return exp((double) (cur_score - prev_score) / temperature);
}

State simulated_annealing(State& beginning_state, ll duration) {

    double temp_start = 2e3;
    double temp_end = 6e2;
    double temperature = temp_start;

    State cur_state = beginning_state;
    State best_state = cur_state;
    int iter = 0;
    ll cur_time = 0;
    timer.start();

    while (true) {
        if (iter % 100 == 0) {
            cur_time = timer.get_time();
            if (cur_time > duration) break;
            double t = (double) cur_time / duration;
            temperature = pow(temp_start, 1 - t) * pow(temp_end, t);
        }

        #ifdef DEBUG
        if (iter % 100000 == 0) cerr << temperature << endl;
        #endif

        ll prev_score = cur_state.score;
        cur_state.move();

        if (accept(prev_score, cur_state.score, temperature) > rng.next_double()) {
            if (cur_state.score > best_state.score) {
                best_state = cur_state;
            }
        } else {
            cur_state.move_back();
        }

        iter++;
    }

    #ifdef DEBUG
    cerr << "Iterations: " << iter << endl;
    #endif

    return best_state;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

