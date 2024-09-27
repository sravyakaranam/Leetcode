class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        
        // Push all rotten oranges to the queue and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // If there are no fresh oranges, return 0 (no time needed)
        if (fresh == 0) return 0;
        
        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // BFS to spread the rotting process
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    grid[nrow][ncol] = 2;  // Mark as rotten
                    fresh--;  // Reduce the count of fresh oranges
                }
            }
        }
        
        // If there are still fresh oranges left, return -1
        return fresh == 0 ? tm : -1;
    }
};
