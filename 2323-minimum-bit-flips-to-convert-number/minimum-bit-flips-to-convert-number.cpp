class Solution {
public:
    int minBitFlips(int start, int goal) {

        int re=start^goal;
        cout<<re<<endl;
        int out=0;
        //int rem;
        while(re>0)
        {
            out+=re&1;
            re=re>>1;
        }
        
        return out;
        
    }
};