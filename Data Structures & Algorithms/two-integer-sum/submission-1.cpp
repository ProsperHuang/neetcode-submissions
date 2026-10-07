class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> myMap;

        // insert all numbers into hashset first
        for (int i = 0; i < nums.size(); i++) {
            // if found
            if (myMap.find(target - nums[i]) != myMap.end()) {
                return {myMap[target - nums[i]], i};
            }
            // insert value and index into the map
            myMap[nums[i]] = i;
        }

        return {};
    }
};
