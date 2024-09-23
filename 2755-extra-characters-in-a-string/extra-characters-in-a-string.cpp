class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dict(dictionary.begin(), dictionary.end()); // Dictionary for fast lookup
        vector<int> dp(n + 1, n); // dp[i] stores the minimum extra characters in s[0..i-1]
        
        dp[0] = 0; // No extra characters in an empty string
        
        // Iterate through the string
        for (int i = 1; i <= n; i++) {
            // Initialize dp[i] as if the current character s[i-1] is an extra character
            dp[i] = dp[i - 1] + 1;
            
            // Try all possible substrings ending at position i-1
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dict.count(word)) { // If the substring is in the dictionary
                    dp[i] = min(dp[i], dp[j]); // Update dp[i] considering this word
                }
            }
        }
        
        return dp[n];
    }
};
