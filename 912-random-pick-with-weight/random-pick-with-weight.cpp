class Solution {
private:
    vector<int> prefixSums;
    int totalSum;

public:
    // Constructor to initialize the prefix sum array
    Solution(vector<int>& w) {
        totalSum = 0;
        for (int weight : w) {
            totalSum += weight;
            prefixSums.push_back(totalSum);
        }
    }
    
    // Method to pick an index based on the weights
    int pickIndex() {
        int randomValue = rand() % totalSum + 1; // Random number between 1 and totalSum
        
        // Perform binary search on prefixSums to find the corresponding index
        int left = 0, right = prefixSums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSums[mid] < randomValue) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
