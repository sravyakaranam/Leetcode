class Solution {
public:
    int minOperations(vector<string>& logs) {

        int steps=0;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="../")
            {
                if(steps==0)continue;
                else steps--;
            }
            else if(logs[i]=="./")
            {
                continue;
            }
            else
            {
                steps++;
            }
        }
        return steps;
    }
};