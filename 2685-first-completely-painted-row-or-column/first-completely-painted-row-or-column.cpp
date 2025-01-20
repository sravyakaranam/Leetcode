class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

       
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] = {i, j};
            }
        }

        
        vector<int> rowCount(m, 0), colCount(n, 0);

        
        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            auto [row, col] = pos[val]; 

            rowCount[row]++;
            colCount[col]++;

            
            if (rowCount[row] == n || colCount[col] == m) {
                return i; 
            }
        }

        return -1; 
    }
};
