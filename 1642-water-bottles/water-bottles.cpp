class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int su=numBottles;
        int rem=numBottles%numExchange;
        int res=numBottles/numExchange;
        //cout<<res<<endl;
        //cout<<su<<endl;
        while(res>0)
        {
            su=su+res;
            res=res+rem;
            cout<<res<<":"<<rem<<endl;
            rem=res%numExchange;
            res=res/numExchange;
            
        }
        return su;
    }
};