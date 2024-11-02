class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            bool destroyed=false;
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0)
            {
                
                if(abs(asteroids[i])==abs(st.top()))
                {
                    st.pop();
                    destroyed=true;
                    break;
                }
                else if(abs(asteroids[i])<abs(st.top()))
                {
                    destroyed=true;
                    break;
                }
                else 
                {
                    st.pop();
                    
                }
            }
            if(destroyed==false)
            {
                st.push(asteroids[i]);
            }

        }
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};