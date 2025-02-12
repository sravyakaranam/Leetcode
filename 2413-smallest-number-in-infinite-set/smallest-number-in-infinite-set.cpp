class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> inHeap;
    int nextSmallest;

    SmallestInfiniteSet() {
        nextSmallest = 1;  // Start from 1
    }
    
    int popSmallest() {
        if (!pq.empty()) {  
            int smallest = pq.top();  // Get the smallest number
            pq.pop();
            inHeap.erase(smallest);  // Remove from the set (mark as removed)
            return smallest;
        }
        
        return nextSmallest++;  // If heap is empty, return the next natural number
    }
    
    void addBack(int num) {
        if (num < nextSmallest && inHeap.find(num) == inHeap.end()) {
            pq.push(num);
            inHeap.insert(num);  // Track numbers present in the heap
        }
    }
};
