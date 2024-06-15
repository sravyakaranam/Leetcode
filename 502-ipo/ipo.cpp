class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /*int res=0;
        int maxi=0;
        
        unordered_map<int,int> m;
        for(int i=0;i<profits.size();i++)
        {
            m[capital[i]]=profits[i];
        }
        while(k--)
        {
            
            if(m.find(w)!=m.end())
            {
                res+=m[w];
                w=m[w];
            }
        }
        return res;*/
        struct MaxHeapComparator {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.first < b.first; 
            }
        };
        struct MinHeapComparator {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.first > b.first; 
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, MinHeapComparator> minheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, MaxHeapComparator> maxheap;

        for(int i=0;i<profits.size();i++)
        {
            minheap.push({capital[i],profits[i]});
        }

        for(int i=0;i<k;i++)
        {
            while(!minheap.empty() && minheap.top().first<=w)
            {
                auto [c,p]=minheap.top();
                minheap.pop();
                maxheap.push({p,c});
            }

            if(maxheap.empty())
            {
                break;
            }

            w+=maxheap.top().first;
            maxheap.pop();

        }
        return w;
    }
};