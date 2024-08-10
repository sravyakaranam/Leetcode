class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0) return;

        grid[x][y] = 1; // Mark this sub-cell as visited by setting it to 1
        // Move in all four possible directions
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        // Expand each cell into a 3x3 grid of sub-cells
        vector<vector<int>> expandedGrid(3 * n, vector<int>(3 * n, 0));

        // Populate the expanded grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    expandedGrid[3 * i][3 * j + 2] = 1;
                    expandedGrid[3 * i + 1][3 * j + 1] = 1;
                    expandedGrid[3 * i + 2][3 * j] = 1;
                } else if (grid[i][j] == '\\') {
                    expandedGrid[3 * i][3 * j] = 1;
                    expandedGrid[3 * i + 1][3 * j + 1] = 1;
                    expandedGrid[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }

        // Count the regions using DFS
        int regions = 0;
        for (int i = 0; i < 3 * n; ++i) {
            for (int j = 0; j < 3 * n; ++j) {
                if (expandedGrid[i][j] == 0) {
                    dfs(expandedGrid, i, j);
                    regions++; // Increment regions for each DFS call
                }
            }
        }

        return regions;
    }
};
