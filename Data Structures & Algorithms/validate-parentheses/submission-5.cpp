class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2 != 0){
            return false;
        }

        stack <char> st;

        //push in open brackets
        //closing brackets must come in the reverse order of the open brackets
        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            //check if empty before st.top(), because closing bracket w/o opening reads empty stack
            else if (st.empty()) { 
                return false;
            }
            else if (c == ')' && st.top() != '('){
                return false;
            }    
            else if (c == '}' && st.top() != '{'){
                return false;
            }  
            else if (c == ']' && st.top() != '['){
                return false;
            }  
            else{ //closing bracket with valid opening bracket at the top of stack
                st.pop();
            }
        }

        return st.empty();
    }
};
