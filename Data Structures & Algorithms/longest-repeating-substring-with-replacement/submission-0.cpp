class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char, int> count;
        int max_freq = 0;
        int left = 0;
        int longest = 0;
        for (int i = 0; i<s.size(); i++){
            int window_size = i-left+1;

            count[s[i]]++;
            max_freq = max(max_freq, count[s[i]]);

            while (max_freq+k < window_size){            
                count[s[left]]--;
                left++;
                window_size = i-left+1;
            }
            longest = max(longest, window_size);
        }

        return longest;
    }
};
