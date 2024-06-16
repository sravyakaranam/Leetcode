class Solution {
public:
    /*void generatesubsetsum(int idx,vector<int> &nums,int numsize,vector<int> &res,int sum)
    {
        if(idx==numsize)
        {
            res.push_back(sum);
            return;
        }
        generatesubsetsum(idx+1,nums,numsize,res,sum+nums[idx]);
        generatesubsetsum(idx+1,nums,numsize,res,sum);
    }
    vector<int> subsetsum(vector<int>& nums)
    {
        vector<int> res;
        int numsize=nums.size();
        generatesubsetsum(0,nums,numsize,res,0);
        sort(res.begin(),res.end());
        return res;
    }*/
    int minPatches(vector<int>& nums, int n) {
        long long max_reach = 0;  
        int patches = 0;          
        int i = 0;                

        while (max_reach < n) {
            if (i < nums.size() && nums[i] <= max_reach + 1) {
                
                max_reach += nums[i++];
            } else {
                
                max_reach += max_reach + 1;
                patches++;  
            }
        }

        return patches; 
            
    }
};