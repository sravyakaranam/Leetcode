class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n=nums.size();
        int left=0;
        int zeroco=0;
        int maxi=0;
        int h=k;
        for(int right=0;right<n;right++)
        {
           
           if(nums[right]==0)zeroco++;

           while(zeroco>k)
           {
            if(nums[left]==0)zeroco--;

            left++;
           }
            maxi=max(maxi,right-left+1);
        }

        return maxi;
    }
};