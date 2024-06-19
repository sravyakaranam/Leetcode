class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ma=0;
        int mi=INT_MAX;
        for(int i=0;i<prices.size()-1;i++)
        {

            if(prices[i+1]>prices[i])
            {
                mi=min(prices[i],mi);
                int dif=prices[i+1]-mi;
                ma=max(ma,dif);
            }
            
        }
        return ma;
    }
};