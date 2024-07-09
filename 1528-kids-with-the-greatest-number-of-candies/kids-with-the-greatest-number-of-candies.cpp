class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=0;
        vector<bool> res;
        for(int i=0;i<candies.size();i++)
        {
            maxi=max(maxi,candies[i]);
        }

        cout<<maxi<<endl;
        for(int i=0;i<candies.size();i++)
        {
            int temp=extraCandies+candies[i];
            if(temp>=maxi)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
            //maxi=max(maxi,candies[i]);
        }
        return res;
    }
};