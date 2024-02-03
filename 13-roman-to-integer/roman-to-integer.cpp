class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> um;
        um.insert({'I',1});
        um.insert({'V',5});
        um.insert({'X',10});
        um.insert({'L',50});
        um.insert({'C',100});
        um.insert({'D',500});
        um.insert({'M',1000});

        int res=um[s[s.length()-1]];
        for(int i=s.length()-2;i>=0;i--)
        {
            if(um[s[i]]<um[s[i+1]])
            {
                res-=um[s[i]];
            }
            else
            {
                res+=um[s[i]];
            }
        }
        return res;
    }
};