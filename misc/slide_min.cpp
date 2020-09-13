#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> slide_min(const vector<T>& v, int k) {
    vector<T> ret;
    deque<int> dq;
    for (int i = 0; i < v.size(); i++) {
        while (!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) {
            ret.push_back(v[dq.front()]);
            if (dq.front() == i - k + 1) dq.pop_front();
        }
    }
}