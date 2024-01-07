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

    std::vector<int> compress(std::vector<T> vs) const {
        std::ranges::transform(vs, vs.begin(),
                               [&](const T& x) { return compress(x); });
        return vs;
    }

    T decompress(int i) const { return xs[i]; }

    int size() const { return xs.size(); }

   private:
    std::vector<T> xs;
};