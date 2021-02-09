#pragma once

template <typename T>
struct Edge {
    int from, to;
    T weight;
    Edge() = default;
    Edge(int to, T weight) : from(-1), to(to), weight(weight) {}
    Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}
};
