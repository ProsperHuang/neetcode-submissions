class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> myMap;
        for (int i = 0; i<nums.size(); i++){
            myMap[nums[i]]++;
        }

        //copy entries to vector of pairs
        vector<pair<int, int>> entries(myMap.begin(), myMap.end());

        //sort by descending frequency. third parameter is a custom "lambda" param
        sort(entries.begin(), entries.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        //get top k keys
        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(entries[i].first);
        }
        return answer;
    }
};
