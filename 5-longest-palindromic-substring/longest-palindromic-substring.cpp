class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
        {
            return s;
        }
        int max_length=1;
       
        int st=0,end=0;
        //int left=0,right=0;

        //if string length is odd
        for(int i=0;i<s.length()-1;++i)
        {
            int left=i;
            int right=i;
            while(left>=0 && right<s.length())
            {
                if(s[left]==s[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
            int length=right-left-1;
            if(max_length<length)
            {
                max_length=length;
                st=left+1;
            end=right-1;
            }
             
        }
        //if string length is even
        for(int i=0;i<s.length()-1;++i)
        {
            int left=i;
            int right=i+1;
            while(left>=0 && right<s.length())
            {
                if(s[left]==s[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
            int length=right-left-1;
            if(max_length<length)
            {
                max_length=length;
                st=left+1;
            end=right-1; 
            }
            
        }

        return s.substr(st,max_length);
    }
};