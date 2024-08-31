class Solution {
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, 
                          std::vector<double>& succProb, int start, int end) {
        // Create adjacency list
        std::vector<std::vector<std::pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);  // Undirected graph
        }

        // Initialize probabilities
        std::vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        // Priority queue to store {probability, node}
        std::priority_queue<std::pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end) return prob;

            for (const auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0;  // If end is not reachable
    }
};