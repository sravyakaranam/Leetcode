class Solution {
public:
    int minKnightMoves(int x, int y) {

        x=abs(x);
        y=abs(y);

        vector<pair<int, int>> directions = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        queue<tuple<int,int,int>> q;
        q.push({0,0,0});

        set<pair<int,int>> visited;
        visited.insert({0,0});

        while(!q.empty())
        {
            auto[cx,cy,steps]=q.front();
            q.pop();

            if(cx==x && cy==y)return steps;

            for(auto [dx,dy]:directions)
            {
                int nx=cx+dx;
                int ny=cy+dy;

                if(nx>=-1 && ny>=-1 && visited.find({nx,ny})==visited.end())
                {
                    visited.insert({nx,ny});
                    q.push({nx,ny,steps+1});
                }

            }
        }

        return -1;
    }
};