class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int area;
        int max_area = 0;
        while (left < right){
            area = (right-left)*(min(heights[left],heights[right]));
            if (area>max_area){
                max_area=area;
            }
            if (heights[right]>=heights[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};
