class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n=nums.size();
        int left=0;
        double maxi=0.0;
        double su=0.0;
        if(n<k)return 0;
        for(int i=0;i<k;i++)
        {
            su=su+nums[i];
           
        }
        double av=su/k;
        maxi=av;
        //su=0.0;
        cout<<su<<" "<<av<<endl;
        for(int right=k;right<n;right++)
        {
            while(right-left+1>k)
            {
                su=su-nums[left];
                su=su+nums[right];
                
                av=su/k;
                cout<<su<<" "<<av<<endl;
                left++;
                
            }
            maxi=max(maxi,av);
        }
        return maxi;
    }
};