class Solution {
public:
     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<unordered_set<int>> ancestors(n);

        // Building the graph and indegree array
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // Topological sorting using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Propagate ancestors information to children
            for (int child : adj[node]) {
                // Insert all ancestors of the current node into each child
                ancestors[child].insert(node);
                ancestors[child].insert(ancestors[node].begin(), ancestors[node].end());
                
                // Decrement indegree and check if ready to process
                if (--indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        // Convert sets to the output format and sort
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i].assign(ancestors[i].begin(), ancestors[i].end());
            sort(result[i].begin(), result[i].end());
        }

        return result;
    }
};