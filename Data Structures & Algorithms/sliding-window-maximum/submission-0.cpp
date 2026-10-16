class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> answer;

        //first k elements in monotonic order 
        for (int i = 0; i<k; i++){
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        answer.push_back(nums[dq.front()]);

        //now to the remaining after 1st window is done
        for (int i = k; i<nums.size(); i++){
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            answer.push_back(nums[dq.front()]);
        }

        return answer;
    }
};
