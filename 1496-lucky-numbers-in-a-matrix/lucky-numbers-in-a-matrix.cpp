class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMin(m, INT_MAX);
        vector<int> colMax(n, INT_MIN);
       
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                
            }
            cout<<rowMin[i]<<" ";
        }
        cout<<endl;
        
        for(int j = 0; j < n; ++j){
            for(int i = 0; i < m; ++i){
                colMax[j] = max(colMax[j], matrix[i][j]);
                
            }
            cout<<colMax[j]<<" ";
        }
        cout<<endl;

        vector<int> luckyNumbers;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]){
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }
        return luckyNumbers;
    }
};