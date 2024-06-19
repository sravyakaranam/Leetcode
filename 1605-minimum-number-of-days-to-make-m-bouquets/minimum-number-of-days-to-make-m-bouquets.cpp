class Solution {
public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if (bloomDay.empty() || bloomDay.size() < (long long)m * k) {
            return -1; 
        }

        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;  
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid;  
            } else {
                left = mid + 1;  
            }
        }
        return left;  
    }

    bool canMakeBouquets(const std::vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int day : bloomDay) {
            if (day <= days) {
                ++flowers;  
                if (flowers == k) {
                    ++bouquets;
                    flowers = 0;  
                    if (bouquets == m) return true;  
                }
            } else {
                flowers = 0; 
            }
        }
        return false;
    }
};