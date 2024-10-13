class Solution {
public:
    bool isv(string sr,int l,int r)
    {
       

        while(l<=r)
        {
            if(sr[l]!=sr[r])return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
         int l=0;
        int r=s.size()-1;

        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                return isv(s,l+1,r)||isv(s,l,r-1);
            }
            l++;
            r--;

        }
        return true;
    }
    
};