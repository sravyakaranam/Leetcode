class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n,0);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();  // Get index of the colder day
                st.pop();
                ans[idx] = i - idx;  // Calculate the difference in days
            }
            cout<<i<<endl;
            st.push(i);  // Push current day's index onto the stack
        }

        return ans;
        
    }
};