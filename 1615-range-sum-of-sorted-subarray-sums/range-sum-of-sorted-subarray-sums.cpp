class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySums;  // Vector to store all subarray sums
        // Calculate all subarray sums
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }

        // Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());

        // Compute the sum of the sums from index 'left' to 'right'
        // Adjust indices because 'left' and 'right' are 1-based
        int result = 0;
        int mod = 1e9 + 7;  // To handle large results
        for (int i = left - 1; i < right; ++i) {
            result = (result + subarraySums[i]) % mod;
        }

        return result;
    }
};