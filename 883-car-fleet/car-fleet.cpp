class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={position[i],(double)(target-position[i])/speed[i]};
        }
        //sort(v.begin(),v.end());
        //reverse(v.begin(),v.end());
        sort(v.begin(), v.end());
        stack<double> s;
        
        for (int i = n - 1; i >= 0; --i) {
            // If current car arrives sooner than the last car in the stack
            // it joins that fleet, so we do not count it as a new fleet.
            if (s.empty() || v[i].second > s.top()) {
                s.push(v[i].second);
            }
        }
        
        return s.size();
    }
};