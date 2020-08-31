#include <bits/stdc++.h>
using namespace std;

vector<int> change_base(int n, int base) {
    int q = n / base, r = n % base;
    if (q == 0) return {r};
    auto ret = change_base(q, base);
    ret.push_back(r);
    return ret;
}