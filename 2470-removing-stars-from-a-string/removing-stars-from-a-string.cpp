class Solution {
public:
    string removeStars(string s) {

        vector<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                if(!st.empty())
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back(s[i]);
            }
        }

       
        return string(st.begin(),st.end());
        
    }
};