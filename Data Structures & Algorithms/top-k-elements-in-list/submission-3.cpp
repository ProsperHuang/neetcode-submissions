class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int i = 0; i<nums.size(); i++){
            map[nums[i]]++;
            
        }

        vector<vector<int>> frequency(nums.size());
        for (auto pair : map) {
            int number = pair.first;
            int count = pair.second;
            frequency[count-1].push_back(number);
        }
        
        vector<int> answer;
        for (int j = frequency.size() - 1; j >= 0; j--) {
            for (int number : frequency[j]) {
                answer.push_back(number);

                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};