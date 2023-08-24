#pragma once
#include <set>
#include <vector>

/**
 * @brief Sum of Top K Values
 */

template <typename T>
class SumTopK {
   public:
    SumTopK() = default;
    explicit SumTopK(int k) : k(k) {}

    void insert(T x) {
        small.insert(x);
        sumsmall += x;
        fix();
    }

    void erase(T x) {
        if (small.find(x) != small.end()) {
            small.erase(small.find(x));
            sumsmall -= x;
        } else {
            assert(big.find(x) != big.end());
            big.erase(big.find(x));
            sumbig -= x;
        }
        fix();
    }

    T sum_big() { return sumbig; }

    T sum_small() { return sumsmall; }

   private:
    std::multiset<T> small, big;
    T sumsmall = 0, sumbig = 0;
    int k;

    void fix() {
        while (!small.empty() && !big.empty() &&
               *small.rbegin() > *big.begin()) {
            auto st = --small.end();
            auto bt = big.begin();
            auto sv = *st, bv = *bt;
            sumsmall -= sv, sumsmall += bv;
            sumbig -= bv, sumbig += sv;
            small.erase(st), small.insert(bv);
            big.erase(bt), big.insert(sv);
        }
        while (!small.empty() && big.size() < k) {
            auto st = --small.end();
            auto sv = *st;
            sumsmall -= sv;
            sumbig += sv;
            small.erase(st);
            big.insert(sv);
        }
        while (big.size() > k) {
            auto bt = big.begin();
            auto bv = *bt;
            sumsmall += bv;
            sumbig -= bv;
            big.erase(bt);
            small.insert(bv);
        }
    }
};
