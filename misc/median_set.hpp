#pragma once
#include <set>

/**
 * @brief Median Set
 */
template <typename T>
class MedianSet {
   public:
    void insert(T x) {
        if (x < *right.begin()) {
            left.insert(x);
        } else {
            right.insert(x);
        }
        balance();
    }

    void erase(T x) {
        if (x < *right.begin()) {
            left.erase(x);
        } else {
            right.erase(x);
        }
        balance();
    }

    T median() const {
        if (left.size() > right.size()) {
            return *left.rbegin();
        } else {
            return (*left.rbegin() + *right.begin()) / 2;
        }
    }

   private:
    std::set<T> left, right;

    void balance() {
        while (left.size() < right.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        while (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            left.erase(left.rbegin());
        }
    }
};
