class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low_row = 0;
        int high_row = matrix.size()-1;
        int target_row = 0;

        while (low_row <= high_row){
            int mid_row = (high_row+low_row)/2;
    
            if (matrix[mid_row][0] == target){
                return true;
            }
            else if (matrix[mid_row][0] < target){
                low_row = mid_row+1;
            }
            else if (matrix[mid_row][0] > target){
                high_row = mid_row-1;
            }

            if (high_row < 0) {
                return false;
            }
            target_row = high_row;
        }

        int low_col = 0;
        int high_col = matrix[target_row].size()-1;
        
        while (low_col <= high_col){
            int mid_col = (high_col+low_col)/2;
            if (matrix[target_row][mid_col] == target){
                return true;
            }
            else if (matrix[target_row][mid_col] < target){
                low_col = mid_col+1;
            }
            else if (matrix[target_row][mid_col] > target){
                high_col = mid_col-1;
            }
        }

        return false;
    }
};
