class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        long long res=0;
        vector<pair<int,int>> vp;
        long long s=0;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({nums2[i],nums1[i]});
        }
        sort(vp.rbegin(),vp.rend());
        priority_queue<int,vector<int>,greater<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp.push(vp[i].second);

            s+=vp[i].second;
            if(mp.size()>k)
            {
                s-=mp.top();
                mp.pop();
            }
            if(mp.size()==k)
            {
                res=max(res,s*vp[i].first);
            }

        }
        return res;

        
        
    }
};