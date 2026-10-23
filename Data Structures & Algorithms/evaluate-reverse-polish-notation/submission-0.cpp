class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> stk;
        int left;
        int right; 
        for (string token : tokens){
            if (token == "+"){
                right = stk.top();
                stk.pop();
                left = stk.top();
                stk.pop();
                stk.push(left+right);
            }
            else if (token == "-"){
                right = stk.top();
                stk.pop();
                left = stk.top();
                stk.pop();
                stk.push(left-right);
            }
            else if (token == "*"){
                right = stk.top();
                stk.pop();
                left = stk.top();
                stk.pop();
                stk.push(left*right);
            }
            else if (token == "/"){
                right = stk.top();
                stk.pop();
                left = stk.top();
                stk.pop();
                stk.push(left/right);
            }
            else{
                stk.push(stoi(token));
            }

        }
        return stk.top();
    }
};
