#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            result.push_back(i);
        }
        sort(result.begin(), result.end(), [](const int& a, const int& b) {
            return to_string(a) < to_string(b);
        });
        return result;
    }
};
