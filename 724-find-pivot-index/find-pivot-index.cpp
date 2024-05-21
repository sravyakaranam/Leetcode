class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;

        // Compute total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Iterate to find the pivot index
        for (int i = 0; i < nums.size(); ++i) {
            // If left sum equals right sum, we found the pivot
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i]; // Update leftSum for the next iteration
        }

        return -1; // Return -1 if no pivot index is found
    }
};