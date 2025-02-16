class Solution {
public:
    void bfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &grid)
    {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        q.push({r,c});
        vis[r][c]=1;
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(auto d:dir)
            {
                int nx=x+d.first;
                int ny=y+d.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]=='O')
                {
                    vis[nx][ny]=1;
                    //grid[nx][ny]='X';
                    q.push({nx,ny});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && !vis[i][0])bfs(i,0,vis,board);
            if(board[i][n-1]=='O' && !vis[i][n-1])bfs(i,n-1,vis,board);
        }
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O' && !vis[0][j])bfs(0,j,vis,board);
            if(board[m-1][j]=='O' && !vis[m-1][j])bfs(m-1,j,vis,board);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};