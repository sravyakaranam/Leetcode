class Solution {
public:
    int po(int k) {
        return 1 << k;  
    }

    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false; 

        unordered_map<string, int> mp;  
        string temp = "";  

        int left = 0;  
        for (int right = 0; right < s.length(); right++) {
            temp.push_back(s[right]);  

            
            if (temp.size() > k) {
                temp.erase(0, 1);  
                left++;  
            }

            
            if (right - left + 1 == k) {
                mp[temp]++;
            }
        }

        
        cout << "Unique substrings found: " << mp.size() << endl;
        cout << "All possible substrings (2^k): " << po(k) << endl;

        
        return mp.size() == po(k);
    }
};