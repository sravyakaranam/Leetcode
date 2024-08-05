class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }

        vector<string> ve;
        int co=0;
        for(auto m:arr)
        {
            if(mp[m]==1)
            {
                ve.push_back(m);
                co++;
            }
            
        }
        
        for(auto n:ve)
        {
            cout<<n<<endl;
        }
        if(co<k)return "";
        else return ve[k-1];
    }
};