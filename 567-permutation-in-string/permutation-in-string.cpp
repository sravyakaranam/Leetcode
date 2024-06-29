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
    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> res;
        unordered_map<char, int> countP, countTemp;
        for (char c : s1) {
            countP[c]++;
        }

        int left = 0;
        for (int right = 0; right < s2.length(); ++right) {
            countTemp[s2[right]]++;

            // Maintain the window size
            if (right - left + 1 > s1.size()) {
                if (countTemp[s2[left]] == 1) {
                    countTemp.erase(s2[left]);  // Remove char completely if count is 1
                } else {
                    countTemp[s2[left]]--;  // Decrease count
                }
                left++;
            }

            if (right - left + 1 == s1.size()) {
                if (isAnagram(countP, countTemp)) {
                    return true;
                }
            }
        }

        return false;
    }
};