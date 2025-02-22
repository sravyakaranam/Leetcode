class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n=board.size();
        vector<int> ve(n*n+1,-1);
        bool ltor=true;
        int idx=1;
        for(int i=n-1;i>=0;i--)
        {
            if(ltor)
            {
                for(int j=0;j<n;j++)
                {
                    ve[idx++]=board[i][j];
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    ve[idx++]=board[i][j];
                }
            }
            ltor=!ltor;
        }
        vector<int> vis(n*n+1,0);
        queue<pair<int,int>> q;
        q.push({1,0});
        vis[1]=1;
        while(!q.empty())
        {
            auto[pos,rolls]=q.front();
            q.pop();
            if(pos==n*n)return rolls;
            for(int dice=1;dice<=6;dice++)
            {
                int next=pos+dice;
                if(next>n*n)continue;
                if(ve[next]!=-1)
                {
                    next=ve[next];
                }
                if(!vis[next])
                {
                    vis[next]=1;
                    q.push({next,rolls+1});
                }

            }
            
        }

        return -1;

        
    }
};