class NumArray {
public:
    vector<int> temp;
    NumArray(vector<int>& nums) {

        temp=nums;
        
    }
    
    int sumRange(int left, int right) {
        int res=temp[left];
        for(int i=left+1;i<=right;i++)
        {
            res+=temp[i];
        }
        return res;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */