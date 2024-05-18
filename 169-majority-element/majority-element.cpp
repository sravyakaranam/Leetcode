class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int maxi=0;
        int res;
        for(auto n:mp)
        {
            if(maxi<n.second)
            {
                maxi=n.second;
                res=n.first;
            }
        }
        return res;
        
    }
};