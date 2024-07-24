class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> output;
        unordered_map<int,int> mp;
        for(int i=0;i<mapping.size();i++)
        {
            mp[i]=mapping[i];
        }
        vector<pair<int,int>> out;
        unordered_map<int,int> mp2;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            int res=0;
            int mul=1;
            if(temp>=0 and temp<=9)
            {
                out.push_back({nums[i],mp[nums[i]]});
            }else{
            while(temp>0)
            {
                int t=temp%10;
                res=res+mp[t]*mul;
                mul=mul*10;
                temp=temp/10;
            }
            
            out.push_back({nums[i],res});
            }
            //mp2[nums[i]]=res;
            //cout<<res<<endl;

        }
        for(auto n:out)
        {
            cout<<n.first<<":"<<n.second<<endl;
           
        }
        sort(out.begin(),out.end(),[](const pair<int,int>& a, const pair<int,int>& b) {return a.second<b.second;});
        for(auto n:out)
        {
            //cout<<n.first<<":"<<n.second<<endl;
            output.push_back(n.first);
        }
        return output;
    }
};