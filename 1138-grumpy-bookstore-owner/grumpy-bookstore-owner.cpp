class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int res=0;
        int l=0;
        int r=0;
        int ws=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)res+=customers[i];
            if (i < minutes) {
                if (grumpy[i] == 1) {
                    ws += customers[i];
                }
            }
        }
        int maxi=ws;
        for(int i=minutes;i<n;i++)
        {
           if(grumpy[i]==1){
                    ws+=customers[i];
            }
            if(grumpy[i-minutes]==1){
                    ws-=customers[i-minutes];
            }
            maxi=max(maxi,ws);  
            
        }

        return maxi+res;

        
        
    }
};