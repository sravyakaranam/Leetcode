class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int,int>> v;
        for(int i=0;i<nums1.size();i++)
        {
            v.push_back({nums2[i],nums1[i]});
        }

        sort(v.rbegin(),v.rend());

        priority_queue<int,vector<int>,greater<int>> pq;

        int l=0;
        long long res=0;
        long long su=0;
        for(auto a:v)
        {
            pq.push(a.second);
            su+=a.second;
            l++;
            if(l>k)
            {
                l--;
                long long t=pq.top();
                su-=t;
                pq.pop();
            }
            if(l==k)res=max(res,a.first*su);
        }
        return res;
    }
};