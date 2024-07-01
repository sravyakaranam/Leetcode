class Solution {
public:
    bool isodd(unordered_map<int,int> vec)
    {
        bool flag=true;
        for(auto n:vec)
        {
            
            if(n.first%2==0){
                flag=false;
                break;
            }
        }
        
        return flag;
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        unordered_map<int,int> vec;
        for(int right=0;right<n;right++)
        {
            vec[arr[right]]++;
            if(right-left+1>3)
            {
                vec.erase(arr[left]);
                left++;
            }
            if(right-left+1==3)
            {
                cout<<isodd(vec)<<endl;
                if(isodd(vec))return true;
                //break;
            }
        }
        return false;
    }
};