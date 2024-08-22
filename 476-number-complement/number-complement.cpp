class Solution {
public:
    int findComplement(int num) {

        string temp="";
        int n=num;

        while(n!=0)
        {
            int s=n%2;
            temp=temp+to_string(s);
            n=n/2;
        }
        cout<<temp<<endl;
        string res="";
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i]=='1')res+='0';
            else if(temp[i]=='0')res+='1';
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
        return stoi(res,0,2);
    }
};