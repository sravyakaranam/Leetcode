class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check row and column validity
        for (int i = 0; i < 9; i++) {
            set<char> rows, cols;
            for (int j = 0; j < 9; j++) {
                char row_val = board[i][j];
                char col_val = board[j][i];
                if (row_val != '.' && !rows.insert(row_val).second) return false;
                if (col_val != '.' && !cols.insert(col_val).second) return false;
            }
        }

        // Check 3x3 sub-boxes validity
        for (int block = 0; block < 9; block++) {
            set<char> block_vals;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char val = board[block / 3 * 3 + i][block % 3 * 3 + j];
                    if (val != '.' && !block_vals.insert(val).second) return false;
                }
            }
        }

        return true;
    }
};