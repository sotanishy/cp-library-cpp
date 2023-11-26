#include <string>
#include <vector>

std::vector<int> lyndon_factorization(const std::string& s) {
    const int n = s.size();
    std::vector<int> res;
    for (int i = 0; i < n;) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j]) {
                k = i;
            } else {
                ++k;
            }
            ++j;
        }
        while (i <= k) {
            res.push_back(i);
            i += j - k;
        }
    }
    res.push_back(n);
    return res;
}
