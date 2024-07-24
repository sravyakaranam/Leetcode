class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

       if (nums.size() < 3) return false; // Early return if not enough elements

    int first = INT_MAX, second = INT_MAX; // Use two variables to track the smallest and the second smallest element

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] <= first) {
            first = nums[i]; // Find the smallest element
        } else if (nums[i] <= second) {
            second = nums[i]; // Find the second smallest element
        } else {
            return true; // If we find a third element that is bigger than both `first` and `second`, return true
        }
    }

    return false; // Return false if no triplet found
        
    }
};