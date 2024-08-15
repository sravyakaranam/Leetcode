class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0;
        int c10=0;
        //int c20=0;
        bool flag=true;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                c5++;
            }
            else if(bills[i]==10)
            {
                c10++;
                if(c5>0)
                {
                    c5--;
                }
                else
                {
                    flag=false;
                }
            }
            else if(bills[i]==20)
            {
               // c20++;
                if(c10>0 and c5>0)
                {
                    c10--;
                    c5--;
                }
                else if(c5>=3)
                {
                    c5=c5-3;
                }
                else 
                {
                    flag=false;
                }

            }
        }
        return flag;
    }
};