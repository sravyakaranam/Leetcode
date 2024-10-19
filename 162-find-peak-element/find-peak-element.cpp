class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare the middle element with the next one
            if (nums[mid] > nums[mid + 1]) {
                // If the middle element is greater than the next, the peak is on the left side
                right = mid;
            } else {
                // If the next element is greater, the peak is on the right side
                left = mid + 1;
            }
        }

        // At the end, left == right, which is the peak element
        return right;
    }
};