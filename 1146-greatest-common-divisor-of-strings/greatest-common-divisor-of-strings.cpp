class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        if (str1 == str2) {
            return str1;
        }
        
        if (str1.length() > str2.length()) {
            return gcdOfStrings(str1.substr(str2.length()), str2);
        } else {
            return gcdOfStrings(str2.substr(str1.length()), str1);
        }
        
    }
};