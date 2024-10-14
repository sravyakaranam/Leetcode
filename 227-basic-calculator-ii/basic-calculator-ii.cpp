class Solution {
public:
    int cal(int a, int b, char op) {
        switch(op) {
            case '+': return b + a;
            case '-': return b - a;  // Important: b is first operand, a is second
            case '*': return b * a;
            case '/': return b / a;  // Important: b is first operand, a is second
            default: return 0;
        }
    }

    int priority(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }

    int calculate(string s) {
        stack<int> st1;  // Stack to hold the numbers
        stack<char> st2; // Stack to hold the operators
        int n = s.size();
        int num = 0;
        bool hasNum = false; // To track if we're processing a number

        for (int i = 0; i < n; i++) {
            char c = s[i];

            // If it's a digit, construct the number (for multi-digit numbers)
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                hasNum = true;
            }

            // If it's an operator or end of string, push the number to the stack
            if (!isdigit(c) && c != ' ' || i == n - 1) {
                if (hasNum) {
                    st1.push(num);
                    num = 0;
                    hasNum = false;
                }

                // If current char is an operator, process based on precedence
                if (!isdigit(c) && c != ' ') {
                    while (!st2.empty() && priority(st2.top()) >= priority(c)) {
                        int a = st1.top(); st1.pop();
                        int b = st1.top(); st1.pop();
                        char op = st2.top(); st2.pop();
                        st1.push(cal(a, b, op));
                    }
                    // Push the current operator to the stack
                    st2.push(c);
                }
            }
        }

        // After the loop, process any remaining operators
        while (!st2.empty()) {
            int a = st1.top(); st1.pop();
            int b = st1.top(); st1.pop();
            char op = st2.top(); st2.pop();
            st1.push(cal(a, b, op));
        }

        return st1.top();
    }
};
