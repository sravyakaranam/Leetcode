class Solution {
public:

    /*int isvalids(string s)
    {
        set<char> se;
        for(int i=0;i<s.size();i++)
        {
            se.insert(s[i]);
        }
        if(se.size()==s.size())return s.size();
        else return 0;
    }*/
    int lengthOfLongestSubstring(string s) {

       // unordered_map<int,int> mp;
       /* int ma=1;
        if(s.empty())return 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string str=s.substr(i,j-i+1);
                ma=max(ma,isvalids(str));
            }
            
            
        }
        return ma;*/

        if (s.empty()) return 0;

        unordered_set<char> charSet;
        int maxLength = 0;
        int l = 0;  

        for (int r = 0; r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                
                charSet.erase(s[l]);
                l++;
            }
            
            charSet.insert(s[r]);
            maxLength = max(maxLength, r - l + 1);  
        }

        return maxLength;
    }
};