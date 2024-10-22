class Solution {
public:
    int countl(vector<vector<int>>& matrix,int mid)
    {
        int n=matrix.size();

        int re=0;
        int r=n-1;
        int c=0;

        while(r>=0 && c<n)
        {
            if(matrix[r][c]<=mid)
            {
                c=c+1;
                re+=r+1;
            }
            else
            {
                r=r-1;
            }
        }
        return re;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int l=matrix[0][0];
        int r=matrix[n-1][n-1];

        while(l<r)
        {
            int mi=l+(r-l)/2;
            int co=countl(matrix,mi);
            if(co<k)l=mi+1;
            else r=mi;
        }

        return l;
        
    }
};