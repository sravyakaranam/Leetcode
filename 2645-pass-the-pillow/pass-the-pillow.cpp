class Solution {
public:
    int passThePillow(int n, int time) {

        if(time==n-1)return n;
        int res;
        int time_for_one=time/(n-1);
        cout<<time_for_one<<endl;
        if(time_for_one%2==0)
        {
            res=time-((n-1)*time_for_one)+1;
        }
        else
        {
            res=n-(time-((n-1)*time_for_one));
        }
        return res;
        
    }
};