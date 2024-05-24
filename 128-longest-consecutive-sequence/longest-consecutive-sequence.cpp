class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int co=1;
        int maxi=1;
        if(nums.size()==0)
        {
            return 0;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
           
            if(nums[i+1]-nums[i]==1)
            {
                co++;
                if(co>maxi)
                {
                    maxi=co;
                }
            }
            else if(nums[i+1]==nums[i])
            {
                continue;
            }
            else
            {
                co=1;
                
            }
        }
        return maxi;
    }
};