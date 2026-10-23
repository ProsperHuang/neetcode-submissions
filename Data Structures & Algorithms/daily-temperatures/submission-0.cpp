class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> stk;
        stack <int> indices;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i<temperatures.size(); i++){
            if (stk.empty()){
                stk.push(temperatures[i]);
                indices.push(i);
            }
            else {
                if (stk.top() < temperatures[i]){
                    while (!stk.empty() && stk.top() < temperatures[i]){
                        result[indices.top()] = i - indices.top();
                        stk.pop();
                        indices.pop();
                    }
                    stk.push(temperatures[i]);
                    indices.push(i);
                }
                else{
                    stk.push(temperatures[i]);
                    indices.push(i);
                }
            }
        }
        return result;
    }
};
