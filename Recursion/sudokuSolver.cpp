 class Solution {
private:
    bool isValid(vector<vector<char>>& board,int row,int col,char dig){
        for(int i = 0;i<9;i++){
            if(board[row][i] == dig) return false;
            if(board[i][col] == dig) return false;
        }
        int start_box_row = row/3 * 3;
        int start_box_col = col/3 *3;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(board[start_box_row + i][start_box_col + j] == dig) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i< 9; i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char dig = '1'; dig <= '9';dig++){
                        if(isValid(board,i,j,dig)){
                            board[i][j] = dig;
                            if(solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};