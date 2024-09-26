class Solution {
public:

    void dfs(int r,int c,vector<vector<int>> &ans,vector<vector<int>> &image,int Ncolor,int iniC,int delR[],int delC[])
    {
        ans[r][c]=Ncolor;
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nRow=r+delR[i];
            int nCol=c+delC[i];
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && image[nRow][nCol]==iniC && ans[nRow][nCol]!=Ncolor)
            {
                dfs(nRow,nCol,ans,image,Ncolor,iniC,delR,delC);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int iniC=image[sr][sc];
        vector<vector<int>> ans=image;
        int delR[]={-1,0,+1,0};
        int delC[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,color,iniC,delR,delC);

        return ans;

        
    }
};