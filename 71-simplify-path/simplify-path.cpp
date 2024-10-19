class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string dir;
        stringstream ss(path);

        while(getline(ss, dir,'/'))
        {
            if(dir=="" || dir==".")
            {
                continue;
            }
            if(dir=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(dir);
            }
        }

        string res="";
        while(!st.empty())
        {
            res="/"+st.top()+res;
            st.pop();
        }
        return res.empty()?"/":res;
    }
};