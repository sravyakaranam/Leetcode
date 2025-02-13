class Solution {
public:
    int cal(int a, int b, const std::string& o)
    {
        if (o == "*") {
            return a * b;
        } else if (o == "+") {
            return a + b;
        } else if (o == "/") {
            if (b != 0) { 
                return a / b;
            } else {
                throw std::runtime_error("Division by zero.");
            }
        } else if (o == "-") {
            return a - b;
        } else {
            throw std::invalid_argument("Unsupported operation");
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(!s.empty() && (tokens[i]=="+" ||tokens[i]=="-" ||tokens[i]=="/" ||tokens[i]=="*"))
            {
                int b=stoi(s.top());
                s.pop();
                int a=stoi(s.top());
                s.pop();
                int re=cal(a,b,tokens[i]);
                s.push(to_string(re));

            }
            else{
                s.push(tokens[i]);
            }
            
        }
        return stoi(s.top());
    }
};