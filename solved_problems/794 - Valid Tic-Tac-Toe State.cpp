class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x_count, o_count, x_line, o_line;
        
        x_count = o_count = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X') x_count++;
                else if(board[i][j] == 'O') o_count++;
            }
        }
        
        if(o_count > x_count || x_count-1 > o_count) return false;
        
        x_line = countLine(board, 'X');
        
        if(x_line > 1) return false;
        
        o_line = countLine(board, 'O');
        
        if(x_line > 0 && o_line > 0) return false;
        
        if(x_line > 0 && x_count == o_count) return false;
        
        if(o_line > 0 && x_count != o_count) return false;
        
        return true;
    }
    
    int countLine(vector<string>& board, char sample){
        int line = 0;
        
        for(int i = 0; i < 3; i++){
            if((board[i][0] == sample) && (board[i][1] == sample) && (board[i][2] == sample)){
         line++;
                board[i][0] = board[i][1] = board[i][2] = ' ';
            }
            if((board[0][i] == sample) && (board[1][i] == sample) && (board[2][i] == sample)){
         line++;
         board[0][i] = board[1][i] = board[2][i] = ' ';
            }
        }
        
        if((board[0][0] == sample) && (board[1][1] == sample) && (board[2][2] == sample)){
         line++;
            board[0][0] = board[1][1] = board[2][2] = ' ';
            }
        else if((board[0][2] == sample) && (board[1][1] == sample) && (board[2][0] == sample)){
         line++;       
            }
        
        return line;
    }
};