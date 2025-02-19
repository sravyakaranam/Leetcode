class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {


        vector<vector<int>> graph(numCourses);
        vector<int> res;

        vector<int> indegree(numCourses,0);

        for(auto pre:prerequisites)
        {
            int course=pre[0];
            int req=pre[1];
            graph[req].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            res.push_back(curr);
            for(auto a:graph[curr])
            {
                indegree[a]--;
                if(indegree[a]==0)q.push(a);
            }
        }
        vector<int> t;
        return res.size()<numCourses?t:res;
        
    }
};