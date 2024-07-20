class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {


        int ro_size=rowSum.size();
        int co_size=colSum.size();
        vector<vector<int>> res(ro_size,vector<int>(co_size, 0));
        int mi=INT_MAX;

        for(int i=0;i<ro_size;i++)
        {
            for(int j=0;j<co_size;j++)
            {
                if(rowSum[i]!=0 && res[i][j]==0)
                {
                    int temp=min(rowSum[i],colSum[j]);
                    res[i][j]=temp;
                    rowSum[i]=rowSum[i]-temp;
                    colSum[j]=colSum[j]-temp;
                }
            }
        }
        
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[0].size();j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }

        return res;
    }
};