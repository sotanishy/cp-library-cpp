#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Coordinate Compression
 * @docs docs/misc/compress.md
 */
template <typename T>
class Compress {
public:
    explicit Compress(const vector<T>& vs) : xs(vs) {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }

    int compress(const T& x) {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }

    T decompress(int i) {
        return xs[i];
    }

private:
    vector<T> xs;
};