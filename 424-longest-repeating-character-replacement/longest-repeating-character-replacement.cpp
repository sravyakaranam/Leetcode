class Solution {
public:
int characterReplacement(string s, int k) {
        int maxCount = 0;  
        int maxLength = 0;  
        int l = 0;  
        unordered_map<char, int> charCount;  

        for (int r = 0; r < s.size(); ++r) {
            charCount[s[r]]++;
            maxCount = max(maxCount, charCount[s[r]]);

            
            while (r - l + 1 - maxCount > k) {
                
                charCount[s[l]]--;
                if (charCount[s[l]] == 0) {
                    charCount.erase(s[l]);
                }
                l++;
            }

            
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    
    
    }
};