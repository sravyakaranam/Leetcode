class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /**
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        return nums[k-1];**/

        priority_queue<int> max_heap;

        for(int n:nums)
        {
            max_heap.push(n);
        }
        while(k-1>0)
        {
            max_heap.pop();
            k--;
        }
        return max_heap.top();
        
    }
};