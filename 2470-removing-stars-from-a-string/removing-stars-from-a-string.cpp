class Solution {
public:
    string removeStars(string s) {

        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        string res(st.size(),' ');
        for(int i=st.size()-1;i>=0;i--)
        {
            res[i]=st.top();
            st.pop();
        }
        return res;
        
    }
};