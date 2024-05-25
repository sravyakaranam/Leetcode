class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            set<int> r,c;
            for(int j=0;j<columns;j++)
            {
                if(!r.insert(matrix[i][j]).second)return false;
                if(!c.insert(matrix[j][i]).second)return false;
            }
        }
        return true;
        
    }
};