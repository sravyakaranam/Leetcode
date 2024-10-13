class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;  // Stack to store indices of '('
        string res = "";
        vector<bool> to_remove(n, false);  // Keeps track of indices to remove
        
        // First pass: Mark invalid parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);  // Push index of '(' to stack
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();  // There's a matching '(' so pop from stack
                } else {
                    to_remove[i] = true;  // Mark this ')' for removal
                }
            }
        }

        // Mark unmatched '(' left in the stack for removal
        while (!st.empty()) {
            to_remove[st.top()] = true;
            st.pop();
        }

        // Second pass: Build the result string
        for (int i = 0; i < n; i++) {
            if (!to_remove[i]) {
                res += s[i];  // Only add valid characters
            }
        }

        return res;
    }
};
