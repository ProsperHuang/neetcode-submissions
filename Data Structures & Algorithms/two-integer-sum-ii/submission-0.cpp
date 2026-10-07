class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while (numbers[left] + numbers[right] != target){
            while (numbers[left] + numbers[right] > target){
                right--;
            }
            while (numbers[left] + numbers[right] < target){
                left++;
            }
        }
        
        return {left+1, right+1};
    }
};