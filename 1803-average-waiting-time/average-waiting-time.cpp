class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        int su=customers[0][0];
        double res=0.0;
        vector<int> store;
        for(auto m:customers)
        {
            if(su>=m[0])
            {
                su+=m[1];
                store.push_back(su-m[0]);
                cout<<su<<"this is sum"<<endl;
            }
            else
            {
                su=m[0]+m[1];

                store.push_back(su-m[0]);
                cout<<su<<"this is sum"<<endl;

            }
            
        }

        for(int i=0;i<store.size();i++)
        {
            cout<<store[i]<<endl;
            res+=store[i];
        }
        res=res/customers.size();

        return res;


        
    }
};