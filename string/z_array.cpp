#pragma once
#include <bits/stdc++.h>

/*
 * @brief Z Array
 * @docs docs/string/z_array.md
 */
std::vector<int> z_array(const std::string& s) {
    int n = s.size();
    std::vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    // for (int i = 1; i < n; ++i) {
    //     if (i > r) {
    //         l = r = i;
    //         while (r < n && s[r - l] == s[r]) ++r;
    //         --r;
    //         z[i] = r - l + 1;
    //     } else {
    //         int k = i - l;
    //         if (z[k] < r - i + 1) {
    //             z[i] = z[k];
    //         } else {
    //             l = i;
    //             while (r < n && s[r - l] == s[r]) ++r;
    //             --r;
    //             z[i] = r - l + 1;
    //         }
    //     }
    // }
    for (int i = 1; i < n; ++i) {
        int k = i - l;
        if (i <= r && z[k] < r - i + 1) {
            z[i] = z[k];
        } else {
            l = i;
            if (i > r) r = i;
            while (r < n && s[r - l] == s[r]) ++r;
            --r;
            z[i] = r - l + 1;
        }
    }
    return z;
}