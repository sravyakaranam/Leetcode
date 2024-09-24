class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> set1;
        //unordered_set<int> set2;
        int maxi=0;
        for(auto n:arr1)
        {
            string temp=to_string(n);
            for(int i=1;i<=temp.length();i++)
            {
                set1.insert(stoi(temp.substr(0,i)));
            }

        }
        for(auto m:arr2)
        {
            string temp2=to_string(m);
            for(int j=1;j<=temp2.length();j++)
            {
                int test=stoi(temp2.substr(0,j));
                if(set1.find(test)!=set1.end())
                {
                    maxi = max(maxi, (int)to_string(test).length());
                }
            }

        }
        return maxi;
    }
};