class Solution {
public:
    int minSwaps(string s) {

        if(s.size()==0)return 0;
        int cc=0;
        int co=0;
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')co++;
            if(s[i]==']')cc++;

            
            if(cc>co)
            {
                res++;
                cc--;
                co++;
            }
          
        }

        return res;
        
    }
};