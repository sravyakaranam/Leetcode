class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Set distance to self to zero
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Fill initial distances based on edges
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Determine the city with the minimum number of reachable cities
        int minReachableCities = INT_MAX;
        int cityWithMinReachableCities = -1;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            // Check if this city has fewer reachable cities or if it's a tie and has a higher index
            if (count < minReachableCities || (count == minReachableCities && i > cityWithMinReachableCities)) {
                minReachableCities = count;
                cityWithMinReachableCities = i;
            }
        }
        
        return cityWithMinReachableCities;
    }
};