class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n=s.size();
        stack<int> st;
        vector<bool> to_rem(n,false);

       string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty()){
                st.pop();
                }
                else to_rem[i]=true;
             
            }
           
        }
        while(!st.empty())
        {
            to_rem[st.top()]=true;
            st.pop();
        }

        for(int i=0;i<n;i++)
        {
            if(!to_rem[i])res+=s[i];
        }
        
        return res;
    }
};