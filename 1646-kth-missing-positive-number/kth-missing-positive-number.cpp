class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        vector<int> missing;  // This will store the missing numbers

        int n = arr.size();  // Length of the input array
        int expected = 1;    // The expected number at each step
        int i = 0;           // Index to traverse arr
        
        // Traverse through all expected numbers up to the largest in arr
        while (i < n && missing.size() < k) {
            if (arr[i] != expected) {
                missing.push_back(expected);  // Add missing number to the list
            } else {
                i++;  // Move to the next element in arr
            }
            expected++;  // Increment the expected number
        }
        
        // If we still need more missing numbers after exhausting the array
        while (missing.size() < k) {
            missing.push_back(expected);
            expected++;
        }
        
        return missing[k - 1]; 
    }
};