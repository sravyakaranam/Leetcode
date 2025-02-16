class Solution {
public:


    void bfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();

            for(auto d:dir)
            {
                int nx=x+d.first;
                int ny=y+d.second;

                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]=='1')
                {
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }


        
    }
    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int res=0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(vis[row][col]==0 && grid[row][col]=='1')
                {
                    res++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return res;
    }
};