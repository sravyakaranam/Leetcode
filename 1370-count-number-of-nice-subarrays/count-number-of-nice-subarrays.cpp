class Solution {
public:
    bool isodd(int s)
    {
        if(s%2==0)return false;
        else return true;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int left = 0;
        int oco=0;
        int res=0;
        int countExactK=0;
        for (int right = 0; right < n; right++) {
            if (isodd(nums[right]))
            {
                oco++;
            }
            while(oco>k)
            {
                if(isodd(nums[left]))
                {
                    oco--;
                }
                left++;
                mp[right]=right-left+1;
  
            }
            int tempLeft = left;
            int tempCount = oco;

            // Move tempLeft to find the exact start of subarrays with exactly k odds
            while (tempCount == k) {
                countExactK++;
                if (isodd(nums[tempLeft])) {
                    tempCount--;
                }
                tempLeft++;
            }


        }
        return countExactK;
    }
};