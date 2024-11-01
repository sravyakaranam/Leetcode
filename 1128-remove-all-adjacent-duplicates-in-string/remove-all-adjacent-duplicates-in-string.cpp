class Solution {
public:
    string removeDuplicates(string s) {
        string result;  // Acts as a stack

        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                // If the current character is the same as the last in result, remove it
                result.pop_back();
            } else {
                // Otherwise, add the current character to result
                result.push_back(c);
            }
        }

        return result;
    }
};