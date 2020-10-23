#pragma once
#include <algorithm>
#include <vector>

/*
 * @brief Coordinate Compression
 */
template <typename T>
class Compress {
public:
    Compress() = default;
    explicit Compress(const std::vector<T>& vs) : xs(vs) {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    }

    int compress(const T& x) const {
        return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }

    std::vector<int> compress(const std::vector<T>& vs) const {
        std::vector<int> ret;
        std::transform(vs.begin(), vs.end(), std::back_inserter(ret), [&](const T& x) {
            return compress(x);
        });
        return ret;
    }

    T decompress(int i) const {
        return xs[i];
    }

private:
    std::vector<T> xs;
};