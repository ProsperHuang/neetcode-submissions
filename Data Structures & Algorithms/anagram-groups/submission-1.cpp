class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> map;
        for (int i = 0; i<strs.size(); i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (pair<string, vector<string>> entry : map) {
            result.push_back(entry.second);
        }
        return result;
    }
};