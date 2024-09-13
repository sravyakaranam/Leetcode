class Solution {
public:
    int find(vector<int> arr,int le,int ri)
    {
        cout<<le<<","<<ri<<endl;
        int res=arr[le];
        for(int i=le+1;i<=ri;i++)
        {
            res=res^arr[i];
        }
        return res;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int m=queries.size();
        vector<int> out;
        for(auto m:queries)
        {
            int le=m[0];
            int ri=m[1];
            out.push_back(find(arr,le,ri));
        }
        int u=1^3;
        cout<<u<<endl;
        return out;
    }
};