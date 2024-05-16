class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> mpr;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                if(mp[s[i]]!=t[i]){
                    cout<<mp[s[i]]<<" ";
                    return false;}
                
            }
            else
            {
                mp[s[i]]=t[i];
            }
        }
        for(int i=0;i<t.length();i++)
        {
            if(mpr.find(t[i])!=mpr.end())
            {
                if(mpr[t[i]]!=s[i]){
                    cout<<mpr[t[i]]<<" ";
                    return false;}
                
            }
            else
            {
                mpr[t[i]]=s[i];
            }
        }
        return true;
    }
};