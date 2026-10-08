class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int start;
        int current;
        int length = 1;
        int longest = 0;


        for (int i = 0; i<nums.size(); i++){
            set.insert(nums[i]);
        }

        for (int i = 0; i<nums.size(); i++){
            if (!set.count(nums[i]-1)){ //if is a potential starter
                current = nums[i];
                while (set.count(current+1)){
                    current++;
                    length++;
                }
                if (length>longest){
                    longest = length;
                }
                length = 1;
            }
        }

        return longest;
    }
};
