class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end()); // Get the maximum value from piles
        int res = right;

        while (left <= right) {
            int k = left + (right - left) / 2;
            long long hours = 0; // Use long long to prevent overflow

            for (int p : piles) {
                hours += (p + k - 1) / k; // Efficient ceiling of division without floating-point arithmetic
            }

            if (hours <= h) {
                res = std::min(res, k);
                right = k - 1;
            } else {
                left = k + 1;
            }
        }

        return res;
    }
};