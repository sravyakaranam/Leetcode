class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, maxLen = 0;
        deque<int> maxDeque, minDeque;  // Deques to store indices of the elements

        for (int right = 0; right < nums.size(); ++right) {
            // Maintain decreasing deque for maximums
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain increasing deque for minimums
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Ensure the current window meets the limit condition
            while (!maxDeque.empty() && !minDeque.empty() && (nums[maxDeque.front()] - nums[minDeque.front()] > limit)) {
                left = min(maxDeque.front(), minDeque.front()) + 1;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};