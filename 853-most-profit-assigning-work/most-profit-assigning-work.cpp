class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        /*unordered_map<int,int> m;
        for(int i=0;i<difficulty.size();i++)
        {
            m[difficulty[i]]=profit[i];
        }
        
        vector<int> v;
        int maxi=0;
        int s=difficulty.size()-1;
        for(int i=0;i<worker.size();i++)
        {
            while(s>=0)
            {
                if(difficulty[s]<=worker[i])
                {
                    maxi=max(difficulty[s],maxi);
                }
                
                s--;
                
            }
            s=difficulty.size()-1;
            
            cout<<s<<" ";
            v.push_back(maxi);
            maxi=0;
        }
        cout<<"--------------"<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        int res=0;
        for(int i=0;i<v.size();i++)
        {
            if(m.find(v[i])!=m.end())
            {
                res=res+m[v[i]];
            }
        }
        return res;*/
        // Map to store the maximum profit for each difficulty
        unordered_map<int, int> maxProfitForDifficulty;
        
        // Fill the map with the maximum profit for each difficulty level
        for (int i = 0; i < difficulty.size(); i++) {
            if (maxProfitForDifficulty.find(difficulty[i]) == maxProfitForDifficulty.end())
                maxProfitForDifficulty[difficulty[i]] = profit[i];
            else
                maxProfitForDifficulty[difficulty[i]] = max(maxProfitForDifficulty[difficulty[i]], profit[i]);
        }
        
        // Sorting the worker array to use binary search later
        sort(worker.begin(), worker.end());

        // Create a vector to store the maximum profit up to each difficulty
        vector<pair<int, int>> maxProfitUpTo;
        for (auto& p : maxProfitForDifficulty) {
            maxProfitUpTo.push_back(p);
        }
        // Sort the difficulties
        sort(maxProfitUpTo.begin(), maxProfitUpTo.end());

        // Adjust the maxProfitUpTo to ensure it holds the maximum profit up to that difficulty
        for (int i = 1; i < maxProfitUpTo.size(); i++) {
            maxProfitUpTo[i].second = max(maxProfitUpTo[i-1].second, maxProfitUpTo[i].second);
        }

        // Function to find the maximum profit a worker can earn
        auto getMaxProfit = [&](int capability) {
            int low = 0, high = maxProfitUpTo.size() - 1;
            int bestProfit = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (maxProfitUpTo[mid].first <= capability) {
                    bestProfit = maxProfitUpTo[mid].second;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return bestProfit;
        };

        // Calculate the total profit for all workers
        int totalProfit = 0;
        for (int cap : worker) {
            totalProfit += getMaxProfit(cap);
        }

        return totalProfit;
    
    }
};