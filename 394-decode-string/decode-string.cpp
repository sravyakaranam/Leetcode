class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;   
        stack<string> stringStack;
        string current = "";  
        int num = 0;          
        
        for (char c : s) {
            if (isdigit(c)) {  
                num = num * 10 + (c - '0');  
            } 
            else if (c == '[') {  
                
                countStack.push(num);
                stringStack.push(current);
                
                num = 0;
                current = "";
            } 
            else if (c == ']') {  
                
                string temp = current;  
                int repeat = countStack.top(); countStack.pop();  
                current = stringStack.top(); stringStack.pop();  

                
                while (repeat--) current += temp;
            } 
            else {  
                
                current += c;
            }
        }
        return current;
    }
};