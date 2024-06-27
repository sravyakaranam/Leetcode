class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        unordered_map<int,int> mp;
        int res;
        for(int i=0;i<edges.size();i++)
        {
            int v1=edges[i][0];
            int v2=edges[i][1];
            mp[v1]++;
            mp[v2]++;
            

        }
        for(auto n:mp)
        {
            if(n.second==edges.size())
            {
                res=n.first;
                break;
            }
        }

    return res;
        
    }
};