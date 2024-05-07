class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        vector<int> res(arr.size());
        int maxi=-1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            res[i]=maxi;
            maxi=max(arr[i],maxi);
        }
        return res;
    }
};