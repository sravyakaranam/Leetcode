class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c1 = 0;  
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                c1++;
            }
        }
        if (c1 == 0) return 0; 

        vector<int> temp;
        int res = INT_MAX;  
        int left = 0; 
        int c0 = 0;  

        
        for (int i = 0; i < c1; i++) {
            temp.push_back(nums[i]);
            if (nums[i] == 0) {
                c0++;
            }
        }
        res = min(res, c0);  

       
        for (int right = c1; right < n + c1; right++) {
            
            if (nums[left] == 0) {
                c0--;
            }
            left++;

            
            int newIdx = right % n;  
            temp.push_back(nums[newIdx]);
            if (nums[newIdx] == 0) {
                c0++;
            }

            
            res = min(res, c0);
        }

        return res;
    }
};
