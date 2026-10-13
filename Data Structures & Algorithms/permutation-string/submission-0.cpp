class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> s1_map;
        unordered_map <char, int> s2_map;
        int left = 0;
        for (int i = 0; i<s2.size(); i++){
            if (i<s1.size()){
                s1_map[s1[i]]++; //add s1 to map.
                s2_map[s2[i]]++; //add s2 to map.
            }
            else{
                s2_map[s2[left]]--;
                if (s2_map[s2[left]] == 0) {
                    s2_map.erase(s2[left]);
                }
                s2_map[s2[i]]++;
                left++;
            }

            //make sure you're checking the full s1 after it's put in the hashmap
            if ((i >= s1.size()-1) && (s1_map == s2_map)){
                return true;
            }
        }
        return false;
    }
};
