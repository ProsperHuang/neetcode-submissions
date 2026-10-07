class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        int largestCount = 0;

        //put vector into hashset
        unordered_set <int> mySet(nums.begin(), nums.end());

        //iterate through mySet not nums because it contains only unique numbers
        for (int num : mySet){
            if (!mySet.count(num-1)){
                int increment = 1;
                count = 1;

                while(mySet.count(num+increment)){
                    increment++;
                    count++;
                }
            }
            if (count > largestCount){
                largestCount = count;
            }
        }
        return largestCount;
    }
};