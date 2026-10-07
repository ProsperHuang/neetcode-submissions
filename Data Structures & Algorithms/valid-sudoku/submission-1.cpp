class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int row = 0; row<board.size(); row++){
            for (int col = 0; col<board[row].size(); col++){
                if (board[row][col] == '.'){
                    continue;
                }

                if (rows[row].count(board[row][col])){
                    return false;
                }
                rows[row].insert(board[row][col]);

                if (cols[col].count(board[row][col])){
                    return false;
                }
                cols[col].insert(board[row][col]);

                int box = (row / 3) * 3 + (col / 3);
                if (boxes[box].count(board[row][col])) {
                    return false;
                }
                boxes[box].insert(board[row][col]);                
            }
        }
        return true;
    }
};