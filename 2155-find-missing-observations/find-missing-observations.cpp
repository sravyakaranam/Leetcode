class Solution {
public:
   
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum_rolls = accumulate(rolls.begin(), rolls.end(), 0);
        int total_sum_required = (m + n) * mean;
        int sum_missing = total_sum_required - sum_rolls;
        
       
        if (sum_missing < n || sum_missing > 6 * n) {
            return {};
        }
        
        
        vector<int> res(n, 1);  
        sum_missing -= n; 

        for (int i = 0; i < n && sum_missing > 0; ++i) {
            int add = min(5, sum_missing);  
            res[i] += add;
            sum_missing -= add;
        }
        
        return res;
        
    }
};



