class MinStack {
public:

    stack<int> minStack;
    stack<int> minS;
    MinStack() {
      
    }
    
    void push(int val) {
       minStack.push(val);
       if(minS.empty()||val<=minS.top())
       {
        minS.push(val);
       }
         
    }
    
    void pop() {
        if(minStack.empty())return;
        int v=minStack.top();
        minStack.pop();
        if(!minS.empty() && minS.top()==v)
        {
            minS.pop();
        }
        
    }
    
    int top() {
        return minStack.top();
        
    }
    
    int getMin() {
        
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */