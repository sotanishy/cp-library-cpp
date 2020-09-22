#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
string to_string(const pair<T, U>& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename T>
string to_string(const T& v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {
    cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}