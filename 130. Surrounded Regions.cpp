class Solution {
public:
    void check(vector<vector<char>>& board, int i, int j, int row, int col){
        if(board[i][j] == 'O'){
            board[i][j] ='1';
            if( i > 1)          //往上
                check(board, i - 1, j, row, col);
            if( j > 1)          //往左
                check(board, i, j-1, row, col);
            if( i +1 < row)     //往下
                check(board, i + 1, j, row, col);
            if( j + 1 < col)    //往上
                check(board, i , j + 1, row, col);
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(!row)
            return ;
        int col = board[0].size();
        if(!col || row == 1 || col == 1)
            return ;
        int i, j;     
        
        for( i = 0; i < board.size(); i++){
            check(board, i, 0, row, col);
            if(col > 1)
                check(board, i, col - 1, row, col);
        }
        
        for( j = 0; j < board[0].size(); j++){
            check(board, 0, j, row, col);
            if(row > 1)
                check(board, row - 1, j, row, col);
        }
        
        for( i = 0; i < row; i++)
            for(j = 0; j < col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        
        return ;
    }
};