class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(temp);
                temp="";
            }
            else if(s[i]==')')
            {
                reverse(temp.begin(),temp.end());
                if (!st.empty()) {
                    temp = st.top() + temp;  // Concatenate with what was before this parenthetical content
                    st.pop();
                }
               
            }
            else
            {
                temp+=s[i];
            }

        }
        

        return temp;
        
    }
};