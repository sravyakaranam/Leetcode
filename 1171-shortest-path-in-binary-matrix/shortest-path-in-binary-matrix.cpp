class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][0]==1 || grid[m-1][n-1]==1)
        {
            return -1;
        }
        int dir[][2]={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{-1,-1},{1,1}};
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        queue<vector<int>> q;
        q.push({0,0});
        vis[0][0]=true;
        int res=0;
        while(!q.empty())
        {
            int si=q.size();
            for(int i=0;i<si;i++)
            {
                auto curr=q.front();
                q.pop();
                if(curr[0]==m-1 && curr[1]==n-1)return res+1;
                for(int k=0;k<8;k++)
                {
                    int nextX=dir[k][0]+curr[0];
                    int nextY=dir[k][1]+curr[1];

                    if(nextX>=0 && nextX<m && nextY>=0 && nextY<n && !vis[nextX][nextY] && grid[nextX][nextY]==0)
                    {
                        q.push({nextX,nextY});
                        vis[nextX][nextY]=true;
                    }
                }
                
            }
            res++;

        }
        return -1;
        
        
        
    }
};