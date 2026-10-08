class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> result;
        int lower = 0;
        int higher = numbers.size()-1;
        while (numbers[lower] + numbers[higher] != target){
            if (numbers[lower] + numbers[higher] > target){
                higher--;
            }
            if (numbers[lower] + numbers[higher] < target){
                lower++;
            }
        }
        result = {lower+1,higher+1};
        return result;
    }
};
