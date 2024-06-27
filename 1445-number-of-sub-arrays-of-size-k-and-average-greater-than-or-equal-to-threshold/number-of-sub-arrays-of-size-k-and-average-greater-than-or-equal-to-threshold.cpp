class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int n=arr.size();
        int left=0;
        int su=0;
        int av=0;
        int count=0;
        for(int right=0;right<n;right++)
        {
            su=su+arr[right];
            if(right-left+1 > k)
            {
                su=su-arr[left];
                left++;
            }
            if(right-left+1 == k)
            {
                av=su/k;
                if(av >= threshold)
                {
                    count++;
                }
            }
        }
        return count;
    }
};