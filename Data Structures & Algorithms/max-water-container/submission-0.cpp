class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        int water = 0;
        int distance = 0;

        while (left < right){
            distance = right - left;

            water = distance * (min(height[left], height[right]));
            if (water > maxWater){
                maxWater = water;
            }

            if (height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};