/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Hash map to store original node -> cloned node mapping
        unordered_map<Node*, Node*> clones;
        
        // Queue for BFS traversal
        queue<Node*> q;
        q.push(node);

        // Clone the first node
        clones[node] = new Node(node->val);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Iterate through neighbors
            for (Node* neighbor : curr->neighbors) {
                if (clones.find(neighbor) == clones.end()) {
                    // Clone neighbor if not already cloned
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Add the cloned neighbor to the cloned node's neighbor list
                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];  // Return the clone of the given node
    }
};