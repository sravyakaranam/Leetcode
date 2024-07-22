class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int,string>> temp;
        vector<string> res;

        for(int i=0;i<names.size();i++)
        {
            temp.push_back({heights[i],names[i]});
        }

        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        for(auto n:temp)
        {
            res.push_back(n.second);
        }

        return res;
    }
};