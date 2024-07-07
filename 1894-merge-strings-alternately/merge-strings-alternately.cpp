class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int l1=word1.length();
        int l2=word2.length();
        int i=0,j=0;
        while(i<l1 && j<l2)
        {
            res+=word1[i++];
            res+=word2[j++];
        }
        while(i<l1)
        {
            res+=word1[i++];
        }
        while(j<l2)
        {
            res+=word2[j++];
        }

        return res;
        
    }
};