#pragma once
#include <algorithm>
#include <vector>

/**
 * @brief Coordinate Compression
 */
template <typename T>
class Compress {
   public:
    Compress() = default;
    explicit Compress(const std::vector<T>& vs) : xs(vs) {
        std::ranges::sort(xs);
        xs.erase(std::ranges::unique(xs).begin(), xs.end());
    }

    int compress(const T& x) const {
        return std::ranges::lower_bound(xs, x) - xs.begin();
    }

    std::vector<int> compress(const std::vector<T>& vs) const {
        std::vector<int> res;
        std::ranges::transform(vs, res.begin(),
                               [&](const T& x) { return compress(x); });
        return res;
    }

    T decompress(int i) const { return xs[i]; }

    int size() const { return xs.size(); }

   private:
    std::vector<T> xs;
};