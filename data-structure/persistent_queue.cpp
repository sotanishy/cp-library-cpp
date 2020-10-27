#pragma once
#include <cassert>
#include "persistent_array.cpp"

/*
 * @brief Persistent Queue
 */
template <typename T>
class PersistentQueue {
public:
    PersistentQueue() : first(0), last(0) {}

    int size() const {
        return last - first;
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
        return pa.get(last - 1);
    }

    PersistentQueue push(const T& val) const {
        return PersistentQueue(pa.set(last, val), first, last + 1);
    }

    PersistentQueue pop() const {
        assert(!empty());
        return PersistentQueue(pa, first + 1, last);
    }

private:
    PersistentArray<T> pa;
    int first, last;

    PersistentQueue(const PersistentArray<T>& pa, int first, int last)
        : pa(pa), first(first), last(last) {}
};