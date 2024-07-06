class Solution {
public:
    int passThePillow(int n, int time) {

        if(time==n-1)return n;
        int res;
        int full_traversals = time/(n-1);

        if(full_traversals%2==0)
        {
            res=time-((n-1)*full_traversals)+1;
        }
        else
        {
            res=n-(time-((n-1)*full_traversals));
        }
        return res;
        
    }
};