class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        long long val=1;

        vector<int> degree(n,0);
        for(auto edge:roads)
        {
            int u=edge[0];
            int v=edge[1];
            degree[u]++;
            degree[v]++;
        }
        sort(degree.begin(),degree.end());

        for(auto deg:degree)
        {
            ans+=val*deg;
            val++;
        }

        return ans;
    }
};