class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0 || word.length() == 0) return false;
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    board[i][j] = '.';
                    if(walk(board, m, n, i, j, word, 1)) return true;
                    board[i][j] = word[0];
                }
            }
        }
        
        return false;
    }
    
    bool walk(vector<vector<char>>& board, int& m, int& n, int x, int y, string& word, int l){
        
        if(l == word.length()){
            return true;
        }
        
        int next[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, nx, ny;
        
        for(int i = 0; i < 4; i++){
            nx = x + next[i][0], ny = y+ next[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == word[l]){
                board[nx][ny] = '.';
                if(walk(board, m, n, nx, ny, word, l+1)) return true;
                board[nx][ny] = word[l];
            }
        }
        
        
        return false;
    }
};