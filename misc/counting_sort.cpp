#include <bits/stdc++.h>
using namespace std;

vector<int> counting_sort(vector<int>& v, int k) {
    vector<int> cnt(k+1);
    for (int i = 0; i < v.size(); i++) cnt[v[i]]++;
    for (int i = 1; i <= k; i++) cnt[i] += cnt[i-1];
    vector<int> ret(v.size());
    for (int i = v.size() - 1; i >= 0; i--) ret[--cnt[v[i]]] = v[i];
    return ret;
}