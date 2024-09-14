class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Find the maximum value in the array
        int maxElement = *max_element(nums.begin(), nums.end());
        int maxLength = 0, currentLength = 0;

        // Traverse the array to find the longest subarray of maximum values
        for (int num : nums) {
            if (num == maxElement) {
                currentLength++; // Increment length if current element is max
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 0; // Reset length if the current element is not max
            }
        }
        return maxLength;
    }
};
