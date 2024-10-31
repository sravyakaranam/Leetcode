class Solution {
public:
    
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        if(nums.empty())
        {
            res.push_back({lower,upper});
            return res;
        }
        int n=nums.size();
        int l=0;
        if(nums[0]>lower)
        {
            res.push_back({lower,nums[0]-1});
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]+1)
            {
                
                res.push_back({nums[i-1]+1,nums[i]-1});
            }  
        }
        if(nums[n-1]<upper)
        {
            res.push_back({nums[n-1]+1,upper});
        }

        return res;
        
    }
};