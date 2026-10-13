class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> seen;
        int left = 0;
        int counter = 0;
        int longest = 0;

        for (int right = 0; right<s.size(); right++){
            while (seen.count(s[right])){
                seen.erase(s[left]);
                left++;
                counter--;
            }
            seen.insert(s[right]);
            counter++;
            if (counter>longest){
                longest = counter;
            }
        }
        return longest;
    }
};
