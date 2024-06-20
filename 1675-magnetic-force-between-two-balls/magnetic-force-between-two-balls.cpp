class Solution {
public:
    bool posit(int force, vector<int> position,int m)
    {
        int prev=position[0];
        int co=1;
        for(int i=1;i<position.size();i++)
        {
            int curr=position[i];
            if(curr-prev>=force){prev=curr;
            co++;
            }
            if(co==m)break;
        }
        return co==m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
       int minD=1;
       int maxD=position[position.size()-1]-position[0];
        int result=0;
        while(minD<=maxD)
        {
            int force=minD+(maxD-minD)/2;
            if(posit(force,position,m))
            {
                result=force;
                minD=force+1;
            }
            else
            {
                maxD=force-1;
            }
        }
        return result;
        
    }
};