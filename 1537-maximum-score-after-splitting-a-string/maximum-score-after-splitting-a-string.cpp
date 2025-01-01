class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        
        // Step 1: Calculate the total number of '1's in the string
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        // Step 2: Traverse the string and calculate the max score
        int leftZeros = 0, rightOnes = totalOnes;
        int maxScore = 0;
        
        // Iterate over the string, considering valid splits
        for (int i = 0; i < n - 1; i++) {
            // Update count of '0's on the left
            if (s[i] == '0') {
                leftZeros++;
            }
            // Update count of '1's on the right
            if (s[i] == '1') {
                rightOnes--;
            }
            // Calculate score for the current split
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        
        return maxScore;
    }
};
