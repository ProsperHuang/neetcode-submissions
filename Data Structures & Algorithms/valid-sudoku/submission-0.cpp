class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set <char> mySet;
        //for rows
        for (int i = 0; i<board.size(); i++){
            for (int j = 0; j<board[0].size(); j++){
                if(board[i][j] != '.' && mySet.count(board[i][j])){
                    return false;
                }
                else{
                    mySet.insert(board[i][j]);
                }
            }
            mySet.clear();
        }
        mySet.clear();

        //for cols
        for (int i = 0; i<board.size(); i++){
            for (int j = 0; j<board[0].size(); j++){
                if(board[j][i] != '.' && mySet.count(board[j][i])){
                    return false;
                }
                else{
                    mySet.insert(board[j][i]);
                }
            }
            mySet.clear();
        }
        mySet.clear();

        //for boxes
        for (int i = 0; i<board.size()/3; i++){
            for (int j = 0; j<board[0].size()/3; j++){
                for (int k = 0; k<board.size()/3; k++){
                    for (int l = 0; l<board[0].size()/3; l++){
                        int row = i * 3 + k;
                        int col = j * 3 + l;
                        if(board[row][col] != '.' && mySet.count(board[row][col])){
                            return false;
                        }
                        else{
                            mySet.insert(board[row][col]);
                        }
                    }
                }
                mySet.clear();
            }
        }
        return true;
    }
};