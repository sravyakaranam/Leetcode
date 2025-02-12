#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> leftHeap, rightHeap;
        int left = 0, right = costs.size() - 1;
        long long totalCost = 0;

        // Step 1: Fill initial heaps from both ends
        while (left < candidates) {
            leftHeap.push(costs[left++]);
        }
        while (right >= left && right >= costs.size() - candidates) {
            rightHeap.push(costs[right--]);
        }

        // Step 2: Hire `k` workers
        while (k--) {
            // Step 3: Pick the cheapest worker
            if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                totalCost += leftHeap.top();
                leftHeap.pop();
                // Add new left candidate if possible
                if (left <= right) {
                    leftHeap.push(costs[left++]);
                }
            } else {
                totalCost += rightHeap.top();
                rightHeap.pop();
                // Add new right candidate if possible
                if (left <= right) {
                    rightHeap.push(costs[right--]);
                }
            }
        }

        return totalCost;
    }
};
