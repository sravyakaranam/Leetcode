class Solution {
    #define pii pair<int,int>
public:
    int countPalindromicSubsequence(string s) {

        int n=s.size();

        unordered_map<char,pii> mp;

        for(int i=0;i<n;++i)
        {
            if(!mp.count(s[i]))
            {
                mp[s[i]].first=mp[s[i]].second=i;
            }
            else
            {
                mp[s[i]].second=i;
            }
        }
        int res=0;

        for(auto [c,se]:mp)
        {
            if(se.first==se.second)continue;
            res+=unordered_set<char>(s.begin()+se.first+1,s.begin()+se.second).size();
        }
        return res;
    }
};