#pragma once
#include <vector>
#include "geometry.hpp"

std::vector<Vec> convex_hull(std::vector<Vec>& pts) {
    int n = pts.size();
    if (n == 1) return pts;
    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {
        return (v1.imag() != v2.imag()) ? (v1.imag() < v2.imag()) : (v1.real() < v2.real());
    });
    int k = 0; // the number of vertices in the convex hull
    std::vector<Vec> ch(2 * n);
    // right
    for (int i = 0; i < n; ++i) {
        while (k > 1 && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;
        ch[k++] = pts[i];
    }
    int t = k;
    // left
    for (int i = n - 2; i >= 0; --i) {
        while (k > t && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;
        ch[k++] = pts[i];
    }
    ch.resize(k - 1);
    return ch;
}

