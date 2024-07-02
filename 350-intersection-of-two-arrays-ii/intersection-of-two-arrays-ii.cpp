class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> res;
        if(n2<=n1)
        {
            unordered_map<int,int> mp1;
            
            for(int i=0;i<nums1.size();i++)
            {
                mp1[nums1[i]]++;
            }
            for(int i=0;i<nums2.size();i++)
            {
                if(mp1.find(nums2[i])!=mp1.end() && mp1[nums2[i]]!=0)
                {
                    //cout<<nums2[i]<<endl;
                    //cout<<mp1[nums2[i]]<<endl;
                    mp1[nums2[i]]--;
                    res.push_back(nums2[i]);
                }
            }
            //return res;
        }else
        {
            unordered_map<int,int> mp1;
            //vector<int> res;
            for(int i=0;i<nums2.size();i++)
            {
                mp1[nums2[i]]++;
            }
            for(int i=0;i<nums1.size();i++)
            {
                if(mp1.find(nums1[i])!=mp1.end() && mp1[nums1[i]]!=0 )
                {
                    //cout<<nums2[i]<<endl;
                    mp1[nums1[i]]--;
                    res.push_back(nums1[i]);
                }
            }
            
        }
        return res;
    }
};