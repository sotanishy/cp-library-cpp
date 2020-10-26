#pragma once
#include <cassert>
#include "persistent_array.cpp"

/*
 * @brief Persistent Queue
 */
template <typename T, int Cap = (int) 1e7>
class PersistentQueue {
public:
    PersistentQueue() : first(0), last(0) {}

    int size() const {
        return (last - first + Cap) % Cap;
    }

    bool empty() const {
        return size() == 0;
    }

    T front() const {
        assert(!empty());
        return pa.get(first);
    }

    T back() const {
        assert(!empty());
        return pa.get((last + Cap - 1) % Cap);
    }

    PersistentQueue push(const T& val) const {
        assert(size() < Cap);
        return PersistentQueue(pa.set(last, val), first, (last + 1) % Cap);
    }

    PersistentQueue pop() const {
        assert(!empty());
        return PersistentQueue(pa, (first + 1) % Cap, last);
    }

private:
    PersistentArray<T> pa;
    int first, last;

    PersistentQueue(const PersistentArray<T>& pa, int first, int last)
        : pa(pa), first(first), last(last) {}
};