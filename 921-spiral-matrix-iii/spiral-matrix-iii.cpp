class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int totalCells = rows * cols;
        int x = rStart, y = cStart;
        result.push_back({x, y});
        
        int step = 0;
        int direction = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (result.size() < totalCells) {
            if (direction == 0 || direction == 2) {
                step++;
            }
            
            for (int i = 0; i < step; ++i) {
                x += directions[direction][0];
                y += directions[direction][1];
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    result.push_back({x, y});
                }
            }
            
            direction = (direction + 1) % 4;
        }
        
        return result;
    }
};
