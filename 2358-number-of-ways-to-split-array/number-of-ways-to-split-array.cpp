class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int res=0;
        long long int s2=0;

        for(int i=0;i<nums.size();i++)
        {
            s2+=nums[i];
        }
        long long int s1=0;
        for(int j=0;j<nums.size()-1;j++)
        {
            s1+=nums[j];
            long long int temp=s2-s1;
            if(s1>=temp)
            {
                res++;
            }
        }
        return res;
    }
};