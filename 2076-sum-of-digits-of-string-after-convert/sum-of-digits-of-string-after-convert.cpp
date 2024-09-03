class Solution {
public:
    int getLucky(string s, int k) {
        unordered_map<char, int> mp;
        int st = 1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            mp[ch] = st;
            st++;
        }

        string res = "";
        for (auto t : s) {
            res += to_string(mp[t]);  // Convert each character to its mapped number string
        }

        int j = 0;
        while (j < k) {
            int out = 0;  
            for (auto l : res) {
                out += (l - '0');  
            }
            res = to_string(out); 
            j++;  
        }
       
        return stoi(res);  
    }
};