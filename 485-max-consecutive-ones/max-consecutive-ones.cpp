class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        //int left=0;
        int co=0;
        for(int r=0;r<nums.size();r++)
        {
            //cout<<nums[r]<<endl;
            if(nums[r]==1)
            {
                co++;
            }
            else if(nums[r]==0)
            {
                cout<<co<<endl;
                maxi=max(maxi,co);
                co=0;
            }
        }
        return max(maxi,co);
    }
};