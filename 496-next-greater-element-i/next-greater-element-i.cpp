class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        vector<int> ans;

        // Iterate through nums2 and fill map with the next greater element for each number
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        // As there might be elements without a greater next element, map them to -1
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }

        // Map the result from nums1 based on computed values for nums2
        for (int num : nums1) {
            ans.push_back(m[num]);
        }

        return ans;
        
    }
};