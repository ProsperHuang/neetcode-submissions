class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = {1};
        int prefix_result = 1;
        vector<int> suffix = {1};
        int suffix_result = 1;

        for (int i = 1; i<nums.size(); i++){
            prefix_result *= nums[i-1];
            prefix.push_back(prefix_result);
        }
        for (int j = nums.size(); j>1; j--){
            suffix_result *= nums[j-1];
            suffix.push_back(suffix_result);
        }

        vector<int> answer;
        for (int k = 0; k<nums.size(); k++){
            answer.push_back(prefix[k]*suffix[nums.size()-k-1]);
        }
        return answer;
    }
};