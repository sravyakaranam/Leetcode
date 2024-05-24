class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxi=INT_MIN;
        while(left<=right)
        {
            int b=right-left;
            int l=min(height[left],height[right]);
            int area=l*b;
            cout<<area<<" ";
            if(area>maxi)
            {
                maxi=area;
            }
            if(height[left]<height[right])
            {
                left++;
            }
            else{
                right--;
            }
            
        }
        return maxi;
        
    }
};