class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();
        int su=0;
        int mini=INT_MAX;
        int l=0;
        for(int r=0;r<n;r++)
        {
            su=su+nums[r];
            while(su>=target)
            {
                mini=min(mini,r-l+1);
                su=su-nums[l];
                l++;
            }
        }
        return (mini==INT_MAX)?0:mini;
    }
};