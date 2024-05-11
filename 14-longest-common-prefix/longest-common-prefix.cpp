class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n=strs[0].length();
       
        for(int i=0;i<n;i++)
        {
            for(string& s:strs){
                 if(i==s.length() || s[i]!=strs[0][i])
                {
                    return res;
                }
            }
            res=res+strs[0][i];
        }
        return res;
        
    }
};