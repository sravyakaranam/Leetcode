class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> flip(n, 0); 
        int currentFlips = 0; 
        int result = 0; 

        for (int i = 0; i < n; i++) {
            
            if (i >= k) currentFlips -= flip[i - k]; 
            
            
            if ((nums[i] + currentFlips) % 2 == 0) { 
                if (i > n - k) return -1; 
                result++;
                currentFlips++; 
                flip[i] = 1; 
            }
        }
        
        return result;
        
    }
};