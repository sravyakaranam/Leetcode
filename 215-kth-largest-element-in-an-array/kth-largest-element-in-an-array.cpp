class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> mh;
        for(int i=0;i<nums.size();i++)
        {
            mh.push(nums[i]);
        }
        int p=k-1;
        while(p-- )
        {
            mh.pop();
        }

        return mh.top();
        
    }
};