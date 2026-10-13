class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size(), 0);
        vector<int> right_max(height.size(), 0);

        left_max[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        right_max[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int water = 0;
        for (int j = 0; j<height.size(); j++){
            water += min(left_max[j],right_max[j]) - height[j];
        }

        return water;
    }
};
