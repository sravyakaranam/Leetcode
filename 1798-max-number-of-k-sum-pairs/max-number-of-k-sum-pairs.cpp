class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int res=0;
        int s=nums.size();
        int l=0;
        int r=s-1;
            while(l<r)
            {
               
                if(nums[l]+nums[r]==k)
                {
                    cout<<l<<":"<<r<<endl;
                    cout<<nums[l]<<":"<<nums[r]<<endl;
                    
                    res++;
                    l++;
                    r--;
                    cout<<l<<":"<<r<<endl;
                }
                else if(nums[l]+nums[r]<k)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
      
        return res;
        
    }
};