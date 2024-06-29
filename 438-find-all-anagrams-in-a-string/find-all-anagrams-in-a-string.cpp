class Solution {
public:

   bool isAnagram(const unordered_map<char, int>& countP, const unordered_map<char, int>& countTemp) {
        if (countP.size() != countTemp.size()) {
            return false;
        }
        for (const auto& p : countP) {
            if (countTemp.find(p.first) == countTemp.end() || countTemp.at(p.first) != p.second) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }

        vector<int> res;
        unordered_map<char, int> countP, countTemp;
        for (char c : p) {
            countP[c]++;
        }

        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            countTemp[s[right]]++;

            // Maintain the window size
            if (right - left + 1 > p.size()) {
                if (countTemp[s[left]] == 1) {
                    countTemp.erase(s[left]);  // Remove char completely if count is 1
                } else {
                    countTemp[s[left]]--;  // Decrease count
                }
                left++;
            }

            if (right - left + 1 == p.size()) {
                if (isAnagram(countP, countTemp)) {
                    res.push_back(left);
                }
            }
        }

        return res;
    }
};