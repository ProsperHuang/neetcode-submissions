class MinStack {
public:
    stack<int> values;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        //push values into stack
        values.push(val);

        //push current min into another stack
        if (mins.empty()) {
            mins.push(val);
        }
        else {
            mins.push(min(val, mins.top()));
        }
    }
    
    void pop() {
        values.pop();
        mins.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
