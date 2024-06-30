class Solution {
public:
    bool isgood(unordered_map<char,int> mp)
    {
        //bool flag=0;
        for(auto n:mp)
        {
            if(n.second!=1)
            {
                return false;
            }
        }
        return true;
    }
    int countGoodSubstrings(string s) {

        int left=0;
        int res=0;
        unordered_map<char,int> mp;
        for(int right=0;right<s.length();right++)
        {
            mp[s[right]]++;
            if(right-left+1>3)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)mp.erase(s[left]);
                
                left++;
            }
            if(right-left+1==3)
            {
                if(isgood(mp))
                {
                    res++;
                }
            }
        }
        return res;
        
    }
};