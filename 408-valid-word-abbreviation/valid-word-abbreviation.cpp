class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {

        int wl=word.size();
        int abl=abbr.size();


        int i=0;
        int j=0;
        
        if(abl>wl)return false;
        //if(isdigit(abbr[0]))return false;
        while(i<abl && j<wl)
        {
            if(isdigit(abbr[i]))
            {
               
                if(abbr[i]=='0')return false;
                int num=0;
                while(i<abl && isdigit(abbr[i]))
                {
                    num=num*10+(abbr[i]-'0');
                    i++;
                }
                j=j+num;
                if (j > wl) return false; 
            }
            else
            {
                if( j>=wl || abbr[i]!=word[j])return false;
                i++;
                j++;
            }
        }


        return i==abl && j==wl;
    }
};