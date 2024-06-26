class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < k) return 0;
        long long su=0;
        
        long long maxi=INT_MIN;
        unordered_map<int, int> count;
        bool flag=0;
        int left=0;
        for(int right=0;right<nums.size();right++)
        {
            while(right-left+1>k)
            {
                su=su-nums[left];
                count[nums[left]]--;
                if (count[nums[left]] == 0) {
                    count.erase(nums[left]); 
                }
                left++;
                
            }
            su=su+nums[right];
            count[nums[right]]++;

            if (right - left + 1 == k && count.size() == k) {
                maxi=max(maxi,su);
                flag=1;
            }
            
        }

        return flag?maxi:0;
        
    }
};