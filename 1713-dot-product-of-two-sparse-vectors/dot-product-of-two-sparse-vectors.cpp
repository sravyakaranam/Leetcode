class SparseVector {
public:
    
    vector<int> res;
    SparseVector(vector<int> &nums) {
            res=nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int out=0;
        for(int i=0;i<res.size();i++)
        {
            out+=vec.res[i]*res[i];
        }
        return out;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);