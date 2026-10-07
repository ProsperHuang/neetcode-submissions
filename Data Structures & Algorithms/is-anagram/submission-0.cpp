class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        std::unordered_map <char, int> myMap;
        for (int i = 0; i<s.length(); i++){
            if (!myMap.count(s[i])){
                myMap[s[i]] = 1;
            }
            else{
                myMap[s[i]]++;
            }
        }
        for (int i = 0; i<t.length(); i++){
            if (myMap.count(t[i])){
                myMap[t[i]]--;
                if (myMap[t[i]] < 0){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
