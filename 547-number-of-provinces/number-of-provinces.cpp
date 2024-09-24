class Solution {
public:
    
    void dfs(vector<int>& v, vector<vector<int>>& adjl, int node) {
        v[node] = 1; 
        for (auto k : adjl[node]) {  
            if (v[k] == 0) {  
                dfs(v, adjl, k);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();  
        vector<vector<int>> adjl(V);  
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {  
                    adjl[i].push_back(j);
                }
            }
        }

        vector<int> v(V, 0);  
        int res = 0;  

       
        for (int i = 0; i < V; i++) {
            if (v[i] == 0) {  
                res++;
                dfs(v, adjl, i); 
            }
        }

        return res; 
    }
};
