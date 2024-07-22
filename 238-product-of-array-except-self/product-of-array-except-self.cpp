class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());

        int leftpro=1;
        for(int i=0;i<nums.size();i++)
        {
            res[i]=leftpro;
            leftpro=leftpro*nums[i];
        }

        int rightpro=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            res[i]=res[i]*rightpro;
            rightpro=rightpro*nums[i];
        }
        return res;

    }
};