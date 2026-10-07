class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){
            return false;
        }

        unordered_map <char, int> map;
        for (int i = 0; i<s.length(); i++){ //hashmap of string s's chars and count
            if (map.count(s[i])){
                map[s[i]]++;
            }
            else{
                map[s[i]]=1;
            }  
        }

        for (int j = 0; j<t.length(); j++){ //decrease count for each char in new word
            if (map.count(t[j])){
                map[t[j]]--;
                if (map[t[j]]<0){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        // for (int k = 0; k<s.length(); k++){
        //     if (map[s[k]]!=0){
        //         return false;
        //     }
        // }
        return true;
    }
};