class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeros = 0;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i] == 0){
                zeros++;
            }
            else{
                product *= nums[i];
                if (zeros > 1){
                    break;
                }
            }
            
        }

        vector <int> answer(nums.size());
        for (int i = 0; i<nums.size(); i++){
            if (zeros > 1){
                answer[i] = 0;
            }
            else{
                if (zeros != 0){
                    if (nums[i] == 0){
                        answer[i] = product;
                    }
                    else{
                        answer[i] = 0;
                    }
                }
                else{
                    answer[i] = product/nums[i];
                }
            }
        }
        return answer;

    }
};