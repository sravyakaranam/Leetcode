class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int m=sentence.size();
        int n=searchWord.size();
        int res=1;
        int i=0;
        while(i<m)
        {
            int start=i;
            while(i<m && sentence[i]!=' ')
            {
                i++;
            }
            string word=sentence.substr(start,i-start);

            if(word.size()>=n && word.substr(0,n)==searchWord)
            {
                return res;
            }
            res++;
            i++;
        }

        return -1;
    }
};