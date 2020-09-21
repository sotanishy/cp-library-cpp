#include <bits/stdc++.h>

/*
 * @brief Coordinate Compression
 * @docs docs/misc/compress.md
 */
template <typename T>
class Compress {
public:
    explicit Compress(const std::vector<T>& vs) : xs(vs) {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    }

    int compress(const T& x) {
        return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }

    T decompress(int i) {
        return xs[i];
    }

private:
    std::vector<T> xs;
};