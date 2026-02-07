class Solution {
public:
    bool solved = false;
    bool isCorrectNum(vector<vector<char>> &board, int row, int col, char dig){
        //horizontal check
        for(int j=0; j<9; j++){
            if(board[row][j] == dig) return false;
        }
        //vertical check
        for(int i=0; i<9; i++){
            if(board[i][col] == dig) return false;
        }
        // individual 3x3 box check
        int rs = (row/3)*3;
        int cs = (col/3)*3;
        for(int i=rs; i <= rs+2; i++){
            for(int j=cs; j <= cs+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }
    void setNumber(vector<vector<char>> &board, int row, int col) {
        if (row == 9) {
            solved = true;
            return;
        }

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.') {
            setNumber(board, nextRow, nextCol);
            return;
        }

        for (char dig = '1'; dig <= '9'; dig++) {
            if (isCorrectNum(board, row, col, dig)) {
                board[row][col] = dig;
                setNumber(board, nextRow, nextCol);

                if (solved) return;   // manual early stop
                board[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        setNumber(board, 0, 0);
    }
};