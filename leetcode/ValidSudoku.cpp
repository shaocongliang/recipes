class Solution {
public:
    bool isValidRow(const int row, const int col, vector<vector<char>> &board) {
        for(int i = 0; i < 9; ++i) {
            if(i != col && board[row][i] == board[row][col]) {
                return false;
            }
        }
        return true;
    }
    bool isValidCol(const int row, const int col, vector<vector<char>> &board) {
        for(int i = 0; i < 9; ++i) {
            if(i != row && board[i][col] == board[row][col]) {
                return false;
            }
        }
        return true;
    }
    bool isValidCell(int m, int n, int row, const int col, vector<vector<char>> &board) {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if((i != m || j != n) && board[i+row*3][j+col*3] == board[m+row*3][n+col*3]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == '.'){
                    continue;
                }
                if(isValidRow(i, j, board) == false || isValidCol(i, j, board) == false || isValidCell(i%3,j%3,i/3,j/3,board) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};