class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> ans;

        for (string& s : strs) {
            array<int, 26> count = {0};
            for (char c : s){
                count[c - 'a']++;
            } 
            ans[count].push_back(move(s));
        }

        vector<vector<string>> result;
        for (auto& entry : ans) {
            result.push_back(move(entry.second));
        }

        return result;
    }
};
